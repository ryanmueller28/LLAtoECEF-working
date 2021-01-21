#include "../include/ECEF.h"

/**
 * Empty constructor for declaration
 * */
ECEF::ECEF()
{

}
/**
 * Constructor
 * @param - Lat, long long double latitude
 * @param - Long, long long double longitude
 * @param - Alt, long long double altitude
 * @param - deltaTime, time since last unix epoch
 * @param - H, long long double height
 * set lla class parameter to LLA constructor
 * and set h class parameter to constructor function parameter
 * */
ECEF::ECEF(long double Lat, long double Long, long double Alt, long double deltaTime)
{
    lla = LLA(Lat, Long, Alt, deltaTime);
    h = Alt;
}

long double ECEF::convertLLAtoX()
{
    /**
     * Calculate the X ECEF by getting N and calculating constants
     * From LLA and WGS84 Params 
     * */
    X = (N + h) * cos(lla.getLat()) * cos(lla.getLong());
    return X;
}

long double ECEF::convertLLAtoY()
{
    /**
     * Calculate the Y ECEF by getting N and calculating constants
     * From LLA and WGS84 Params 
     * */
    Y = (N + h) * cos(lla.getLat()) * sin(lla.getLong());
    return Y;
}

long double ECEF::convertLLAtoZFlattened()
{
    /**
     * Convert Z using the flattened semi minor axis
     * */
    Z = ((pow(params.SEMI_MINOR_AXIS_FLATTENING, 2) / pow(params.SEMI_MAJOR_AXIS, 2)) * sin(lla.getLat()));
    return Z;
}

long double ECEF::convertLLAtoZConstant()
{   
   /**
    * Convert Z using semi minor axis constant
    * */ 
    Z = ((pow(params.SEMI_MINOR_AXIS_CONSTANT, 2) / pow(params.SEMI_MAJOR_AXIS, 2)) * sin(lla.getLat()));
    return Z;
}

long double ECEF::calculateN()
{
    /**
     * Get radius of curvate using
     * a / square root (1 - e ^ 2 sin ^ 2 latitude)
     * */
    
    N = params.SEMI_MAJOR_AXIS / (sqrt(squareRootNParams()));
    return N;
}

long double ECEF::squareRootNParams()
{
    // Feels hacky to return the inverse, but it's a negative number otherwise and sqrt a negative number returns -NAN
    return -(1 - pow(M_E, 2) * sinSquaredLat(lla.getLat()));
}

long double ECEF::sinSquaredLat(long double lat)
{
    long double tmp = sin(lat);
    return tmp * tmp;
}

void ECEF::fullConversion()
{
    N = calculateN();
    X = convertLLAtoX();
    Y = convertLLAtoY();
    Z = convertLLAtoZFlattened();
}