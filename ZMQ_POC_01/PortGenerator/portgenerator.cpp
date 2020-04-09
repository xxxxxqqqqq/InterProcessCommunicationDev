#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include <time.h>
#include "portgenerator.h"


// "PortGenerator" -> Class Constructor
PortGenerator::PortGenerator(){

};

// "PortGenerator" -> Components are initialized as non-active
void PortGenerator::initActivation()
{
    A_Outputs.isActive = false;
    B_Outputs.isActive = false;
    C_Outputs.isActive = false;
    D_Outputs.isActive = false;
    E_Outputs.isActive = false;
    F_Outputs.isActive = false;
};

// "PortGenerator" -> Desired components are activated
int PortGenerator::setActivation(int number_of_comps)
{
    int active_counter = 0;
    if (number_of_comps == 0)
    {
        std::cout << "ERROR! -> No components were specified" << std::endl;
        return -1;
    };
    if (number_of_comps > 0)
    {
        A_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 1)
    {
        B_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 2)
    {
        C_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 3)
    {
        D_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 4)
    {
        E_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 5)
    {
        F_Outputs.isActive = true;
        active_counter++;
    };
    if (number_of_comps > 6)
    {
        std::cout << "ERROR! -> CSPAS does not support this amount of components as different processes for now" << std::endl;
        return -1;
    }
    return active_counter;
};

// "PortGenerator" -> Ports between all components and "PortGenerator" are set
int PortGenerator::SetPortGenCompPorts(int startingport)
{
    std::cout << "*** BOSS <-> All Components ***" << std::endl
              << std::endl;
    A_Outputs.portGenPort = startingport;
    std::cout << "(CompA - BOSS) will be communicated via (" << A_Outputs.portGenPort << ")" << std::endl;
    B_Outputs.portGenPort = A_Outputs.portGenPort + 1;
    std::cout << "(CompB - BOSS) will be communicated via (" << B_Outputs.portGenPort << ")" << std::endl;
    C_Outputs.portGenPort = B_Outputs.portGenPort + 1;
    std::cout << "(CompC - BOSS) will be communicated via (" << C_Outputs.portGenPort << ")" << std::endl;
    D_Outputs.portGenPort = C_Outputs.portGenPort + 1;
    std::cout << "(CompD - BOSS) will be communicated via (" << D_Outputs.portGenPort << ")" << std::endl;
    E_Outputs.portGenPort = D_Outputs.portGenPort + 1;
    std::cout << "(CompE - BOSS) will be communicated via (" << E_Outputs.portGenPort << ")" << std::endl;
    F_Outputs.portGenPort = E_Outputs.portGenPort + 1;
    std::cout << "(CompF - BOSS) will be communicated via (" << F_Outputs.portGenPort << ")" << std::endl
              << std::endl;
    return F_Outputs.portGenPort + 1;
};

