#include "all_sockets.h"
#include "all_components.h"

#ifndef DEFINED_TYPEDEF_FOR_COMPE_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPE_FULL_HEADER_

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_Iinternal_
#define DEFINED_TYPEDEF_FOR_Iinternal_

typedef struct {
    int I_01_01;
    float I_01_02;
} Iinternal;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_I_
#define DEFINED_TYPEDEF_FOR_I_

typedef struct {
    Iinternal I_01;
} Istruct;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompE_Inputs_
#define DEFINED_TYPEDEF_FOR_CompE_Inputs_

typedef struct {
    Cstruct C[3];
    Istruct I;
    int M;
} CompE_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompE_Outputs_
#define DEFINED_TYPEDEF_FOR_CompE_Outputs_

typedef struct {
    bool isActive;
    int portGenPort;
} CompE_Outputs;

#endif
#endif