#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "real.h"
#ifndef MACROS_AND_TYPEDEF
#define MACROS_AND_TYPEDEF

#define VAdd(v1, v2, v3)\
  (v1).x = (v2).x + (v3).x,\
  (v1).y = (v2).y + (v3).y,\
  (v1).z = (v2).z + (v3).z

#define VSAdd(v1,v2,s3,v3)\
  (v1).x = (v2).x + (s3)*(v3).x,\
  (v1).y = (v2).y + (s3)*(v3).y,\
  (v1).z = (v2).z + (s3)*(v3).z

#define VVSAdd(v1,s2,v2) VSAdd (v1,v1,s2,v2)

#define VVAdd(v1,v2) VAdd(v1,v1,v2)

#define VCSum(v)\
  ((v).x + (v).y + (v).z)

#define VSub(v1, v2, v3)\
  (v1).x = (v2).x - (v3).x,\
  (v1).y = (v2).y - (v3).y,\
  (v1).z = (v2).z - (v3).z



#define VDot(v1, v2)\
  ((v1).x*(v2).x + (v1).y*(v2).y + (v1).z*(v2).z)

#define VLenSq(v) VDot(v,v)



#define VSet(v,sx,sy,sz)\
  (v).x = (sx),\
  (v).y = (sy),\
  (v).z = (sz)

#define VSetAll(v,s) VSet(v,s,s,s)

#define VZero(v) VSetAll(v,0.)



#define VWrap(v, t)\
  if (v.t >= 0.5 * region.t) v.t -= region.t;\
  else if (v.t < -0.5 * region.t) v.t += region.t

#define VWrapAll(v)\
{VWrap(v,x);\
  VWrap(v,y);\
  VWrap(v,z);}

#define VSharpReflect(m,t,fu,fl)\
  if (m.r.t >= 0.49 * region.t) m.rv.t *= -fu;\
  else if (m.r.t < -0.49 * region.t) m.rv.t *=-fl

#define VSharpReflectAll(m)\
{VSharpReflect(m,x,0.01,0.01);\
  VSharpReflect(m,y,0.01,0.01);\
  VSharpReflect(m,z,0.01,0.01);}




#define Sqr(x) ((x)*(x))

#define Cube(x) ((x)*(x)*(x))

#define DO_MOL for(int n = 0; n < nMol; n++)

#define VMul(v1,v2,v3)\
  (v1).x = (v2).x * (v3).x,\
  (v1).y = (v2).y * (v3).y,\
  (v1).z = (v2).z * (v3).z

#define VDiv(v1,v2,v3)\
  (v1).x = (v2).x / (v3).x,\
  (v1).y = (v2).y / (v3).y,\
  (v1).z = (v2).z / (v3).z

#define VScale(v,s)\
  (v).x *= s,\
  (v).y *= s,\
  (v).z *= s

#define NDIM 3

#define AllocMem(a,n,t) a = (t*)malloc((n)*sizeof(t))

#define VSCopy(v2,s1,v1) \
(v2).x = (s1) * (v1).x,\
(v2).y = (s1) * (v1).y,\
(v2).z = (s1) * (v1).z

#define VProd(v) ((v).x * (v).y * (v).z)



#define PropZero(v)\
(v).sum = 0.,\
(v).sum2 = 0.

#define PropAccum(v)\
v.sum += (v).val,\
v.sum2 += Sqr((v).val)

#define PropAvg(v,n)\
(v).sum /= n,\
(v).sum2 = sqrt( Max( (v).sum2/n - Sqr((v).sum), 0. ) )

#define PropEst(v)\
  (v).sum, (v).sum2

#define Max(x1,x2)\
  (((x1) > (x2)) ? (x1):(x2))



typedef double real;
//typedef float real;

typedef struct {
real x, y, z;
} VecR;

typedef struct {
VecR r, rv, ra;
} Mol;

typedef struct {
  int x,y,z;
} VecI;

typedef struct {
  real val, sum, sum2;
} Prop;

#endif
