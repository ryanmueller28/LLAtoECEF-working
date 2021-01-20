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
    ECEF(ld Lat, ld Long, ld Alt, ld deltaTime, ld H);

    ld convertLLAtoX();
    ld convertLLAtoY();
    ld convertLLAtoZFlattened();
    ld convertLLAtoZConstant();
    ld calculateN();

private:
    WGS84Params params;
    LLA lla;
    ld X, Y, Z, N, h;

    

    ld sinSquaredLat(ld lat);
};