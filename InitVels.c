#include "macros_and_typedef.h"
#include "VRand.h"
#include "extern_global_variables.h"
#include <time.h>

void InitVels(){
  VZero(vSum);

  srand(time(NULL));
  DO_MOL{
    VRand(&mol[n].rv);
    VScale(mol[n].rv,velMag);
    VVAdd(vSum,mol[n].rv);
  }

  DO_MOL VVSAdd(mol[n].rv,-1./nMol,vSum);
}

