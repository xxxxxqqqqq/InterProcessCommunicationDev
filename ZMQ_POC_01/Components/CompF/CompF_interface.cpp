#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompF_interface.h"

CompF_Interface::CompF_Interface(){

};

std::list<Comp_InputDetails> CompF_Interface::Inputs()
{
    CompF_myInputDetails = {};

    return CompF_myInputDetails;
};

std::list<Comp_OutputDetails> CompF_Interface::Outputs()
{
    CompF_myOutputDetails = {};

    return CompF_myOutputDetails;
};