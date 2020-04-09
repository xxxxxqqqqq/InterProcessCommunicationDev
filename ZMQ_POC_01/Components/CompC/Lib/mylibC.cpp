#include "mylibC.h"

mylibC::mylibC(){

};

void mylibC::InitializeRun(int exectime)
{
    usleep(exectime);
}

void mylibC::StepRun(int exectime)
{
    usleep(exectime);
}

