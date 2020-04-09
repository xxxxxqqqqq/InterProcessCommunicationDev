#ifndef DEFINED_TYPEDEF_FOR_COMPE_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPE_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompE_Interface
{
    std::list<Comp_InputDetails> CompE_myInputDetails;
    std::list<Comp_OutputDetails> CompE_myOutputDetails;

public:
    CompE_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif