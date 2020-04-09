#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompA_interface.h"

CompA_Interface::CompA_Interface(){

};

std::list<Comp_InputDetails> CompA_Interface::Inputs()
{
    CompA_myInputDetails = {};

    return CompA_myInputDetails;
};

std::list<Comp_OutputDetails> CompA_Interface::Outputs()
{
    CompA_myOutputDetails = {
        Comp_OutputDetails("A", "struct", 1, 0),
        Comp_OutputDetails("B", "double", 1, 0),
        Comp_OutputDetails("C", "struct", 3, 0),
        Comp_OutputDetails("D", "float", 1, 0)};
    
    return CompA_myOutputDetails;
};