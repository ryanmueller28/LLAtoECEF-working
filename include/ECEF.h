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
    ECEF(double Lat, double Long, double Alt, double deltaTime);

    double convertLLAtoX();
    double convertLLAtoY();
    double convertLLAtoZFlattened();
    double convertLLAtoZConstant();
    double calculateN();
/*
    used to test variables
    void printCalculated();
*/
private:
    WGS84Params params;
    LLA lla;
    double X, Y, Z, N, h;

    double sinSquaredLat(double lat);
    double squareRootNParams();
};