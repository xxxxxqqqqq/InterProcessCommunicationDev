#include "mylibE.h"

mylibE::mylibE(){

};

void mylibE::InitializeRun(int exectime)
{
    usleep(exectime);
}

void mylibE::StepRun(int exectime)
{
    usleep(exectime);
}

