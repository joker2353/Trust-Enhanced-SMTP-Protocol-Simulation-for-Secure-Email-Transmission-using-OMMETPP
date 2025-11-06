#include <omnetpp.h>
#include "TrustSMTP_m.h"
#include "utils.h"
#include <string>
#include <sstream>

using namespace omnetpp;
using namespace peyal;

class SMTPClient : public cSimpleModule {
private:
    cMessage *sendTimer = nullptr;
    cMessage *smtpTimer = nullptr;
    double sendInterval;
    double trustScore;
    std::string address;
    int msgCounter = 0;
    

    enum SMTPState {
        DISCONNECTED,
        CONNECTED,
        EHLO_SENT,
        MAIL_FROM_SENT,
        RCPT_TO_SENT,
        DATA_SENT,
        SENDING_DATA,
        QUIT_SENT
    };
    
    SMTPState currentState = DISCONNECTED;
    std::string recipient;
    std::string currentMessage;
    int smtpStep = 0;
    
  
    std::vector<std::string> smtpSteps = {
        "HELLO", "EMAIL", "QUIT"
    };

protected:
    virtual void initialize() override {
        sendInterval = par("sendInterval").doubleValue();
        trustScore = par("initialTrustScore").doubleValue();
        address = par("address").stdstringValue();
        
        sendTimer = new cMessage("sendTimer");
        smtpTimer = new cMessage("smtpTimer");
        
        scheduleAt(simTime() + uniform(0, sendInterval), sendTimer);
    }

    virtual void handleMessage(cMessage *msg) override {
        if (msg == sendTimer) {
            startSMTPSession();
            scheduleAt(simTime() + sendInterval, sendTimer);
        }
        else if (msg == smtpTimer) {
            processSMTPStep();
        }
        else if (auto *response = dynamic_cast<SMTPResponse*>(msg)) {
            handleSMTPResponse(response);
        }
        else {
            delete msg;
        }
    }
    
    void startSMTPSession() {
        currentState = DISCONNECTED;
        smtpStep = 0;
        recipient = (address == "hostA") ? "hostB" : "hostA";
        
        EV << "Client " << address << " starting SMTP session to " << recipient << "\n";
        
       
        scheduleAt(simTime() + 0.1, smtpTimer);
    }
    
    void processSMTPStep() {
        if (smtpStep >= smtpSteps.size()) {
            currentState = DISCONNECTED;
            return;
        }
        
        std::string step = smtpSteps[smtpStep];
        EV << "Client " << address << " executing step: " << step << "\n";
        
        if (step == "HELLO") {
            sendSimpleMessage("HELLO", "Hello from " + address);
            currentState = EHLO_SENT;
        }
        else if (step == "EMAIL") {
            sendEmailMessage();
            currentState = SENDING_DATA;
        }
        else if (step == "QUIT") {
            sendSimpleMessage("QUIT", "Goodbye");
            currentState = QUIT_SENT;
        }
        
        smtpStep++;
        scheduleAt(simTime() + 0.5, smtpTimer);
    }
    
    void sendSimpleMessage(const std::string& message, const std::string& details) {
        auto *cmd = new SMTPCommand();
        cmd->setCommand(message.c_str());
        cmd->setParameter(details.c_str());
        cmd->setClientId(address.c_str());
        cmd->setTrustScore(trustScore);
        cmd->setName(message.c_str());
        
        EV << "Client " << address << " sending: " << message << "\n";
        send(cmd, "out");
    }
    
    void sendEmailMessage() {
       
        auto *data = new SMTPData();
        data->setFrom((address + "@example.com").c_str());
        data->setTo((recipient + "@example.com").c_str());
        data->setSubject(("Email " + std::to_string(msgCounter)).c_str());
        data->setBody(("Hello from " + address + "!").c_str());
        data->setSizeBytes(100);
        data->setTrustScore(trustScore);
        data->setMsgId(msgCounter++);
        
       
        std::string emailName = "EMAIL (Trust: " + std::to_string(trustScore) + ")";
        data->setName(emailName.c_str());
        
        EV << "Client " << address << " sending email (trust=" << trustScore << ")\n";
        send(data, "out");
    }
    
    void handleSMTPResponse(SMTPResponse *response) {
        EV << "Client " << address << " received response: " << response->getCode() << " " << response->getStatusText() << "\n";
        
        if (response->getCode() == 221) {
           
            currentState = DISCONNECTED;
        }
        
        delete response;
    }

    virtual void finish() override {
        cancelAndDelete(sendTimer);
        cancelAndDelete(smtpTimer);
    }
};

Define_Module(SMTPClient);
