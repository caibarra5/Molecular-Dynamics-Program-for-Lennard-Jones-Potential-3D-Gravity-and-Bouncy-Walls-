#include "global.h"
#include "VRand.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int main(){

  VecR p;

  VRand(&p);

  printf("%lf \n",p.x);
  printf("%lf \n",p.y);
  printf("%lf \n",pow(p.x,2)+pow(p.y,2));


  return 0;
}

