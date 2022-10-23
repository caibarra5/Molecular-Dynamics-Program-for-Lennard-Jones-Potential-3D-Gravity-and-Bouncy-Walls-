#include "macros_and_typedef.h"
#include "extern_global_variables.h"
void InitCoords(){
  VecR c,gap;
  int n,nx,ny,nz;

  VDiv (gap,region,initUcell);
  n = 0;
  for(nz = 0; nz < initUcell.z; nz++){
    for (ny = 0; ny < initUcell.y; ny++){
      for(nx = 0; nx < initUcell.x; nx++){
       VSet(c,0.5+nx,0.5+ny,0.5+nz);
       VMul(c,c,gap);
       VVSAdd(c,-0.5,region);
       mol[n].r = c;
       ++n;
      }
    }
  }
}

