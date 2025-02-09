#include "MathUtils.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <numbers>

double MathUtils::randomNormal(double mean, double stddev) {
    double u1 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 1.0);
    double z  = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mean + stddev * z;
}