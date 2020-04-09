#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <functional>
#include "CompD.h"
#include "CompD_interface.h"
#include "CompD_messages.h"
#include "Lib/mylibD.h"
#include "../../build/Components/CompD/CompD.pb.h"

int main(int argc, char *argv[])
{
    // *********************************** INITIALIZATION START *********************************** //
    std::string mycomp = "CompD";
    bool check_port = false;
    bool sim_time = false;
    bool exec_time = false;
    int starting_port, simulation_time, execution_time;
    int my_portgen_port;
    std::string myprocess = argv[0];
    std::string delimiter = "/";
    std::string update_msg;
    size_t delimiter_pos = 0;
    std::string request_msg_portgen;
    std::list<Comp_InputDetails> myInputs;
    std::list<Comp_OutputDetails> myOutputs;
    std::list<void(*)> mySockets;
    std::list<void(*)> myInputSockets;
    std::list<void(*)> myOutputSockets;
    std::list<void(*)>::iterator it_sockets;
    std::vector<std::string> serialized_input_messages, serialized_output_messages;
    std::map<int, std::string> serialized_received_messages;
    // ************************************ INITIALIZATION END ************************************ //

    // ******************************************************************************************** //
    // 1. Parsing the name of the process
    // 2. Parsing the command line argument

    // *1*
    while ((delimiter_pos = myprocess.find(delimiter)) != std::string::npos)
    {
        myprocess.erase(0, delimiter_pos + delimiter.length());
    }
    mycomp = myprocess;

    // *2*
    std::cout << std::endl;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-port") == 0)
        {
            check_port = true;
        };

        if (strcmp(argv[i], "-simtime") == 0)
        {
            sim_time = true;
            check_port = false;
        };

        if (strcmp(argv[i], "-exectime") == 0)
        {
            exec_time = true;
            sim_time = false;
            check_port = false;
        };

        if (check_port && strcmp(argv[i], "-port") != 0)
        {
            starting_port = std::stoi(argv[i]);
            std::cout << "Starting port is: " << starting_port << std::endl;
        }

        if (sim_time && strcmp(argv[i], "-simtime") != 0)
        {
            simulation_time = std::stoi(argv[i]);
            std::cout << "Simulation time is: " << simulation_time << std::endl;
        }

        if (exec_time && strcmp(argv[i], "-exectime") != 0)
        {
            execution_time = std::stoi(argv[i]);
            std::cout << "Execution time is: " << execution_time << std::endl;
        }
    }
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Initializing the interface class
    // 2. Setting up port for communicating with Port Generator
    // 3. Setting up my inputs and outputs

    // *1*
    CompD_Interface CurrCompInterface;

    // *2*
    my_portgen_port = starting_port+3;

    // *3*
    myInputs = CurrCompInterface.Inputs();
    myOutputs = CurrCompInterface.Outputs();
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Initializing a generic component class to utilize GenericComp methods
    // 2. Request for inter-component ports for inputs and get reply
    // 3. Request for inter-component ports for outputs and get reply

    // *1*
    GenericComp CurrComp;

    // *2*
    std::vector<int> inputcollector = CurrComp.GiveInRequestGetInReply(myInputs, my_portgen_port, mycomp);
    myInputs = CurrComp.DistributeInputsToComp(myInputs, inputcollector, mycomp);

    // *3*
    std::vector<int> outputcollector = CurrComp.GiveOutRequestGetOutReply(myOutputs, my_portgen_port, mycomp);
    myOutputs = CurrComp.DistributeOutputsToComp(myOutputs, outputcollector, mycomp);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Creating a "AvailableSockets" instance to collect necessary amount of sockets for current component"
    // 2. Initialize all ZMQ sockets
    // 3. Extract only necessary amount of sockets out of all ZMQ Sockets
    // 4. Distrubute extracted sockets as input-output sockets based on the number of inputs and outputs of current component

    // *1*
    AvailableSockets CurrComp_Sockets;

    // *2*
    CurrComp_Sockets.InitializeSockets();

    // *3*
    mySockets = CurrComp_Sockets.GetSockets(inputcollector.size(), outputcollector.size());

    // *4*
    int count_insocs = inputcollector.size();
    for (it_sockets = mySockets.begin(); it_sockets != mySockets.end(); it_sockets++)
    {
        if (count_insocs != 0)
        {
            myInputSockets.push_back(*it_sockets);
            count_insocs--;
        };
    }

    for (int w = 0; w < inputcollector.size(); w++)
    {
        mySockets.pop_front();
    }
    myOutputSockets = mySockets;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Creating ZMQ context for the current component
    // 2. Setting up ZMQ publishers for the current component
    // 3. Setting up ZMQ subscribers for the current component

    // *1*
    void *ctx = zmq_ctx_new();

    // *2*
    int pub_count = 0;
    for (it_sockets = myOutputSockets.begin(); it_sockets != myOutputSockets.end(); it_sockets++)
    {
        *it_sockets = zmq_socket(ctx, ZMQ_PUB);
        zmq_bind(*it_sockets, ("tcp://127.0.0.1:" + std::to_string(outputcollector[pub_count])).c_str());
        pub_count++;
    }

    // *3*
    int sub_count = 0;
    for (it_sockets = myInputSockets.begin(); it_sockets != myInputSockets.end(); it_sockets++)
    {
        *it_sockets = zmq_socket(ctx, ZMQ_SUB);
        zmq_connect(*it_sockets, ("tcp://127.0.0.1:" + std::to_string(inputcollector[sub_count])).c_str());
        zmq_setsockopt(*it_sockets, ZMQ_SUBSCRIBE, NULL, 0);
        sub_count++;
    }
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Creating a "Comp*X*_Messages" instance to to handle protobuf messages for current component"
    // 2. Initializing input and output protobuf messages for current component

    // *1*
    CompD_Messages CurrCompMessages;
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // *2*
    serialized_input_messages = CurrCompMessages.InitInputMsgs();
    serialized_output_messages = CurrCompMessages.InitOutputMsgs();
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Creating a "myLib*X*" instance to run myLib*X*
    // 2. Run myLib"X" with initialized inputs

    // *1*
    mylibD LibD;

    // *2*
    LibD.InitializeRun(execution_time);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Create the poller structure to collect inputs for this component

    // *1*
    zmq_pollitem_t items[myInputSockets.size()];
    int poll_count = 0;
    for (it_sockets = myInputSockets.begin(); it_sockets != myInputSockets.end(); it_sockets++)
    {
        items[poll_count].socket = *it_sockets;
        items[poll_count].events = ZMQ_POLLIN;
        poll_count++;
    }
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Setting up socket for sending allow request
    // 2. Connecting to the desired port for allowance communication

    void *soc = zmq_socket(ctx, ZMQ_REQ);
    std::cout << std::endl;
    zmq_connect(soc, ("tcp://127.0.0.1:" + std::to_string(my_portgen_port)).c_str());
    std::cout << "(" << mycomp << ") is sending allow request to (BOSS) to get allowance for the next step ....." << std::endl
              << std::endl;
    // ******************************************************************************************** //

    // ***************************************** MAIN LOOP **************************************** //
    // 1. Send request to Boss to collect allowance for the next step
    // 2. Publish all your serialized outputs over determined ports for each signal
    // 3. Activate the poller of this component to collect inputs from other components
    // 4. After filling up all the polls for each input for this component, receive inputs into this component
    // 5. After receiving the inputs into this component, run this component to produce output for next step

    for (int i = 1; i <= simulation_time; i++)
    {
        // *1*
        CurrComp.GiveAllowRequestGetAllowReply(my_portgen_port, mycomp, soc);

        // *2*
        int serial_out_count = 0;
        for (it_sockets = myOutputSockets.begin(); it_sockets != myOutputSockets.end(); it_sockets++)
        {
            zmq_send(*it_sockets, serialized_output_messages[serial_out_count].c_str(), serialized_output_messages[serial_out_count].size(), 0);
            serial_out_count++;
        }

        // *3*
        zmq_msg_t update;
        zmq_msg_init(&update);
        int revent_counter;
        if (poll_count != 0)
        {
            while (true)
            {
                zmq_poll(items, poll_count, -1);
                revent_counter = 0;
                for (int j = 0; j < poll_count; j++)
                {
                    if (items[j].revents == 1)
                    {
                        revent_counter++;
                    }
                }

                if (revent_counter == poll_count)
                {
                    break;
                }
            }
        }

        // *4*
        for (int k = 0; k < poll_count; k++)
        {
            if (items[k].revents & ZMQ_POLLIN)
            {
                zmq_msg_recv(&update, items[k].socket, 0);
                update_msg = std::string(static_cast<char *>(zmq_msg_data(&update)), zmq_msg_size(&update));
                serialized_received_messages[k] = update_msg;
            }
        }
        CurrCompMessages.SetInputMsgs(serialized_received_messages);

        // *5*
        LibD.StepRun(execution_time);
        serialized_output_messages = CurrCompMessages.SetOutputMsgs(i);
    }
    //zmq_ctx_term(ctx);

    return 0;
}