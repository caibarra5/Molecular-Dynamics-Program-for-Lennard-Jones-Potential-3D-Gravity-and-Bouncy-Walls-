#include "extern_global_variables.h"
#include <stdio.h>
void GetNameList(FILE *fptr){
  fptr = fopen("parameters.txt","r");
  fscanf(fptr,"%lf",&deltaT);
  fscanf(fptr,"%lf",&density);
  fscanf(fptr,"%d",&initUcell.x);
  fscanf(fptr,"%d",&initUcell.y);
  fscanf(fptr,"%d",&initUcell.z);
  fscanf(fptr,"%d",&stepAvg);
  fscanf(fptr,"%d",&stepEquil);
  fscanf(fptr,"%d",&stepLimit);
  fscanf(fptr,"%lf",&temperature);
    fclose(fptr);
}

