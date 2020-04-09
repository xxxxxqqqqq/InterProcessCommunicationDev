#ifndef DEFINED_TYPEDEF_FOR_COMPB_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPB_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompB_Interface
{
    std::list<Comp_InputDetails> CompB_myInputDetails;
    std::list<Comp_OutputDetails> CompB_myOutputDetails;

public:
    CompB_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif