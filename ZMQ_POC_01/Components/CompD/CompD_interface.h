#ifndef DEFINED_TYPEDEF_FOR_COMPD_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPD_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompD_Interface
{
    std::list<Comp_InputDetails> CompD_myInputDetails;
    std::list<Comp_OutputDetails> CompD_myOutputDetails;

public:
    CompD_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif