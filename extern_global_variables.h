#include "macros_and_typedef.h"
#include "real.h"
#ifndef EXTERN_GLOBAL_VARIABLES
#define EXTERN_GLOBAL_VARIABLES

extern Mol *mol;
extern VecR region, vSum;
extern VecI initUcell;
extern Prop kinEnergy, pressure, totEnergy;
extern real deltaT, density, rCut, temperature, timeNow, uSum, velMag, virSum, vvSum;
extern int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;


#endif
