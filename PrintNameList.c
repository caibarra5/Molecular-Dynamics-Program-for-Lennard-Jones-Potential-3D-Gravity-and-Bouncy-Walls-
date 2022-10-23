#include "extern_global_variables.h"
#include <stdio.h>

void PrintNameList(){
  printf("delta T = %lf\n",deltaT);
  printf("density = %lf\n",density);
  printf("initUcell = %d %d %d\n",initUcell.x,initUcell.y,initUcell.z);
  printf("stepAvg = %d\n",stepAvg);
  printf("step Equil = %d\n",stepEquil);
  printf("stepLimit = %d\n",stepLimit);
  printf("temperature = %lf\n",temperature);
}

