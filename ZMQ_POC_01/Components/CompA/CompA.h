#include "all_sockets.h"
#include "all_components.h"

#ifndef DEFINED_TYPEDEF_FOR_COMPA_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPA_FULL_HEADER_

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_A_
#define DEFINED_TYPEDEF_FOR_A_

typedef struct {
    int A_01;
    float A_02;
} Astruct;

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

#ifndef DEFINED_TYPEDEF_FOR_CompA_Inputs_
#define DEFINED_TYPEDEF_FOR_CompA_Inputs_

typedef struct {
} CompA_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompA_Outputs_
#define DEFINED_TYPEDEF_FOR_CompA_Outputs_

typedef struct {
    Astruct A;
    double B;
    Cstruct C[3];
    float D;
    bool isActive;
    int portGenPort;
} CompA_Outputs;

#endif
#endif

