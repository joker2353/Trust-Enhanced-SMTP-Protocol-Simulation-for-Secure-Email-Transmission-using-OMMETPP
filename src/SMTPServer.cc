/*
 * SMTPServer.cc
 *
 *  Created on: Sep 25, 2025
 *      Author: User
 */
#include <omnetpp.h>
#include <string>
#include <map>
#include "TrustSMTP_m.h"

using namespace omnetpp;
using namespace peyal;

class SMTPServer : public cSimpleModule {
  private:
    std::string address;
    long numReceived = 0;
    long bytesReceived = 0;
    long numCommands = 0;
    long numEmails = 0;
    cOutVector arrivalTimes;
    cOutVector commandTimes;
    

    enum SMTPState {
        DISCONNECTED,
        CONNECTED,
        EHLO_RECEIVED,
        MAIL_FROM_RECEIVED,
        RCPT_TO_RECEIVED,
        DATA_RECEIVED,
        RECEIVING_DATA
    };
    
    SMTPState currentState = DISCONNECTED;
    std::string currentSender;
    std::string currentRecipient;
    std::string currentEmail;

  protected:
    virtual void initialize() override {
        address = par("address").stdstringValue();
        numReceived = 0;
        bytesReceived = 0;
        numCommands = 0;
        numEmails = 0;
        arrivalTimes.setName(("srv_" + address + "_arrivalTimes").c_str());
        commandTimes.setName(("srv_" + address + "_commandTimes").c_str());
    }

    virtual void handleMessage(cMessage *msg) override {
        if (auto *cmd = dynamic_cast<SMTPCommand*>(msg)) {
            handleSMTPCommand(cmd);
        }
        else if (auto *data = dynamic_cast<SMTPData*>(msg)) {
            handleSMTPData(data);
        }
        else if (auto *m = dynamic_cast<TrustSMTPMessage*>(msg)) {

            if (strcmp(m->getTo(), address.c_str()) != 0) {
                EV << "Server " << address << " got msg for '" << m->getTo() << "', dropping\n";
                delete m;
                return;
            }
            EV << "Server " << address << " received msg " << m->getMsgId() << " from " << m->getFrom() << " size=" << m->getSizeBytes() << " trust=" << m->getTrustScore() << "\n";
            numReceived++;
            bytesReceived += m->getSizeBytes();
            arrivalTimes.record(simTime());
            delete m;
        } else {
            delete msg;
        }
    }
    
    void handleSMTPCommand(SMTPCommand *cmd) {
        numCommands++;
        commandTimes.record(simTime());
        
        std::string command = cmd->getCommand();
        std::string parameter = cmd->getParameter();
        std::string clientId = cmd->getClientId();
        
        EV << "Server " << address << " received: " << command << " from " << clientId << "\n";
        

        int arrivalGate = cmd->getArrivalGate()->getIndex();
        int responseGate = 1 - arrivalGate;
        
        SMTPResponse *response = new SMTPResponse();
        
        if (command == "HELLO") {
            response->setCode(250);
            response->setStatusText((std::string("Hello ") + parameter).c_str());
            response->setSuccess(true);
            response->setName("250 OK");
            currentState = EHLO_RECEIVED;
        }
        else if (command == "QUIT") {
            response->setCode(221);
            response->setStatusText("Goodbye");
            response->setSuccess(true);
            response->setName("221 BYE");
            currentState = DISCONNECTED;
        }
        else {
            response->setCode(500);
            response->setStatusText("Unknown command");
            response->setSuccess(false);
            response->setName("500 ERROR");
        }
        
        EV << "Server " << address << " sending: " << response->getName() << " via out[" << responseGate << "]\n";
        send(response, "out", responseGate);
        
        delete cmd;
    }
    
    void handleSMTPData(SMTPData *data) {
        numEmails++;
        numReceived++;
        bytesReceived += data->getSizeBytes();
        arrivalTimes.record(simTime());
        

        int arrivalGate = data->getArrivalGate()->getIndex();
        int responseGate = 1 - arrivalGate;
        
        EV << "Server " << address << " received email from " << data->getFrom() 
           << " trust=" << data->getTrustScore() << " via in[" << arrivalGate << "]\n";

        SMTPResponse *response = new SMTPResponse();
        response->setCode(250);
        response->setStatusText("Email received");
        response->setSuccess(true);
        response->setName("250 OK");
        
        EV << "Server " << address << " sending: " << response->getName() << " via out[" << responseGate << "]\n";
        send(response, "out", responseGate);

        SMTPData *relay = data->dup();
        EV << "Server " << address << " relaying email to TM via out[" << arrivalGate << "]\n";
        send(relay, "out", arrivalGate);

        delete data;
    }

    virtual void finish() override {
        recordScalar(("srv_" + address + ".numReceived").c_str(), numReceived);
        recordScalar(("srv_" + address + ".bytesReceived").c_str(), bytesReceived);
        recordScalar(("srv_" + address + ".numCommands").c_str(), numCommands);
        recordScalar(("srv_" + address + ".numEmails").c_str(), numEmails);
    }
};

Define_Module(SMTPServer);




