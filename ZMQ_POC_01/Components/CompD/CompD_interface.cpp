#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "CompD_interface.h"

CompD_Interface::CompD_Interface(){

};

std::list<Comp_InputDetails> CompD_Interface::Inputs()
{
    CompD_myInputDetails = {
        Comp_InputDetails("C", "struct", 3, 0),
        Comp_InputDetails("G", "double", 1, 0),
        Comp_InputDetails("K", "int", 1, 0)};
    
    return CompD_myInputDetails;
};

std::list<Comp_OutputDetails> CompD_Interface::Outputs()
{
    CompD_myOutputDetails = {
        Comp_OutputDetails("H", "float", 5, 0),
        Comp_OutputDetails("L", "float", 1, 0),
        Comp_OutputDetails("M", "int", 1, 0)};
    
    return CompD_myOutputDetails;
};