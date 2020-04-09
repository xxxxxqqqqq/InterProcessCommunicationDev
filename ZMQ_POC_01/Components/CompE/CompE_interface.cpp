#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompE_interface.h"

CompE_Interface::CompE_Interface(){

};

std::list<Comp_InputDetails> CompE_Interface::Inputs()
{
    CompE_myInputDetails = {
        Comp_InputDetails("C", "struct", 3, 0),
        Comp_InputDetails("I", "struct", 1, 0),
        Comp_InputDetails("M", "int", 1, 0)};

    return CompE_myInputDetails;
};

std::list<Comp_OutputDetails> CompE_Interface::Outputs()
{
    CompE_myOutputDetails = {};
    
    return CompE_myOutputDetails;
};