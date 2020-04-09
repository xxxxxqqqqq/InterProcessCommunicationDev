#include "all_sockets.h"
#include "all_components.h"

#ifndef DEFINED_TYPEDEF_FOR_COMPF_FULL_HEADER_
#define DEFINED_TYPEDEF_FOR_COMPF_FULL_HEADER_

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompF_Inputs_
#define DEFINED_TYPEDEF_FOR_CompF_Inputs_

typedef struct {
} CompF_Inputs;

#endif

////////////////////////////////////////////////////

#ifndef DEFINED_TYPEDEF_FOR_CompF_Outputs_
#define DEFINED_TYPEDEF_FOR_CompF_Outputs_

typedef struct {
    bool isActive;
    int portGenPort;
} CompF_Outputs;

#endif
#endif