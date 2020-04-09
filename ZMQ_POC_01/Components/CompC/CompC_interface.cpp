#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompC_interface.h"

CompC_Interface::CompC_Interface(){

};

std::list<Comp_InputDetails> CompC_Interface::Inputs()
{
    CompC_myInputDetails = {
        Comp_InputDetails("C", "struct", 3, 0),
        Comp_InputDetails("E", "bool", 1, 0),
        Comp_InputDetails("J", "double", 1, 0),
        Comp_InputDetails("L", "float", 1, 0)};

    return CompC_myInputDetails;
};

std::list<Comp_OutputDetails> CompC_Interface::Outputs()
{
    CompC_myOutputDetails = {
        Comp_OutputDetails("F", "double", 1, 0),
        Comp_OutputDetails("J", "double", 1, 0),
        Comp_OutputDetails("K", "int", 1, 0)};
    
    return CompC_myOutputDetails;
};