int main(int argc, char *argv[])
{
    // ******************************************************************************************** //
    int startingport, simulation_time;
    bool count_comps = false;
    bool check_port = false;
    bool sim_time = false;
    int comp_selector = 0;
    std::map<std::string, std::string> comp_matcher;
    std::string default_comp = "Comp";
    std::vector<std::string> all_comps;
    std::list<Comp_InputDetails> CompAInputs, CompBInputs, CompCInputs, CompDInputs, CompEInputs, CompFInputs;
    std::list<Comp_OutputDetails> CompAOutputs, CompBOutputs, CompCOutputs, CompDOutputs, CompEOutputs, CompFOutputs;
    std::list<void(*)> mySockets;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Parsing the command line argument
    // 2. Allocating component shells
    // 3. Initializing the starting port
    std::cout << std::endl
              << "*** Allocated Component Shells ***" << std::endl
              << std::endl;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-comps") == 0)
        {
            count_comps = true;
        };
        if (strcmp(argv[i], "-port") == 0)
        {
            check_port = true;
            count_comps = false;
        };

        if (strcmp(argv[i], "-simtime") == 0)
        {
            sim_time = true;
            count_comps = false;
            check_port = false;
        };

        if (count_comps && strcmp(argv[i], "-comps") != 0)
        {
            char ascii_compcheck = (char)65 + comp_selector;
            comp_matcher[default_comp + ascii_compcheck] = argv[i];
            std::cout << "(" << argv[i] << ")"
                      << " is assigned to ("
                      << default_comp + ascii_compcheck << ") in CSPAS" << std::endl;
            all_comps.push_back(default_comp + ascii_compcheck);
            comp_selector++;
        }
        if (check_port && strcmp(argv[i], "-port") != 0)
        {
            startingport = std::stoi(argv[i]);
            std::cout << "Starting port is: " << startingport << std::endl;
        }
        if (sim_time && strcmp(argv[i], "-simtime") != 0)
        {
            simulation_time = std::stoi(argv[i]);
            std::cout << "Simulation time is: " << simulation_time << std::endl;
        }
    }
    std::cout << std::endl;
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Create PortGenerator
    // 2. Initialize all components as non-active
    // 3. Activate desired amount of components
    // 4. Set up ports for communication between Port Generator and components
    PortGenerator portgenerator;

    portgenerator.initActivation();

    int comp_nbr = portgenerator.setActivation(comp_matcher.size());
    if (comp_matcher.size() != comp_nbr)
    {
        std::cout << "ERROR! -> The number of selected components *" << comp_matcher.size()
                  << "* DOES NOT MATCH with the number of activated components *" << comp_nbr
                  << "*" << std::endl;
        return -1;
    }

    int lastport = portgenerator.SetPortGenCompPorts(startingport);
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Initialiazing component interfaces
    // 2. Getting inputs
    // 3. Getting outputs
    CompA_Interface CompAInterface;
    CompB_Interface CompBInterface;
    CompC_Interface CompCInterface;
    CompD_Interface CompDInterface;
    CompE_Interface CompEInterface;
    CompF_Interface CompFInterface;

    CompAInputs = CompAInterface.Inputs();
    CompBInputs = CompBInterface.Inputs();
    CompCInputs = CompCInterface.Inputs();
    CompDInputs = CompDInterface.Inputs();
    CompEInputs = CompEInterface.Inputs();
    CompFInputs = CompFInterface.Inputs();

    CompAOutputs = CompAInterface.Outputs();
    CompBOutputs = CompBInterface.Outputs();
    CompCOutputs = CompCInterface.Outputs();
    CompDOutputs = CompDInterface.Outputs();
    CompEOutputs = CompEInterface.Outputs();
    CompFOutputs = CompFInterface.Outputs();
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Initializing generic component class for all components
    // 2. Setting inter-component output ports for each component
    // 3. Mapping inter-component input ports for each component
    GenericComp CompA;
    GenericComp CompB;
    GenericComp CompC;
    GenericComp CompD;
    GenericComp CompE;
    GenericComp CompF;
    GenericComp Comp;

    std::cout << std::endl << "*** Inter-Component (CompA) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompAOutputs = CompA.SetInterCompOutputPorts(CompAOutputs, lastport, "CompA");
    lastport = lastport + CompAOutputs.size();
    std::cout << std::endl << "*** Inter-Component (CompB) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompBOutputs = CompB.SetInterCompOutputPorts(CompBOutputs, lastport, "CompB");
    lastport = lastport + CompBOutputs.size();
    std::cout << std::endl << "*** Inter-Component (CompC) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompCOutputs = CompC.SetInterCompOutputPorts(CompCOutputs, lastport, "CompC");
    lastport = lastport + CompCOutputs.size();
    std::cout << std::endl << "*** Inter-Component (CompD) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompDOutputs = CompD.SetInterCompOutputPorts(CompDOutputs, lastport, "CompD");
    lastport = lastport + CompDOutputs.size();
    std::cout << std::endl << "*** Inter-Component (CompE) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompEOutputs = CompE.SetInterCompOutputPorts(CompEOutputs, lastport, "CompE");
    lastport = lastport + CompEOutputs.size();
    std::cout << std::endl << "*** Inter-Component (CompF) <-> Assigned Output Ports ***" << std::endl
              << std::endl;
    CompFOutputs = CompF.SetInterCompOutputPorts(CompFOutputs, lastport, "CompF");
    lastport = lastport + CompFOutputs.size();
    std::cout << std::endl;

    std::cout << std::endl << "*** Inter-Component (CompA) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompAOutputs, "CompA");
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompBOutputs, "CompA");
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompCOutputs, "CompA");
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompDOutputs, "CompA");
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompEOutputs, "CompA");
    CompAInputs = CompA.MapInterCompInputPorts(CompAInputs, CompFOutputs, "CompA");
    std::cout << std::endl << "*** Inter-Component (CompB) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompAOutputs, "CompB");
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompBOutputs, "CompB");
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompCOutputs, "CompB");
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompDOutputs, "CompB");
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompEOutputs, "CompB");
    CompBInputs = CompB.MapInterCompInputPorts(CompBInputs, CompFOutputs, "CompB");
    std::cout << std::endl << "*** Inter-Component (CompC) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompAOutputs, "CompC");
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompBOutputs, "CompC");
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompCOutputs, "CompC");
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompDOutputs, "CompC");
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompEOutputs, "CompC");
    CompCInputs = CompC.MapInterCompInputPorts(CompCInputs, CompFOutputs, "CompC");
    std::cout << std::endl << "*** Inter-Component (CompD) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompAOutputs, "CompD");
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompBOutputs, "CompD");
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompCOutputs, "CompD");
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompDOutputs, "CompD");
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompEOutputs, "CompD");
    CompDInputs = CompD.MapInterCompInputPorts(CompDInputs, CompFOutputs, "CompD");
    std::cout << std::endl << "*** Inter-Component (CompE) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompAOutputs, "CompE");
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompBOutputs, "CompE");
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompCOutputs, "CompE");
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompDOutputs, "CompE");
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompEOutputs, "CompE");
    CompEInputs = CompE.MapInterCompInputPorts(CompEInputs, CompFOutputs, "CompE");
    std::cout << std::endl << "*** Inter-Component (CompF) <-> Assigned Input Ports ***" << std::endl
              << std::endl;
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompAOutputs, "CompF");
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompBOutputs, "CompF");
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompCOutputs, "CompF");
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompDOutputs, "CompF");
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompEOutputs, "CompF");
    CompFInputs = CompF.MapInterCompInputPorts(CompFInputs, CompFOutputs, "CompF");
    std::cout << std::endl;

    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Get Request from CompA and give Reply to CompA
    // 2. Get Request from CompB and give Reply to CompB
    // 3. Get Request from CompC and give Reply to CompC
    // 4. Get Request from CompD and give Reply to CompD
    // 5. Get Request from CompE and give Reply to CompE
    // 6. Get Request from CompF and give Reply to CompF
    CompA.GetInRequestGiveInReply(CompAInputs, startingport, "CompA");
    CompA.GetOutRequestGiveOutReply(CompAOutputs, startingport, "CompA");

    CompB.GetInRequestGiveInReply(CompBInputs, startingport + 1, "CompB");
    CompB.GetOutRequestGiveOutReply(CompBOutputs, startingport + 1, "CompB");

    CompC.GetInRequestGiveInReply(CompCInputs, startingport + 2, "CompC");
    CompC.GetOutRequestGiveOutReply(CompCOutputs, startingport + 2, "CompC");

    CompD.GetInRequestGiveInReply(CompDInputs, startingport + 3, "CompD");
    CompD.GetOutRequestGiveOutReply(CompDOutputs, startingport + 3, "CompD");

    CompE.GetInRequestGiveInReply(CompEInputs, startingport + 4, "CompE");
    CompE.GetOutRequestGiveOutReply(CompEOutputs, startingport + 4, "CompE");

    CompF.GetInRequestGiveInReply(CompFInputs, startingport + 5, "CompF");
    CompF.GetOutRequestGiveOutReply(CompFOutputs, startingport + 5, "CompF");
    // ******************************************************************************************** //

    // ******************************************************************************************** //
    // 1. Creating port-generator sockets for providing allowance to components
    // 2. Initializing all these sockets
    // 3. Extracting only necessary amount of sockets out of all ZMQ Sockets
    // 4. Binding desired sockets for allow request to desired ports
    AvailableSockets PortGenerator_Sockets;

    PortGenerator_Sockets.InitializeSockets();

    mySockets = PortGenerator_Sockets.GetSockets(comp_nbr, 0);

    std::list<void(*)>::iterator it_sockets;
    void *ctx = zmq_ctx_new();
    int pub_count = 0;
    for (it_sockets = mySockets.begin(); it_sockets != mySockets.end(); it_sockets++)
    {
        *it_sockets = zmq_socket(ctx, ZMQ_REP);
        zmq_bind(*it_sockets, ("tcp://127.0.0.1:" + std::to_string(startingport+pub_count)).c_str());
        pub_count++;  
    }
    // ******************************************************************************************** //

    // **************************************** MAIN LOOP ***************************************** //
    clock_t begin = clock();
    for (int i=1; i <= simulation_time; i++)
    {
        Comp.GetAllowRequestGiveAllowReply(startingport, comp_nbr, mySockets);  
    }
    //zmq_ctx_term(ctx);
    clock_t end = clock();
    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    std::cout << "THIS RUN TOOK : " << time_spent << " SECONDS" << std::endl;
    
    return 0;
}
