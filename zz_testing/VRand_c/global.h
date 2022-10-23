#define VAdd(v1, v2, v3)\
  (v1).x = (v2).x + (v3).x,\
  (v1).y = (v2).y + (v3).y

#define VSub(v1, v2, v3)\
  (v1).x = (v2).x - (v3).x,\
  (v1).y = (v2).y - (v3).y

#define VDot(v1, v2)\
  ((v1).x*(v2).x + (v1).y*(v2).y)

#define VSAdd(v1,v2,s3,v3)\
  (v1).x = (v2).x + (s3)*v3.x,\
  (v1).y = (v2).y + (s3)*v3.y

#define VSet(v,sx,sy)\
  (v).x = sx,\
  (v).y = sy

#define VSetAll(v,s) VSet(v,s,s)

#define VZero(v) VSetAll(v,0)

#define VVSAdd(v1,s2,v2) VSAdd (v1,v1,s2,v2)

#define VLenSq(v) VDot(v,v)

#define VWrap(v, t)\
  if (v.t >= 0.5 * region.t) v.t -= region.t;\
  else if (v.t < -0.5 * region.t) v.t += region.t

#define VWrapAll(v)\
{VWrap(v,x);\
  VWrap(v,y);}

#define Sqr(x) ((x)*(x))

#define Cube(x) ((x)*(x)*(x))

#define DO_MOL for(n = 0; n < nMol; n++)

#define VMul(v1,v2,v3)\
  (v1).x = (v2).x * (v3).x,\
  (v1).y = (v2).y * (v3).y

#define VDiv(v1,v2,v3)\
  (v1).x = (v2).x / (v3).x,\
  (v1).y = (v2).y / (v3).y

#define VScale(v,s)\
  v.x *= s,\
  v.y *= s

#define VVAdd(v1,v2) VAdd(v1,v1,v2)

#define NDIM 2

#define AllocMem(a,n,t) a = (t*)malloc((n)*(sizeof(t))

#define VSCopy(v2,s1,v1) \
(v2).x = (s1) * (v1).x,\
(v2).y = (s1) * (v1).y

#define VProd(v) ((v).x * (v).y)

#define PropZero(v)\
v.sum = 0.,\
v.sum2 = 0.

#define PropAccum(v)\
v.sum += v.val,\
v.sum2 += Sqr(v.val)

#define PropAvg(v)\
v.sum /= n,\
v.sum2 /= sqrt(Max(v.sum2/n - Sqr(v.sum),0.))

#define PropEst(v)\
  v.sum, v.sum2

typedef double real;

typedef struct {
real x, y;
} VecR;

typedef struct {
VecR r, rv, ra;
} Mol;

typedef struct {
  int x,y;
} VecI;

typedef struct {
  real val, sum, sum2;
} Prop;
