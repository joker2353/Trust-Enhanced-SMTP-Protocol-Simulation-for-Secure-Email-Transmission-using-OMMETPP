cplusplus {{
#include <string>
}}

namespace peyal;


message TrustSMTPMessage
{
    string from;
    string to;
    int msgId;
    int sizeBytes;
    double trustScore;  
    bool isHandshake = false;
    bool isData = false;
}


message SMTPCommand
{
    string command;      
    string parameter;    
    string clientId;    
    double trustScore;   
}

message SMTPResponse
{
    int code;          
    string statusText;  
    bool success;       
}

message SMTPData
{
    string from;
    string to;
    string subject;
    string body;
    int sizeBytes;
    double trustScore;
    int msgId;
}


message TrustQueryMsg
{
    string sender;
}

message TrustReplyMsg
{
    string sender;
    double score;
}