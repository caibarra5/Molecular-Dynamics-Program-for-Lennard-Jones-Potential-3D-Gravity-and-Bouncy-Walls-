#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "global.h"

void VRand(VecR* p){
  
  time_t t;
  srand((unsigned) time(&t));

  (*p).x = ((double) rand()/RAND_MAX);
  (*p).y = sqrt( 1 - pow((*p).x,2) ); 

  
}


