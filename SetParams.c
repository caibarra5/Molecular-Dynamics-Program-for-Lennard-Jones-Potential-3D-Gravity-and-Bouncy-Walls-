#include "macros_and_typedef.h"
#include "extern_global_variables.h"
#include <math.h>
void SetParams()
{
  rCut = pow(2.,1./6.);
//  rCut = 3.;
  VSCopy(region, 1./sqrt(density),initUcell);
  nMol = VProd(initUcell);
  velMag = sqrt(NDIM * (1.-1./nMol) * temperature);
//  velMag = sqrt(NDIM * temperature);
}

