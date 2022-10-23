#include "global_variables.h"
#include "GetNameList.h"
#include "SetParams.h"
#include "SetupJob.h"
#include "SingleStep.h"
#include <stdio.h>
#include <stdlib.h>
#include "VRand.h"
#include "PrintNameList.h"
#include "real.h"
#include "VRand.h"
#include <string.h>

int main (int argc, char **argv)
{
  FILE *fptr;
  GetNameList (fptr);
  PrintNameList ();


  SetParams();
  printf("\nSetParams() called\n");
  printf("rCut = %lf\n",rCut);
  printf("initUcell.x = %d\n",initUcell.x);
  printf("initUcell.y = %d\n",initUcell.y);
  printf("initUcell.z = %d\n",initUcell.z);
  printf("nMol = %d\n",nMol);
  printf("velMag = %lf\n",velMag);

  fptr = fopen("zs_region.txt","w");
  fprintf(fptr,"%lf\n",region.x);
  fprintf(fptr,"%lf\n",region.y);
  fprintf(fptr,"%lf",region.z);
  fclose(fptr);

  SetupJob();

  fptr = fopen("zw_InitCoords/0.0000","w");
  DO_MOL{
    fprintf(fptr,"%lf %lf %lf\n",(mol[n].r.x),(mol[n].r.y),(mol[n].r.z));  
  }
  fclose(fptr);


  double mag = 0;
  fptr = fopen("zx_InitVels/0","w");
  DO_MOL{
    mag = sqrt( Sqr(mol[n].rv.x) + Sqr(mol[n].rv.y) );
//    fprintf(fptr,"%lf %lf %lf\n",(mol[n].rv.x),(mol[n].rv.y),mag);  
    fprintf(fptr,"%lf %lf %lf\n",(mol[n].rv.x),(mol[n].rv.y),(mol[n].rv.z));  
  }
  fclose(fptr);


  fptr = fopen("zy_InitAccls/0","w");
  DO_MOL{
//    fprintf(fptr,"%lf %lf\n",(mol[n].ra.x),(mol[n].ra.y));  
    fprintf(fptr,"%lf %lf %lf\n",(mol[n].ra.x),(mol[n].ra.y),(mol[n].ra.z));  
  }
  fclose(fptr);

  printf("step    time    sum(v)  Eavg    Estd    KEavg   KEstd press.avg press.std\n");
  moreCycles = 1;

  char dir[20];
  char time[20];

  while (moreCycles==1){
    SingleStep();

  if (stepCount % 100 == 0){
  strcpy(dir,"zw_InitCoords/");
  snprintf(time,20,"%5.4f",timeNow);
  strcat(dir,time);
  fptr = fopen(dir,"w");
  DO_MOL{
//    fprintf(fptr,"%lf %lf\n",(mol[n].r.x),(mol[n].r.y));  
    fprintf(fptr,"%lf %lf %lf\n",(mol[n].r.x),(mol[n].r.y),(mol[n].r.z));  
  }
  }

    if (stepCount >= stepLimit) moreCycles = 0;
  }
  printf("step    time    sum(v)  Eavg    Estd    KEavg   KEstd press.avg press.std\n");

  return 0;
}

