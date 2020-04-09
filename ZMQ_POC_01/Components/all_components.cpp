#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "all_components.h"
#include "CompA.h"
#include "CompB.h"
#include "CompC.h"
#include "CompD.h"
#include "CompE.h"
#include "CompF.h"

// ******************************************************************************************** //
GenericComp::GenericComp(){

};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Searching given "InputName" inside "outputs"
// 2. If it is found, returning the corresponding inter-component port, if not, returning "-1"
int GenericComp::InterCompMapInputToOutput(std::string InputName, std::list<Comp_OutputDetails> outputs)
{
    std::list<Comp_OutputDetails>::iterator it;
    for (it = outputs.begin(); it != outputs.end(); it++)
    {
        if (InputName.compare(it->OutputName) == 0)
        {
            return it->InterCompPort;
        }
    }
    return -1;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Looping through the elements of given "inputs" and tries to find under given "outputs"
// 2. Prints message including port information if found
// 3. Returning the "inputs"
std::list<Comp_InputDetails> GenericComp::MapInterCompInputPorts(std::list<Comp_InputDetails> inputs, std::list<Comp_OutputDetails> outputs, std::string mycomp)
{
    std::list<Comp_InputDetails>::iterator it;
    for (it = inputs.begin(); it != inputs.end(); it++)
    {
        int my_intercomp_port = this->InterCompMapInputToOutput(it->InputName, outputs);
        if (my_intercomp_port != -1)
        {
            it->InterCompPort = my_intercomp_port;
            std::cout << "(" << mycomp << ") Input (" << it->InputName << ") will subscribe to port (" << it->InterCompPort << ")" << std::endl;
        }
    }
    return inputs;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Setting inter-component output ports for given component
// 2. Returning "outputs" filled with inter-component port information
std::list<Comp_OutputDetails> GenericComp::SetInterCompOutputPorts(std::list<Comp_OutputDetails> outputs, int lastport, std::string mycomp)
{
    std::list<Comp_OutputDetails>::iterator it;
    for (it = outputs.begin(); it != outputs.end(); it++)
    {
        it->InterCompPort = lastport;
        lastport++;
        std::cout << "(" << mycomp << ") Output (" << it->OutputName << ") will publish to port (" << it->InterCompPort << ")" << std::endl;
    }
    return outputs;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Gets input request from given "Comp"
// 2. Prints information of what is about to be replied back to given "Comp" regarding inputs
// 3. Replies back inter-component port for inputs to given "Comp"
// 4. Closing used sockets and terminating context, used in this communication
void GenericComp::GetInRequestGiveInReply(std::list<Comp_InputDetails> inputs, int my_portgen_port, std::string mycomp)
{   
    // *1*
    std::list<Comp_InputDetails>::iterator it_in;
    std::cout << "*** (PortGenerator) <-> (" << mycomp << ") Inputs ***" << std::endl
              << std::endl;

    void *ctx = zmq_ctx_new();
    void *soc = zmq_socket(ctx, ZMQ_REP);
    std::cout << std::endl;
    zmq_bind(soc, ("tcp://127.0.0.1:" + std::to_string(my_portgen_port)).c_str());
    zmq_msg_t component_req_in;
    zmq_msg_init(&component_req_in);
    std::cout << "(PortGenerator) is waiting for a request from (" << mycomp << ") to collect input interface ....." << std::endl
              << std::endl;

    // *2*
    for (it_in = inputs.begin(); it_in != inputs.end(); it_in++)
    {
        zmq_msg_recv(&component_req_in, soc, 0);
        std::string component_req_in_content = std::string(static_cast<char *>(zmq_msg_data(&component_req_in)), zmq_msg_size(&component_req_in));
        std::cout << component_req_in_content << " is taken from (" << mycomp << *")" << std::endl;

        std::string InputName = it_in->InputName;
        std::string DataType = it_in->DataType;
        int Dimension = it_in->Dimension;
        int InterCompPort = it_in->InterCompPort;

        std::cout << "(InputName: " << InputName << ")--"
                  << "(DataType: " << DataType << ")--"
                  << "(Dimension: " << Dimension << ")--"
                  << "(Assigned Port Number: " << InterCompPort << ")" << std::endl
                  << std::endl;
        // *3*
        zmq_send(soc, std::to_string(InterCompPort).c_str(), std::to_string(InterCompPort).size(), 0);
    }

    // *4*
    zmq_close(soc);
    zmq_ctx_term(ctx);
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Gets output request from given "Comp"
// 2. Prints information of what is about to be replied back to given "Comp" regarding outputs
// 3. Replies back inter-component port for outputs to given "Comp"
// 4. Closing used sockets and terminating context, used in this communication
void GenericComp::GetOutRequestGiveOutReply(std::list<Comp_OutputDetails> outputs, int my_portgen_port, std::string mycomp)
{
    // *1*
    std::list<Comp_OutputDetails>::iterator it_out;
    std::cout << "*** (PortGenerator) <-> (" << mycomp << ") Outputs ***" << std::endl
              << std::endl;

    void *ctx = zmq_ctx_new();
    void *soc = zmq_socket(ctx, ZMQ_REP);
    std::cout << std::endl;
    zmq_bind(soc, ("tcp://127.0.0.1:" + std::to_string(my_portgen_port)).c_str());
    zmq_msg_t component_req_out;
    zmq_msg_init(&component_req_out);
    std::cout << "(PortGenerator) is waiting for a request from (" << mycomp << ") to collect output interface ....." << std::endl
              << std::endl;

    // *2*
    for (it_out = outputs.begin(); it_out != outputs.end(); it_out++)
    {
        zmq_msg_recv(&component_req_out, soc, 0);
        std::string component_req_out_content = std::string(static_cast<char *>(zmq_msg_data(&component_req_out)), zmq_msg_size(&component_req_out));
        std::cout << component_req_out_content << " is taken from (" << mycomp << *")" << std::endl;

        std::string OutputName = it_out->OutputName;
        std::string DataType = it_out->DataType;
        int Dimension = it_out->Dimension;
        int InterCompPort = it_out->InterCompPort;

        std::cout << "(OutputName: " << OutputName << ")--"
                  << "(DataType: " << DataType << ")--"
                  << "(Dimension: " << Dimension << ")--"
                  << "(Assigned Port Number: " << InterCompPort << ")" << std::endl
                  << std::endl;
        // *3*
        zmq_send(soc, std::to_string(InterCompPort).c_str(), std::to_string(InterCompPort).size(), 0);
    }

    // *4*
    zmq_close(soc);
    zmq_ctx_term(ctx);
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Gives input request from given "Comp"
// 2. Prints information of what is about to be replied back into curent "Comp" regarding inputs
// 3. Gets replies back about inter-component port for inputs into current "Comp"
// 4. Closing used sockets and terminating context, used in this communication and returns inputs
std::vector<int> GenericComp::GiveInRequestGetInReply(std::list<Comp_InputDetails> inputs, int my_portgen_port, std::string mycomp)
{
    // *1*
    std::string in_req_msg;
    std::string comp_ininfo_content;
    std::vector<int> inport_collector;
    std::list<Comp_InputDetails>::iterator it_in;
    std::cout << std::endl << "*** (BOSS) <-> (" << mycomp << ") Inputs ***" << std::endl
              << std::endl;

    void *ctx = zmq_ctx_new();
    void *soc = zmq_socket(ctx, ZMQ_REQ);
    std::cout << std::endl;
    zmq_connect(soc, ("tcp://127.0.0.1:" + std::to_string(my_portgen_port)).c_str());
    std::cout << "(" << mycomp << ") is sending request to (BOSS) to collect its input communication ports ....." << std::endl
              << std::endl;

    // *2*
    for (it_in = inputs.begin(); it_in != inputs.end(); it_in++)
    {
        in_req_msg = it_in->InputName + "_INREQUEST";
        zmq_send(soc, in_req_msg.c_str(), in_req_msg.size(), 0);
        std::cout << in_req_msg << " from (" << mycomp << ") is successfully sent to (BOSS) " << std::endl;

        zmq_msg_t comp_collectinfo_msg;
        zmq_msg_init(&comp_collectinfo_msg);
        std::cout << "(" << mycomp << ") is waiting for a reply from (BOSS) ....." << std::endl;
        
        // *3*
        zmq_msg_recv(&comp_collectinfo_msg, soc, 0);
        comp_ininfo_content = std::string(static_cast<char *>(zmq_msg_data(&comp_collectinfo_msg)), zmq_msg_size(&comp_collectinfo_msg));
        inport_collector.push_back(std::stoi(comp_ininfo_content));
        std::cout << "(" << mycomp << ") successfully collected the input port reply from (BOSS) ....." << std::endl
                  << std::endl;
    }

    // *4*
    zmq_close(soc);
    zmq_ctx_term(ctx);
    return inport_collector;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Gives output request from given "Comp"
// 2. Prints information of what is about to be replied back into curent "Comp" regarding outputs
// 3. Gets replies back about inter-component port for outputs into current "Comp"
// 4. Closing used sockets and terminating context, used in this communication and returns outputs
std::vector<int> GenericComp::GiveOutRequestGetOutReply(std::list<Comp_OutputDetails> outputs, int my_portgen_port, std::string mycomp)
{
    // *1*
    std::string out_req_msg;
    std::string comp_outinfo_content;
    std::vector<int> outport_collector;
    std::list<Comp_OutputDetails>::iterator it_out;
    std::cout << std::endl << "*** (BOSS) <-> (" << mycomp << ") Outputs ***" << std::endl
              << std::endl;

    void *ctx = zmq_ctx_new();
    void *soc = zmq_socket(ctx, ZMQ_REQ);
    std::cout << std::endl;
    zmq_connect(soc, ("tcp://127.0.0.1:" + std::to_string(my_portgen_port)).c_str());
    std::cout << "(" << mycomp << ") is sending request to (BOSS) to collect its output communication ports ....." << std::endl
              << std::endl;

    // *2*
    for (it_out = outputs.begin(); it_out != outputs.end(); it_out++)
    {
        out_req_msg = it_out->OutputName + "_OUTREQUEST";
        zmq_send(soc, out_req_msg.c_str(), out_req_msg.size(), 0);
        std::cout << out_req_msg << " from (" << mycomp << ") is successfully sent to (BOSS) " << std::endl;

        zmq_msg_t comp_collectinfo_msg;
        zmq_msg_init(&comp_collectinfo_msg);
        std::cout << "(" << mycomp << ") is waiting for a reply from (BOSS) ....." << std::endl;

        // *3*
        zmq_msg_recv(&comp_collectinfo_msg, soc, 0);
        comp_outinfo_content = std::string(static_cast<char *>(zmq_msg_data(&comp_collectinfo_msg)), zmq_msg_size(&comp_collectinfo_msg));
        outport_collector.push_back(std::stoi(comp_outinfo_content));
        std::cout << "(" << mycomp << ") successfully collected the output port reply from (BOSS) ....." << std::endl
                  << std::endl;
    }

    // *4*
    zmq_close(soc);
    zmq_ctx_term(ctx);
    return outport_collector;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Distributing all inputs to the desired components;
// 2. Returning inputs filled with inter-component port information
std::list<Comp_InputDetails> GenericComp::DistributeInputsToComp(std::list<Comp_InputDetails> inputs, std::vector<int> inputcollector, std::string mycomp)
{
    std::list<Comp_InputDetails>::iterator it_in;
    int count = 0;

    for (it_in = inputs.begin(); it_in != inputs.end(); it_in++)
    {
        it_in->InterCompPort = inputcollector[count];
        count++;
    }
    return inputs;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Distributing all outputs to the desired components;
// 2. Returning outputs filled with inter-component port information
std::list<Comp_OutputDetails> GenericComp::DistributeOutputsToComp(std::list<Comp_OutputDetails> outputs, std::vector<int> outputcollector, std::string mycomp)
{
    std::list<Comp_OutputDetails>::iterator it_out;
    int count = 0;

    for (it_out = outputs.begin(); it_out != outputs.end(); it_out++)
    {
        it_out->InterCompPort = outputcollector[count];
        count++;
    }
    return outputs;
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Gives allow request from given "Comp"
// 2. Gets replies back about allowance
// 3. Closing used sockets and terminating context, used in this communication and returns inputs
void GenericComp::GiveAllowRequestGetAllowReply(int my_portgen_port, std::string mycomp, void *soc)
{
    // *1*
    std::string get_allowance_req_msg = mycomp + "_ALLOWREQUEST";
    zmq_send(soc, get_allowance_req_msg.c_str(), get_allowance_req_msg.size(), 0);
    std::cout << get_allowance_req_msg << " from (" << mycomp << ") is successfully sent to (BOSS) " << std::endl;

    // *2*
    zmq_msg_t allowance_msg;
    zmq_msg_init(&allowance_msg);
    std::cout << "(" << mycomp << ") is waiting for a allow reply from (BOSS) ....." << std::endl;
    zmq_msg_recv(&allowance_msg, soc, 0);
    std::cout << "(" << mycomp << ") successfully collected the allowance reply from (BOSS) ....." << std::endl
        << std::endl;
    
    // *3*
    //zmq_close(soc);
};
// ******************************************************************************************** //

// ******************************************************************************************** //
// 1. Creates poller for collecting all requests from all "Comp"
// 2. Collects all requests into the poller coming from all "Comp"
// 3. Receives all requests from all "Comp"
// 4. Replies back allowance for all "Comp" for them to start next step adn then closes the used sockets
// 5. Terminating context, used in this communication
void GenericComp::GetAllowRequestGiveAllowReply(int my_portgen_port, int comp_nbr, std::list<void(*)> mySockets)
{
    // *1*
    std::list<void(*)>::iterator it_sockets;

    zmq_pollitem_t items[mySockets.size()];
    int poll_count = 0;
    for (it_sockets = mySockets.begin(); it_sockets != mySockets.end(); it_sockets++)
    {
        items[poll_count].socket = *it_sockets;
        items[poll_count].events = ZMQ_POLLIN;
        poll_count++;
    }

    // *2*
    zmq_msg_t allowance_msg;
    zmq_msg_init(&allowance_msg);
    int revent_counter;
    if (poll_count != 0)
    {
        while(true)
        {
            zmq_poll(items, poll_count, -1);
            revent_counter = 0;
            for (int j=0; j<poll_count; j++)
            {
                if(items[j].revents == 1)
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

    // *3*
    std::string allowance_msg_req;
    for (int k=0; k<poll_count; k++)
    {
        if (items[k].revents & ZMQ_POLLIN)
        {
            zmq_msg_recv(&allowance_msg, items[k].socket, 0);
            allowance_msg_req = std::string(static_cast<char *>(zmq_msg_data(&allowance_msg)), zmq_msg_size(&allowance_msg));
            std::cout << std::endl << allowance_msg_req << " is successfully taken" << std::endl;
        }
    }
    
    // *4*
    std::string get_allowance_rep_msg = "ALLOWREPLY";
    for (it_sockets = mySockets.begin(); it_sockets != mySockets.end(); it_sockets++)
    {
        zmq_send(*it_sockets, get_allowance_rep_msg.c_str(), get_allowance_rep_msg.size(), 0);
        //zmq_close(*it_sockets);
    }
    std::cout << std::endl << "All Components are now allowed to proceed" << std::endl;
};