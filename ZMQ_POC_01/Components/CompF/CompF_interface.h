#ifndef DEFINED_TYPEDEF_FOR_COMPF_INTERFACE_
#define DEFINED_TYPEDEF_FOR_COMPF_INTERFACE_

#include <string>
#include <list>
#include "all_components.h"

class CompF_Interface
{
    std::list<Comp_InputDetails> CompF_myInputDetails;
    std::list<Comp_OutputDetails> CompF_myOutputDetails;

public:
    CompF_Interface();

    std::list<Comp_InputDetails> Inputs();
    std::list<Comp_OutputDetails> Outputs();
};

#endif