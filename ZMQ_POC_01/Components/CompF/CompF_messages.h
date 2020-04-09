#ifndef DEFINED_TYPEDEF_FOR_COMPF_MESSAGES_
#define DEFINED_TYPEDEF_FOR_COMPF_MESSAGES

#include <unistd.h>
#include <vector>
#include <string>
#include <map>

class CompF_Messages
{
public:
    CompF_Messages();

    std::vector<std::string> InitInputMsgs();
    std::vector<std::string> InitOutputMsgs();
    
    void SetInputMsgs(std::map<int, std::string> serialized_received_messages);
    std::vector<std::string> SetOutputMsgs(int increment);
};

#endif