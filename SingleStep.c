#include "macros_and_typedef.h"
#include "extern_global_variables.h"
#include "LeapfrogStep.h"
#include "ApplyBoundaryCond.h"
#include "ComputeForces.h"
#include "EvalProps.h"
#include "PrintSummary.h"
#include "AccumProps.h"

void SingleStep()
{
  ++ stepCount;
  timeNow = stepCount * deltaT;
  LeapfrogStep(1);
  ApplyBoundaryCond();
  ComputeForces();
  LeapfrogStep(2);
  EvalProps();
  AccumProps(1);
  if (stepCount % stepAvg == 0){
    AccumProps(2);
    PrintSummary(stdout);
    AccumProps(0);
  }
}

