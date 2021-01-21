#pragma once

#define _USE_MATH_MACROS
#include <cmath>

/**
 * We declare a macro for long long double
 * 
 * */

/**
 * 
 * The constant WGSS84 Paramaters provided in the example resources
 * This in SCREAMING_SNAKE_CASE as they are constants that will be declared
 * as a const WGS84Params to be used in other files, and SCREAMING_SNAKE_CASE
 * makes sense to me for constants of this kind.
 * */
struct WGS84Params{
    long double SEMI_MAJOR_AXIS = 6378137;
    long double ELLIPSOID_FLATTENING = 1 / 298.257223563;
    long double SEMI_MINOR_AXIS_FLATTENING = SEMI_MAJOR_AXIS * (1 - ELLIPSOID_FLATTENING);
    long double SEMI_MINOR_AXIS_CONSTANT = 6356752.3124518;
    long double FIRST_ECCENTRICITY_CONSTANT = sqrt((pow(SEMI_MAJOR_AXIS, 2) - pow(SEMI_MINOR_AXIS_CONSTANT, 2) / pow(SEMI_MAJOR_AXIS, 2)));
    long double SECOND_ECCENTRICITY_CONSTANT = sqrt((pow(SEMI_MAJOR_AXIS, 2) - pow(SEMI_MINOR_AXIS_CONSTANT, 2) / pow(SEMI_MINOR_AXIS_CONSTANT, 2)));
    long double FIRST_ECCENTRICITY_FLATTENING = sqrt((pow(SEMI_MAJOR_AXIS, 2) - pow(SEMI_MINOR_AXIS_FLATTENING, 2) / pow(SEMI_MAJOR_AXIS, 2)));
    long double SECOND_ECCENTRICITY_FLATTENING = sqrt((pow(SEMI_MAJOR_AXIS, 2) - pow(SEMI_MINOR_AXIS_FLATTENING, 2) / pow(SEMI_MINOR_AXIS_FLATTENING, 2)));
};