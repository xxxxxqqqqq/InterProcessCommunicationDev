#ifndef DEFINED_TYPEDEF_FOR_MYLIBD_
#define DEFINED_TYPEDEF_FOR_MYLIBD_

#include <unistd.h>

class mylibD
{
public:
    mylibD();

    void InitializeRun(int exectime);
    void StepRun(int exectime);
};

#endif