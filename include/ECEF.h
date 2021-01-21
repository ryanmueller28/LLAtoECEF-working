#pragma once
#include "WGS84Params.h"
#include "LLA.h"

/**
 * ECEF.h
 * This class uses and stores
 * The LLA parameters to ECEF parameters
 * Using WGS84 constants where necessary
 * */
class ECEF{
public:

    ECEF();
    ECEF(long double Lat, long double Long, long double Alt, long double deltaTime);

    void fullConversion();

    long double convertLLAtoX();
    long double convertLLAtoY();
    long double convertLLAtoZFlattened();
    long double convertLLAtoZConstant();
    long double calculateN();
    LLA lla;

    

private:
    WGS84Params params;
    long double X, Y, Z, N, h;

    long double sinSquaredLat(long double lat);
    long double squareRootNParams();
};