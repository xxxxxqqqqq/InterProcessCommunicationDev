#include "all_sockets.h"
#include "all_components.h"


#ifndef DEFINED_TYPEDEF_FOR_COMPC_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPC_FULL_HEADER_

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_Cstruct_
#define DEFINED_TYPEDEF_FOR_Cstruct_

typedef struct {
    int C_01;
    float C_02;
    double C_03;
} Cstruct;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompC_Inputs_
#define DEFINED_TYPEDEF_FOR_CompC_Inputs_

typedef struct {
    Cstruct C[3];
    bool E;
    double J;
    float L;
} CompC_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompC_Outputs_
#define DEFINED_TYPEDEF_FOR_CompC_Outputs_

typedef struct {
    double F;
    double J;
    int K;
    bool isActive;
    int portGenPort;
} CompC_Outputs;

#endif
#endif