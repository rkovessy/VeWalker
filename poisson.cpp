#include "poisson.h"
#include "iostream"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "cmath"

poisson::poisson()
{

}

double poisson::createintervals(double lambda)
{
    L = pow(2.718,-lambda);
    k = 0;
    p = 1;

    do {

        double u = (double) rand()/(double) RAND_MAX;

        p = p*u;
        k++;

    } while ((p > L) && (k<100000));

    k = k-1;
    return k;
}
