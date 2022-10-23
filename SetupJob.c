#include "macros_and_typedef.h"
#include "extern_global_variables.h"
#include "AllocArrays.h"
#include "InitCoords.h"
#include "InitVels.h"
#include "InitAccels.h"
#include "AccumProps.h"

void SetupJob()
{
  AllocArrays();
  stepCount = 0;
  InitCoords();
  InitVels();
  InitAccels();
  AccumProps(0);
}

