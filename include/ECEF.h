#pragma once
#include "WGS84Params.h"
#include "LLA.h"

class ECEF{
public:
    ECEF(LLA latlongalt);

    ld convertLLAtoX();
    ld convertLLAtoY();
    ld convertLLAtoZ();

private:
    WGS84Params params;
    LLA lla;
    ld X, Y, Z;

};