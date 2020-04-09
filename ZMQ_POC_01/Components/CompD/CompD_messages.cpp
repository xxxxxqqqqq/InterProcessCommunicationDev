#include "CompD_messages.h"
#include "../../build/Components/CompD/CompD.pb.h"

CompD_Messages::CompD_Messages(){

};

std::vector<std::string> CompD_Messages::InitInputMsgs()
{
    // ******************************************************************************************** //
    CompD::CMessage cstruct;
    CompD::GMessage g;
    CompD::KMessage k;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "c"
    // 2. Set default values for "g"
    // 3. Set default values for "k"
    CompD::CMessage_Cstruct* c;
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

    g.set_g(17);

    k.set_k(21);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "c"
    // 2. Serialize protobuf messages of "g"
    // 3. Serialize protobuf messages of "k"
    // 4. Return all serialized messages
    std::string c_serial;
    std::string g_serial;
    std::string k_serial;

    std::cout << std::endl << "*** Input Initialization STEP 0 ***" << std::endl << std::endl;
    cstruct.SerializeToString(&c_serial);
    for (int i = 0; i < cstruct.c_size(); i++)
    {
        const CompD::CMessage_Cstruct& cread = cstruct.c(i);
        std::cout << "Initialized -> C.c_01[" << i <<"] = " << cread.c_01() << std::endl;
        std::cout << "Initialized -> C.c_02[" << i <<"] = " << cread.c_02() << std::endl;
        std::cout << "Initialized -> C.c_03[" << i <<"] = " << cread.c_03() << std::endl;

    }

    g.SerializeToString(&g_serial);
    g.ParseFromString(g_serial);
    std::cout << "Initialized -> G.g = " << g.g() << std::endl;

    k.SerializeToString(&k_serial);
    k.ParseFromString(k_serial);
    std::cout << "Initialized -> K.k = " << k.k() << std::endl;

    serial_msgs.push_back(c_serial);
    serial_msgs.push_back(g_serial);
    serial_msgs.push_back(k_serial);
    return serial_msgs;
    // ******************************************************************************************** //
};

std::vector<std::string> CompD_Messages::InitOutputMsgs()
{
    // ******************************************************************************************** //
    CompD::HMessage h;
    CompD::LMessage l;
    CompD::MMessage m;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "h"
    // 2. Set default values for "l"
    // 3. Set default values for "m"
    h.add_h(13);
    h.add_h(14);
    h.add_h(15);
    h.add_h(16);
    h.add_h(17);

    l.set_l(84);

    m.set_m(93);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "h"
    // 2. Serialize protobuf messages of "l"
    // 3. Serialize protobuf messages of "m"
    // 4. Return all serialized messages
    std::string h_serial;
    std::string l_serial;
    std::string m_serial;

    std::cout << std::endl << "*** Output Initialization STEP 0 ***" << std::endl << std::endl;
    h.SerializeToString(&h_serial);
    h.ParseFromString(h_serial);
    std::cout << "Initialized -> H.h[0] = " << h.h(0) << std::endl;
    std::cout << "Initialized -> H.h[1] = " << h.h(1) << std::endl;
    std::cout << "Initialized -> H.h[2] = " << h.h(2) << std::endl;
    std::cout << "Initialized -> H.h[3] = " << h.h(3) << std::endl;
    std::cout << "Initialized -> H.h[4] = " << h.h(4) << std::endl;

    l.SerializeToString(&l_serial);
    l.ParseFromString(l_serial);
    std::cout << "Initialized -> L.l = " << l.l() << std::endl;

    l.SerializeToString(&l_serial);
    l.ParseFromString(l_serial);
    std::cout << "Initialized -> F.f = " << l.l() << std::endl;

    serial_msgs.push_back(h_serial);
    serial_msgs.push_back(l_serial);
    serial_msgs.push_back(m_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}

void CompD_Messages::SetInputMsgs(std::map<int, std::string> serialized_received_messages)
{
    // ******************************************************************************************** //
    CompD::CMessage receivedC;
    CompD::GMessage receivedG;
    CompD::KMessage receivedK;
    
    if (serialized_received_messages.find(0) != serialized_received_messages.end())
    {
        receivedC.ParseFromArray(serialized_received_messages[0].data(), serialized_received_messages[0].size());
        std::cout << "Received -> " << receivedC.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(1) != serialized_received_messages.end())
    {
        receivedG.ParseFromArray(serialized_received_messages[1].data(), serialized_received_messages[1].size());
        std::cout << "Received -> " << receivedG.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(2) != serialized_received_messages.end())
    {
        receivedK.ParseFromArray(serialized_received_messages[2].data(), serialized_received_messages[2].size());
        std::cout << "Received -> " << receivedK.DebugString() << std::endl;
    }
    // ******************************************************************************************** //
};

std::vector<std::string> CompD_Messages::SetOutputMsgs(int increment)
{
    // ******************************************************************************************** //
    CompD::HMessage h;
    CompD::LMessage l;
    CompD::MMessage m;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "h"
    // 2. Set default values for "l"
    // 3. Set default values for "m"
    h.add_h(13+increment);
    h.add_h(14+increment);
    h.add_h(15+increment);
    h.add_h(16+increment);
    h.add_h(17+increment);

    l.set_l(84+increment);

    m.set_m(93+increment);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "h"
    // 2. Serialize protobuf messages of "l"
    // 3. Serialize protobuf messages of "m"
    // 4. Return all serialized messages
    std::string h_serial;
    std::string l_serial;
    std::string m_serial;

    std::cout << std::endl << "*** STEP " << increment << " ***" << std::endl;
    h.SerializeToString(&h_serial);
    h.ParseFromString(h_serial);
    std::cout << "H.h[0] = " << h.h(0) << std::endl;
    std::cout << "H.h[1] = " << h.h(1) << std::endl;
    std::cout << "H.h[2] = " << h.h(2) << std::endl;
    std::cout << "H.h[3] = " << h.h(3) << std::endl;
    std::cout << "H.h[4] = " << h.h(4) << std::endl;

    l.SerializeToString(&l_serial);
    l.ParseFromString(l_serial);
    std::cout << "L.l = " << l.l() << std::endl;

    m.SerializeToString(&m_serial);
    m.ParseFromString(m_serial);
    std::cout << "M.m = " << l.l() << std::endl;

    serial_msgs.push_back(h_serial);
    serial_msgs.push_back(l_serial);
    serial_msgs.push_back(m_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}