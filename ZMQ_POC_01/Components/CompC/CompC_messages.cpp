#include "CompC_messages.h"
#include "../../build/Components/CompC/CompC.pb.h"

CompC_Messages::CompC_Messages(){

};

std::vector<std::string> CompC_Messages::InitInputMsgs()
{
    // ******************************************************************************************** //
    CompC::CMessage cstruct;
    CompC::EMessage e;
    CompC::JMessage j;
    CompC::LMessage l;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "c"
    // 2. Set default values for "e"
    // 3. Set default values for "j"
    // 4. Set default values for "l"
    CompC::CMessage_Cstruct* c;
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

    e.set_e(0);

    j.set_j(6);

    l.set_l(9);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "c"
    // 2. Serialize protobuf messages of "e"
    // 3. Serialize protobuf messages of "j"
    // 4. Serialize protobuf messages of "l"
    // 5. Return all serialized messages
    std::string c_serial;
    std::string e_serial;
    std::string j_serial;
    std::string l_serial;

    std::cout << std::endl << "*** Input Initialization STEP 0 ***" << std::endl << std::endl;
    cstruct.SerializeToString(&c_serial);
    for (int i = 0; i < cstruct.c_size(); i++)
    {
        const CompC::CMessage_Cstruct& cread = cstruct.c(i);
        std::cout << "Initialized -> C.c_01[" << i <<"] = " << cread.c_01() << std::endl;
        std::cout << "Initialized -> C.c_02[" << i <<"] = " << cread.c_02() << std::endl;
        std::cout << "Initialized -> C.c_03[" << i <<"] = " << cread.c_03() << std::endl;
    }

    e.SerializeToString(&e_serial);
    e.ParseFromString(e_serial);
    std::cout << "Initialized -> E.e = " << e.e() << std::endl;

    j.SerializeToString(&j_serial);
    j.ParseFromString(j_serial);
    std::cout << "Initialized -> J.j = " << j.j() << std::endl;

    l.SerializeToString(&l_serial);
    l.ParseFromString(l_serial);
    std::cout << "Initialized -> L.l = " << l.l() << std::endl;

    serial_msgs.push_back(c_serial);
    serial_msgs.push_back(e_serial);
    serial_msgs.push_back(j_serial);
    serial_msgs.push_back(l_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}

std::vector<std::string> CompC_Messages::InitOutputMsgs()
{
    // ******************************************************************************************** //
    CompC::FMessage f;
    CompC::JMessage j;
    CompC::KMessage k;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "f"
    // 2. Set default values for "j"
    // 3. Set default values for "k"
    f.set_f(1);

    j.set_j(19);

    k.set_k(23);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "f"
    // 2. Serialize protobuf messages of "j"
    // 3. Serialize protobuf messages of "k"
    // 4. Return all serialized messages
    std::string f_serial;
    std::string j_serial;
    std::string k_serial;

    std::cout << std::endl << "*** Output Initialization STEP 0 ***" << std::endl << std::endl;
    f.SerializeToString(&f_serial);
    f.ParseFromString(f_serial);
    std::cout << "Initialized -> F.f = " << f.f() << std::endl;

    j.SerializeToString(&j_serial);
    j.ParseFromString(j_serial);
    std::cout << "Initialized -> J.j = " << j.j() << std::endl;

    k.SerializeToString(&k_serial);
    k.ParseFromString(k_serial);
    std::cout << "Initialized -> K.k = " << k.k() << std::endl;

    serial_msgs.push_back(f_serial);
    serial_msgs.push_back(j_serial);
    serial_msgs.push_back(k_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}

void CompC_Messages::SetInputMsgs(std::map<int, std::string> serialized_received_messages)
{
    // ******************************************************************************************** //
    CompC::CMessage receivedC;
    CompC::EMessage receivedE;
    CompC::JMessage receivedJ;
    CompC::LMessage receivedL;
    
    if (serialized_received_messages.find(0) != serialized_received_messages.end())
    {
        receivedC.ParseFromArray(serialized_received_messages[0].data(), serialized_received_messages[0].size());
        std::cout << "Received -> " << receivedC.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(1) != serialized_received_messages.end())
    {
        receivedE.ParseFromArray(serialized_received_messages[1].data(), serialized_received_messages[1].size());
        std::cout << "Received -> " << receivedE.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(2) != serialized_received_messages.end())
    {
        receivedJ.ParseFromArray(serialized_received_messages[2].data(), serialized_received_messages[2].size());
        std::cout << "Received -> " << receivedJ.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(3) != serialized_received_messages.end())
    {
        receivedL.ParseFromArray(serialized_received_messages[3].data(), serialized_received_messages[3].size());
        std::cout << "Received -> " << receivedL.DebugString() << std::endl;
    }
    // ******************************************************************************************** //
}

std::vector<std::string> CompC_Messages::SetOutputMsgs(int increment)
{
   // ******************************************************************************************** //
    CompC::FMessage f;
    CompC::JMessage j;
    CompC::KMessage k;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "f"
    // 2. Set default values for "j"
    // 3. Set default values for "k"
    f.set_f(1+increment);

    j.set_j(19+increment);

    k.set_k(23+increment);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "f"
    // 2. Serialize protobuf messages of "j"
    // 3. Serialize protobuf messages of "k"
    // 4. Return all serialized messages
    std::string f_serial;
    std::string j_serial;
    std::string k_serial;

    std::cout << std::endl << "*** STEP " << increment << " ***" << std::endl;
    f.SerializeToString(&f_serial);
    f.ParseFromString(f_serial);
    std::cout << "F.f = " << f.f() << std::endl;

    j.SerializeToString(&j_serial);
    j.ParseFromString(j_serial);
    std::cout << "J.j = " << j.j() << std::endl;

    k.SerializeToString(&k_serial);
    k.ParseFromString(k_serial);
    std::cout << "K.k = " << k.k() << std::endl;

    serial_msgs.push_back(f_serial);
    serial_msgs.push_back(j_serial);
    serial_msgs.push_back(k_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}