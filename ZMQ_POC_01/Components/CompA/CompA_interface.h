#ifndef DEFINED_TYPEDEF_FOR_COMPA_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPA_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompA_Interface
{
    std::list<Comp_InputDetails> CompA_myInputDetails;
    std::list<Comp_OutputDetails> CompA_myOutputDetails;

public:
    CompA_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif