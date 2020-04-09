#include "all_sockets.h"
#include "all_components.h"

#ifndef DEFINED_TYPEDEF_FOR_COMPB_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPB_FULL_HEADER_

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_A_
#define DEFINED_TYPEDEF_FOR_A_

typedef struct
{
    int A_01;
    float A_02;
} Astruct;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_Iinternal_
#define DEFINED_TYPEDEF_FOR_Iinternal_

typedef struct
{
    int I_01_01;
    float I_01_02;
} Iinternal;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_I_
#define DEFINED_TYPEDEF_FOR_I_

typedef struct
{
    Iinternal I_01;
} Istruct;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompB_Inputs_
#define DEFINED_TYPEDEF_FOR_CompB_Inputs_

typedef struct
{
    Astruct A;
    double F;
    float H[5];
} CompB_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompB_Outputs_
#define DEFINED_TYPEDEF_FOR_CompB_Outputs_

typedef struct
{
    bool E;
    double G;
    Istruct I;
    bool isActive;
    int portGenPort;
} CompB_Outputs;

#endif
#endif
