#ifndef DEFINED_TYPEDEF_FOR_MYLIBE_
#define DEFINED_TYPEDEF_FOR_MYLIBE_

#include <unistd.h>

class mylibE
{
public:
    mylibE();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif