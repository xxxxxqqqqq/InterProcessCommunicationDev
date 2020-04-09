#include "CompB_messages.h"
#include "../../build/Components/CompB/CompB.pb.h"

CompB_Messages::CompB_Messages(){

};

std::vector<std::string> CompB_Messages::InitInputMsgs()
{
    // ******************************************************************************************** //
    CompB::AMessage astruct;
    CompB::FMessage f;
    CompB::HMessage h;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "a"
    // 2. Set default values for "f"
    // 3. Set default values for "h"
    CompB::AMessage_Astruct* a;
    a = astruct.add_a();
    a->set_a_01(10);
    a->set_a_02(100);

    f.set_f(7);

    h.add_h(13);
    h.add_h(14);
    h.add_h(15);
    h.add_h(16);
    h.add_h(17);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "a"
    // 2. Serialize protobuf messages of "f"
    // 3. Serialize protobuf messages of "h"
    // 4. Return all serialized messages
    std::string a_serial;
    std::string f_serial;
    std::string h_serial;

    std::cout << std::endl << "*** Input Initialization STEP 0 ***" << std::endl << std::endl;
    astruct.SerializeToString(&a_serial);
    for (int i = 0; i < astruct.a_size(); i++)
    {
        const CompB::AMessage_Astruct& aread = astruct.a(i);
        std::cout << "Initialized -> A.a_01 = " << aread.a_01() << std::endl;
        std::cout << "Initialized -> A.a_02 = " << aread.a_02() << std::endl;
    }

    f.SerializeToString(&f_serial);
    f.ParseFromString(f_serial);
    std::cout << "Initialized -> F.f = " << f.f() << std::endl;

    h.SerializeToString(&h_serial);
    h.ParseFromString(h_serial);
    std::cout << "Initialized -> H.h[0] = " << h.h(0) << std::endl;
    std::cout << "Initialized -> H.h[1] = " << h.h(1) << std::endl;
    std::cout << "Initialized -> H.h[2] = " << h.h(2) << std::endl;
    std::cout << "Initialized -> H.h[3] = " << h.h(3) << std::endl;
    std::cout << "Initialized -> H.h[4] = " << h.h(4) << std::endl;

    serial_msgs.push_back(a_serial);
    serial_msgs.push_back(f_serial);
    serial_msgs.push_back(h_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}

std::vector<std::string> CompB_Messages::InitOutputMsgs()
{
    // ******************************************************************************************** //
    CompB::EMessage e;
    CompB::GMessage g;
    CompB::IMessage_Istruct istruct;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "e"
    // 2. Set default values for "g"
    // 3. Set default values for "i"
    e.set_e(false);

    g.set_g(9);

    CompB::IMessage_Istruct_Istructstruct* i;
    i = istruct.add_i();
    i->set_i_01_01(6);
    i->set_i_01_02(66);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "e"
    // 2. Serialize protobuf messages of "g"
    // 3. Serialize protobuf messages of "i"
    // 4. Return all serialized messages
    std::string e_serial;
    std::string g_serial;
    std::string i_serial;

    std::cout << std::endl << "*** Output Initialization STEP 0 ***" << std::endl << std::endl;
    e.SerializeToString(&e_serial);
    e.ParseFromString(e_serial);
    std::cout << "Initialized -> E.e = " << e.e() << std::endl;

    g.SerializeToString(&g_serial);
    g.ParseFromString(g_serial);
    std::cout << "Initialized -> G.g = " << g.g() << std::endl;

    istruct.SerializeToString(&i_serial);
    for (int q = 0; q < istruct.i_size(); q++)
    {
        const CompB::IMessage_Istruct_Istructstruct& iread = istruct.i(q);
        std::cout << "Initialized -> I.i_01_01 = " << iread.i_01_01() << std::endl;
        std::cout << "Initialized -> I.i_01_02 = " << iread.i_01_02() << std::endl;
    }

    serial_msgs.push_back(e_serial);
    serial_msgs.push_back(g_serial);
    serial_msgs.push_back(i_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}

void CompB_Messages::SetInputMsgs(std::map<int, std::string> serialized_received_messages)
{
 // ******************************************************************************************** //
    CompB::AMessage receivedA;
    CompB::FMessage receivedF;
    CompB::HMessage receivedH;
    
    if (serialized_received_messages.find(0) != serialized_received_messages.end())
    {
        receivedA.ParseFromArray(serialized_received_messages[0].data(), serialized_received_messages[0].size());
        std::cout << "Received -> " << receivedA.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(1) != serialized_received_messages.end())
    {
        receivedF.ParseFromArray(serialized_received_messages[1].data(), serialized_received_messages[1].size());
        std::cout << "Received -> " << receivedF.DebugString() << std::endl;
    }

    if (serialized_received_messages.find(2) != serialized_received_messages.end())
    {
        receivedH.ParseFromArray(serialized_received_messages[2].data(), serialized_received_messages[2].size());
        std::cout << "Received -> " << receivedH.DebugString() << std::endl;
    }
    // ******************************************************************************************** //
}

std::vector<std::string> CompB_Messages::SetOutputMsgs(int increment)
{
     // ******************************************************************************************** //
    CompB::EMessage e;
    CompB::GMessage g;
    CompB::IMessage_Istruct istruct;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "e"
    // 2. Set default values for "g"
    // 3. Set default values for "i"
    e.set_e(0+increment);

    g.set_g(9+increment);

    CompB::IMessage_Istruct_Istructstruct* i;
    i = istruct.add_i();
    i->set_i_01_01(6+increment);
    i->set_i_01_02(66+increment);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize protobuf messages of "e"
    // 2. Serialize protobuf messages of "g"
    // 3. Serialize protobuf messages of "i"
    // 4. Return all serialized messages
    std::string e_serial;
    std::string g_serial;
    std::string i_serial;

    std::cout << std::endl << "*** STEP " << increment << " ***" << std::endl;
    e.SerializeToString(&e_serial);
    e.ParseFromString(e_serial);
    std::cout << "E.e = " << e.e() << std::endl;

    g.SerializeToString(&g_serial);
    g.ParseFromString(g_serial);
    std::cout << "G.g = " << g.g() << std::endl;

    istruct.SerializeToString(&i_serial);
    for (int q = 0; q < istruct.i_size(); q++)
    {
        const CompB::IMessage_Istruct_Istructstruct& iread = istruct.i(q);
        std::cout << "I.i_01_01 = " << iread.i_01_01() << std::endl;
        std::cout << "I.i_01_02 = " << iread.i_01_02() << std::endl;
    }

    serial_msgs.push_back(e_serial);
    serial_msgs.push_back(g_serial);
    serial_msgs.push_back(i_serial);
    return serial_msgs;
    // ******************************************************************************************** //
}