#include "all_sockets.h"
#include "all_components.h"

#ifndef DEFINED_TYPEDEF_FOR_COMPD_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPD_FULL_HEADER_

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

#ifndef DEFINED_TYPEDEF_FOR_CompD_Inputs_
#define DEFINED_TYPEDEF_FOR_CompD_Inputs_

typedef struct {
    Cstruct C[3];
    double G;
    int K;
} CompD_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompD_Outputs_
#define DEFINED_TYPEDEF_FOR_CompD_Outputs_

typedef struct {
    float H[5];
    float L;
    int M;
    bool isActive;
    int portGenPort;
} CompD_Outputs;

#endif
#endif