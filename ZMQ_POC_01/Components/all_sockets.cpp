#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <map>
#include "all_sockets.h"

AvailableSockets::AvailableSockets(){

};

void AvailableSockets::InitializeSockets()
{
    initialized_sockets =
        {
            soc001, soc002, soc003, soc004, soc005,
            soc006, soc007, soc008, soc009, soc010,
            soc011, soc012, soc013, soc014, soc015,
            soc016, soc017, soc018, soc019, soc020};
};

// ******************************************************************************************** //
// 1. Get the number of inputs and outputs from requested place
// 2. Returns the same amount of sockets to that place
std::list<void(*)> AvailableSockets::GetSockets(int inputsockets, int outputsockets)
{
    std::list<void(*)> return_sockets;
    std::list<void(*)>::iterator it;
    int count = 0;
    for (it = initialized_sockets.begin(); it != initialized_sockets.end(); it++)
    {
        return_sockets.push_back(*it);
        count++;

        if (count == (inputsockets + outputsockets))
        {
            break;
        }
    }
    return return_sockets;
};
// ******************************************************************************************** //