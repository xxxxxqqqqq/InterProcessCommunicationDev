#include "CompA_messages.h"
#include "../../build/Components/CompA/CompA.pb.h"

CompA_Messages::CompA_Messages(){

};

std::vector<std::string> CompA_Messages::InitInputMsgs()
{
    std::vector<std::string> serial_msgs;
    return serial_msgs;
};

std::vector<std::string> CompA_Messages::InitOutputMsgs()
{
    // ******************************************************************************************** //
    CompA::AMessage astruct;
    CompA::BMessage b;
    CompA::CMessage cstruct;
    CompA::DMessage d;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "a"
    // 2. Set default values for "b"
    // 3. Set default values for "c"
    // 4. Set default values for "d"
    CompA::AMessage_Astruct* a;
    a = astruct.add_a();
    a->set_a_01(10);
    a->set_a_02(100);

    b.set_b(5);

    CompA::CMessage_Cstruct* c;
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

    d.set_d(500);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize and parse protobuf messages of "a"
    // 2. Serialize and parse protobuf messages of "b"
    // 3. Serialize and parse protobuf messages of "c"
    // 4. Serialize and parse protobuf messages of "d"
    // 5. Return all serialized messages
    std::string a_serial;
    std::string b_serial;
    std::string c_serial;
    std::string d_serial;

    std::cout << std::endl << "*** Output Initialization STEP 0 ***" << std::endl << std::endl;
    astruct.SerializeToString(&a_serial);
    for (int i = 0; i < astruct.a_size(); i++)
    {
        const CompA::AMessage_Astruct& aread = astruct.a(i);
        std::cout << "Initialized -> A.a_01 = " << aread.a_01() << std::endl;
        std::cout << "Initialized -> A.a_02 = " << aread.a_02() << std::endl;
    }

    b.SerializeToString(&b_serial);
    b.ParseFromString(b_serial);
    std::cout << "Initialized -> B.b = " << b.b() << std::endl;

    cstruct.SerializeToString(&c_serial);
    for (int i = 0; i < cstruct.c_size(); i++)
    {
        const CompA::CMessage_Cstruct& cread = cstruct.c(i);
        std::cout << "Initialized -> C.c_01[" << i <<"] = " << cread.c_01() << std::endl;
        std::cout << "Initialized -> C.c_02[" << i <<"] = " << cread.c_02() << std::endl;
        std::cout << "Initialized -> C.c_03[" << i <<"] = " << cread.c_03() << std::endl;

    }

    d.SerializeToString(&d_serial);
    d.ParseFromString(d_serial);
    std::cout << "Initialized -> D.d = " << d.d() << std::endl;

    serial_msgs.push_back(a_serial);
    serial_msgs.push_back(b_serial);
    serial_msgs.push_back(c_serial);
    serial_msgs.push_back(d_serial);
    return serial_msgs;
    // ******************************************************************************************** //
};

void CompA_Messages::SetInputMsgs(std::map<int, std::string> serialized_received_messages)
{
    // ******************************************************************************************** //
    // ******************************************************************************************** //
};

std::vector<std::string> CompA_Messages::SetOutputMsgs(int increment)
{
    // ******************************************************************************************** //
    CompA::AMessage astruct;
    CompA::BMessage b;
    CompA::CMessage cstruct;
    CompA::DMessage d;
    std::vector<std::string> serial_msgs;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Set default values for "a"
    // 2. Set default values for "b"
    // 3. Set default values for "c"
    // 4. Set default values for "d"
    CompA::AMessage_Astruct* a;
    a = astruct.add_a();
    a->set_a_01(10+increment);
    a->set_a_02(100+increment);

    b.set_b(5+increment);

    CompA::CMessage_Cstruct* c;
    c = cstruct.add_c();
    c->set_c_01(6+increment);
    c->set_c_02(7+increment);
    c->set_c_03(8+increment);
    c = cstruct.add_c();
    c->set_c_01(66+increment);
    c->set_c_02(77+increment);
    c->set_c_03(88+increment);
    c = cstruct.add_c();
    c->set_c_01(666+increment);
    c->set_c_02(777+increment);
    c->set_c_03(888+increment);

    d.set_d(500+increment);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Serialize and parse protobuf messages of "a"
    // 2. Serialize and parse protobuf messages of "b"
    // 3. Serialize and parse protobuf messages of "c"
    // 4. Serialize and parse protobuf messages of "d"
    // 5. Return all serialized messages
    std::string a_serial;
    std::string b_serial;
    std::string c_serial;
    std::string d_serial;

    std::cout << std::endl << "*** STEP " << increment << " ***" << std::endl;
    astruct.SerializeToString(&a_serial);
    for (int i = 0; i < astruct.a_size(); i++)
    {
        const CompA::AMessage_Astruct& aread = astruct.a(i);
        std::cout << "A.a_01 = " << aread.a_01() << std::endl;
        std::cout << "A.a_02 = " << aread.a_02() << std::endl;
    }

    b.SerializeToString(&b_serial);
    b.ParseFromString(b_serial);
    std::cout << "B.b = " << b.b() << std::endl;

    cstruct.SerializeToString(&c_serial);
    for (int i = 0; i < cstruct.c_size(); i++)
    {
        const CompA::CMessage_Cstruct& cread = cstruct.c(i);
        std::cout << "C.c_01[" << i <<"] = " << cread.c_01() << std::endl;
        std::cout << "C.c_02[" << i <<"] = " << cread.c_02() << std::endl;
        std::cout << "C.c_03[" << i <<"] = " << cread.c_03() << std::endl;

    }

    d.SerializeToString(&d_serial);
    d.ParseFromString(d_serial);
    std::cout << "D.d = " << d.d() << std::endl;

    serial_msgs.push_back(a_serial);
    serial_msgs.push_back(b_serial);
    serial_msgs.push_back(c_serial);
    serial_msgs.push_back(d_serial);
    return serial_msgs;
    // ******************************************************************************************** //
};