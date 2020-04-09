#ifndef DEFINED_TYPEDEF_FOR_PORT_GENERATOR_
#define DEFINED_TYPEDEF_FOR_PORT_GENERATOR_

#include "CompA.h"
#include "CompB.h"
#include "CompC.h"
#include "CompD.h"
#include "CompE.h"
#include "CompF.h"
#include <zmq.hpp>
#include "all_components.h"
#include "all_sockets.h"
#include "CompA_interface.h"
#include "CompB_interface.h"
#include "CompC_interface.h"
#include "CompD_interface.h"
#include "CompE_interface.h"
#include "CompF_interface.h"

class PortGenerator
{
    // INPUTS
    CompA_Inputs A_Inputs;
    CompB_Inputs B_Inputs;
    CompC_Inputs C_Inputs;
    CompD_Inputs D_Inputs;
    CompE_Inputs E_Inputs;
    CompF_Inputs F_Inputs;

    // OUTPUTS
    CompA_Outputs A_Outputs;
    CompB_Outputs B_Outputs;
    CompC_Outputs C_Outputs;
    CompD_Outputs D_Outputs;
    CompE_Outputs E_Outputs;
    CompF_Outputs F_Outputs;
    
    public:
    PortGenerator();

    void initActivation();
    int setActivation(int number_of_comps);
    int SetPortGenCompPorts(int startingport);
};

#endif

