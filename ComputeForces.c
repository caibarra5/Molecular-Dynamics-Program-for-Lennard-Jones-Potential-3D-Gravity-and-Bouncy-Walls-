#include "macros_and_typedef.h"
#include "extern_global_variables.h"
#define GRAVITY_FACTOR 0.05
void ComputeForces(){

  VecR dr;
  real fcVal, rr, rrCut, rri, rri3;
  int j1, j2, n;
  
  rrCut = Sqr(rCut);
  DO_MOL VZero(mol[n].ra);

  uSum = 0.;
  virSum = 0.;
  for (j1 = 0; j1 < nMol - 1; j1++){
    for (j2 = j1+1; j2 < nMol; j2++){
     VSub(dr,mol[j1].r,mol[j2].r);
//     VWrapAll(dr);
     rr = VDot(dr,dr);
     if(rr < rrCut){
       rri = 1/rr;
       rri3 = Cube(rri);
       fcVal = 48 * rri3 * (rri3-0.5) * rri;
       VVSAdd(mol[j1].ra,fcVal,dr);
       VVSAdd(mol[j2].ra,-fcVal,dr);
       uSum += 4 * rri3 * (rri3 -1.) + 1.;
       virSum += fcVal * rr;
     }
    }
  }
  DO_MOL mol[n].ra.z -= GRAVITY_FACTOR*(mol[n].r.z+0.5*region.z);

}

