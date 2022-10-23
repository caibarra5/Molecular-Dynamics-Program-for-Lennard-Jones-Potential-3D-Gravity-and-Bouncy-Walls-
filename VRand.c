#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "macros_and_typedef.h"
#include "extern_global_variables.h"

void VRand(VecR* p){
  
//  time_t t;
//  srand((unsigned) time(&t));
//  srand(time(NULL));
  
  double x,y,z,s;

  x = ((double) rand()/RAND_MAX);
  y = ((double) rand()/RAND_MAX); 
  z = ((double) rand()/RAND_MAX); 

  s = sqrt( x*x + y*y + z*z );

  p->x = x/s;
  p->y = y/s;
  p->z = z/s;
  
}


