#include "CompE_messages.h"
#include "../../build/Components/CompE/CompE.pb.h"

CompE_Messages::CompE_Messages(){

};

std::vector<std::string> CompE_Messages::InitInputMsgs()
{
    // ******************************************************************************************** //
    CompE::CMessage cstruct;
    CompE::IMessage_Istruct istruct;
    CompE::MMessage m;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "c"
    // 2. Set default values for "i"
    // 3. Set default values for "m"
    CompE::CMessage_Cstruct* c;
    c = cstruct.add_c();
    c->set_c_01(6);
    c->set_c_02(7);
    c->set_c_03(8);
    c = cstruct.add_c();
    c->set_c_01(66);
    c->set_c_02(77);
    c->set_c_03(88);
    c = cstruct.add_c();
    c->set_c_01(666);
    c->set_c_02(777);
    c->set_c_03(888);

    CompE::IMessage_Istruct_Istructstruct* i;
    i = istruct.add_i();
    i->set_i_01_01(6);
    i->set_i_01_02(66);

    m.set_m(56);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "c"
    // 2. Serialize protobuf messages of "i"
    // 3. Serialize protobuf messages of "m"
    // 4. Return all serialized messages
    std::string c_serial;
    std::string i_serial;
    std::string m_serial;

    std::cout << std::endl << "*** Input Initialization STEP 0 ***" << std::endl << std::endl;
    cstruct.SerializeToString(&c_serial);
    for (int i = 0; i < cstruct.c_size(); i++)
    {
        const CompE::CMessage_Cstruct& cread = cstruct.c(i);
        std::cout << "Initialized -> C.c_01[" << i <<"] = " << cread.c_01() << std::endl;
        std::cout << "Initialized -> C.c_02[" << i <<"] = " << cread.c_02() << std::endl;
        std::cout << "Initialized -> C.c_03[" << i <<"] = " << cread.c_03() << std::endl;
    }

    istruct.SerializeToString(&i_serial);
    for (int q = 0; q < istruct.i_size(); q++)
    {
        const CompE::IMessage_Istruct_Istructstruct& iread = istruct.i(q);
        std::cout << "Initialized -> I.i_01_01 = " << iread.i_01_01() << std::endl;
        std::cout << "Initialized -> A.i_01_02 = " << iread.i_01_02() << std::endl;
    }

    m.SerializeToString(&m_serial);
    m.ParseFromString(m_serial);
    std::cout << "Initialized -> M.m = " << m.m() << std::endl;

    serial_msgs.push_back(c_serial);
    serial_msgs.push_back(i_serial);
    serial_msgs.push_back(m_serial);
    return serial_msgs;
    // ******************************************************************************************** //
};

std::vector<std::string> CompE_Messages::InitOutputMsgs()
{
    // ******************************************************************************************** //
    std::vector<std::string> serial_msgs;
    return serial_msgs;
    // ******************************************************************************************** //
};

void CompE_Messages::SetInputMsgs(std::map<int, std::string> serialized_received_messages)
{
    // ******************************************************************************************** //
    CompE::CMessage receivedC;
    CompE::IMessage_Istruct receivedI;
    CompE::MMessage receivedM;
    
    if (serialized_received_messages.find(0) != serialized_received_messages.end())
    {
        receivedC.ParseFromArray(serialized_received_messages[0].data(), serialized_received_messages[0].size());
        std::cout << "Received -> " << receivedC.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(1) != serialized_received_messages.end())
    {
        receivedI.ParseFromArray(serialized_received_messages[1].data(), serialized_received_messages[1].size());
        std::cout << "Received -> " << receivedI.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(2) != serialized_received_messages.end())
    {
        receivedM.ParseFromArray(serialized_received_messages[2].data(), serialized_received_messages[2].size());
        std::cout << "Received -> " << receivedM.DebugString() << std::endl;
    }
    // ******************************************************************************************** //
};

std::vector<std::string> CompE_Messages::SetOutputMsgs(int increment)
{
    // ******************************************************************************************** //
    std::vector<std::string> serial_msgs;
    return serial_msgs;
    // ******************************************************************************************** //
};