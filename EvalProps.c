#include "macros_and_typedef.h"
#include "extern_global_variables.h"
#include "real.h"
void EvalProps()
{
  real vv;

  VZero(vSum);
  vvSum = 0;
  DO_MOL{
    VVAdd(vSum, mol[n].rv);
    vv = VLenSq(mol[n].rv);
    vvSum = vvSum + vv;
  }

kinEnergy.val = 0.5 * vvSum / nMol;
totEnergy.val = kinEnergy.val + uSum/nMol;
pressure.val = density * (vvSum + virSum) / (nMol * NDIM);

}

