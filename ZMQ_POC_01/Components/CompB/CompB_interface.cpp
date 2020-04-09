#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompB_interface.h"

CompB_Interface::CompB_Interface(){

};

std::list<Comp_InputDetails> CompB_Interface::Inputs()
{
    CompB_myInputDetails = {
        Comp_InputDetails("A", "struct", 1, 0),
        Comp_InputDetails("F", "double", 1, 0),
        Comp_InputDetails("H", "float", 5, 0)};

    return CompB_myInputDetails;
};

std::list<Comp_OutputDetails> CompB_Interface::Outputs()
{
    CompB_myOutputDetails = {
        Comp_OutputDetails("E", "bool", 1, 0),
        Comp_OutputDetails("G", "double", 1, 0),
        Comp_OutputDetails("I", "struct", 1, 0)};
    
    return CompB_myOutputDetails;
};