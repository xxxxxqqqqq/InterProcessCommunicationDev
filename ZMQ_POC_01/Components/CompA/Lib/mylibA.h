#ifndef DEFINED_TYPEDEF_FOR_MYLIBA_
#define DEFINED_TYPEDEF_FOR_MYLIBA_

#include <unistd.h>

class mylibA
{
public:
    mylibA();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif