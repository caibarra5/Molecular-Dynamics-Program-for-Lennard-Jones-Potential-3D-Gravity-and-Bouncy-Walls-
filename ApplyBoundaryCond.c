#include "macros_and_typedef.h"
#include "extern_global_variables.h"
void ApplyBoundaryCond(){
//  DO_MOL VWrapAll (mol[n].r);
    DO_MOL VSharpReflectAll(mol[n]);
}

