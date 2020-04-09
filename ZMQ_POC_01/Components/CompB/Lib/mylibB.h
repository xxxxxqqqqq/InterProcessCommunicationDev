#ifndef DEFINED_TYPEDEF_FOR_MYLIBB_
#define DEFINED_TYPEDEF_FOR_MYLIBB_

#include <unistd.h>

class mylibB
{
public:
    mylibB();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif