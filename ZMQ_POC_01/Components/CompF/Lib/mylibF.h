#ifndef DEFINED_TYPEDEF_FOR_MYLIBF_
#define DEFINED_TYPEDEF_FOR_MYLIBF_

#include <unistd.h>

class mylibF
{
public:
    mylibF();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif