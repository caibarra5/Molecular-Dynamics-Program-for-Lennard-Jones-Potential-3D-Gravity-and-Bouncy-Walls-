#include "macros_and_typedef.h"
#include "real.h"
#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

Mol *mol = NULL;
VecR region, vSum;
VecI initUcell;
Prop kinEnergy, pressure, totEnergy;
real deltaT, density, rCut, temperature, timeNow, uSum, velMag, virSum, vvSum;
int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;


#endif
