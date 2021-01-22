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
    ECEF( double Lat,  double ,  double Alt,  double deltaTime);

    void fullConversion();

     double convertLLAtoX();
     double convertLLAtoY();
     double convertLLAtoZFlattened();
     double convertLLAtoZConstant();
     double calculateN();
    LLA lla;

    

private:
    WGS84Params params;
     double X, Y, Z, N, h;

     double sinSquaredLat( double lat);
     double squareRootNParams();
};