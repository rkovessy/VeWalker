#ifndef POISSON_H
#define POISSON_H

#include "poisson.h"
#include "iostream"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmath"

class poisson
{
public:

    poisson();
    double createintervals(double lambda);
    double k;

private:

    double lambda;
    double L;
    double p;

};

#endif


