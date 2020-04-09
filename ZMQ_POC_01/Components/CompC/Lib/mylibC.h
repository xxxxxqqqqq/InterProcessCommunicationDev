#ifndef DEFINED_TYPEDEF_FOR_MYLIBC_
#define DEFINED_TYPEDEF_FOR_MYLIBC_

#include <unistd.h>

class mylibC
{
public:
    mylibC();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif