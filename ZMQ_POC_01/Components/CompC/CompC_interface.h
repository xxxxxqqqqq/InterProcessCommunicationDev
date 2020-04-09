#ifndef DEFINED_TYPEDEF_FOR_COMPC_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPC_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompC_Interface
{
    std::list<Comp_InputDetails> CompC_myInputDetails;
    std::list<Comp_OutputDetails> CompC_myOutputDetails;

public:
    CompC_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif