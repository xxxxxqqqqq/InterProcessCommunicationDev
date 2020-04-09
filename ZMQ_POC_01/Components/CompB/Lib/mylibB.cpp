#include "mylibB.h"

mylibB::mylibB(){

};

void mylibB::InitializeRun(int exectime)
{
    usleep(exectime);
}

void mylibB::StepRun(int exectime)
{
    usleep(exectime);
}

