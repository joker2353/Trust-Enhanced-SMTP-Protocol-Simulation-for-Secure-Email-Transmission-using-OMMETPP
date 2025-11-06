#include <omnetpp.h>
#include <map>
#include <string>
#include "TrustSMTP_m.h"

using namespace omnetpp;
using namespace peyal;

class TrustManager : public cSimpleModule {
  private:
    double dropThreshold = 0.3;
    std::map<std::string,int> addressToOutIndex;

    long numReceived = 0;
    long numDropped = 0;
    long numForwarded = 0;
    long numCommands = 0;
    long numEmails = 0;

    simsignal_t sigReceived;
    simsignal_t sigDropped;
    simsignal_t sigForwarded;
    simsignal_t sigCommands;
    simsignal_t sigEmails;

  protected:
    virtual void initialize() override {
        dropThreshold = par("dropThreshold").doubleValue();

    
        sigReceived = registerSignal("tmReceived");
        sigDropped = registerSignal("tmDropped");
        sigForwarded = registerSignal("tmForwarded");
        sigCommands = registerSignal("tmCommands");
        sigEmails = registerSignal("tmEmails");

        addressToOutIndex["hostA"] = 0;
        addressToOutIndex["hostB"] = 1;

        numReceived = numDropped = numForwarded = numCommands = numEmails = 0;
    }

    virtual void handleMessage(cMessage *msg) override {
        numReceived++;
        emit(sigReceived, (long)1);

        if (auto *cmd = dynamic_cast<SMTPCommand*>(msg)) {
            handleSMTPCommand(cmd);
        }

        else if (auto *data = dynamic_cast<SMTPData*>(msg)) {
            handleSMTPData(data);
        }

        else if (auto *response = dynamic_cast<SMTPResponse*>(msg)) {
            handleSMTPResponse(response);
        }

        else if (auto *m = dynamic_cast<TrustSMTPMessage*>(msg)) {
            handleLegacyMessage(m);
        } else {
            delete msg;
        }
    }
    
    void handleSMTPCommand(SMTPCommand *cmd) {
        numCommands++;
        emit(sigCommands, (long)1);
        
        std::string command = cmd->getCommand();
        
        EV << "TrustManager received: " << command << " from " << cmd->getClientId() << "\n";
        
        forwardToServer(cmd);
    }
    
    void handleSMTPData(SMTPData *data) {
        numEmails++;
        emit(sigEmails, (long)1);
        
        const double trust = data->getTrustScore();
        
        EV << "TrustManager received email from " << data->getFrom() 
           << " trust=" << trust << "\n";
        
       
        if (trust < dropThreshold) {
            EV << "TrustManager: DROPPING email (trust=" << trust << " < " << dropThreshold << ")\n";
            numDropped++;
            emit(sigDropped, (long)1);
            delete data;
            return;
        }
        
        EV << "TrustManager: FORWARDING email (trust=" << trust << " >= " << dropThreshold << ")\n";
        forwardToServer(data);
    }
    
    void handleSMTPResponse(SMTPResponse *response) {
        int arrivalGate = response->getArrivalGate()->getIndex();
        int outGate = arrivalGate; 

        EV << "TrustManager forwarding response via out[" << outGate << "]: "
           << response->getCode() << " " << response->getStatusText() << "\n";

        send(response, "out", outGate);
    }
    
    void handleLegacyMessage(TrustSMTPMessage *m) {
        const double trust = m->getTrustScore();
        if (trust < dropThreshold) {
            EV << "TrustManager dropping msg " << m->getMsgId() << " from " << m->getFrom() << " trust=" << trust << "\n";
            numDropped++;
            emit(sigDropped, (long)1);
            delete m;
            return;
        }

        const char *dest = m->getTo();
        auto it = addressToOutIndex.find(dest);
        if (it == addressToOutIndex.end()) {
            EV << "TrustManager: unknown destination '" << dest << "', dropping\n";
            numDropped++;
            emit(sigDropped, (long)1);
            delete m;
            return;
        }

        int gateIndex = it->second;
        EV << "TrustManager forwarding msg " << m->getMsgId() << " to " << dest << " via out[" << gateIndex << "]\n";
        send(m, "out", gateIndex);
        numForwarded++;
        emit(sigForwarded, (long)1);
    }
    
    void forwardToServer(cMessage *msg) {
        
        int arrivalGate = msg->getArrivalGate()->getIndex();
        
    
        int outGate = arrivalGate; 
        

        if (auto *data = dynamic_cast<SMTPData*>(msg)) {
            data->setName("EMAIL");
        } else if (auto *cmd = dynamic_cast<SMTPCommand*>(msg)) {
            cmd->setName(cmd->getCommand());
        }
        
        EV << "TrustManager relaying from in[" << arrivalGate << "] to out[" << outGate << "]\n";
        send(msg, "out", outGate);
        numForwarded++;
        emit(sigForwarded, (long)1);
    }

    virtual void finish() override {
        recordScalar("tm.numReceived", numReceived);
        recordScalar("tm.numDropped", numDropped);
        recordScalar("tm.numForwarded", numForwarded);
        recordScalar("tm.numCommands", numCommands);
        recordScalar("tm.numEmails", numEmails);
    }
};

Define_Module(TrustManager);




