#include "mylibD.h"

mylibD::mylibD(){

};

void mylibD::InitializeRun(int exectime)
{
    usleep(exectime);
}

void mylibD::StepRun(int exectime)
{
    usleep(exectime);
}

