#ifndef MATH_UTILS_H
#define MATH_UTILS_H

class MathUtils {
    public:
        // generate a normally distributed random number using Box-Muller transform
        static double randomNormal(double mean, double stddev);

        // future: derivative(), integrate(), etc.
};

#endif // MATH_UTIL_H