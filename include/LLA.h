#pragma once

#include "WGS84Params.h"

class LLA{

public:

    LLA(ld latitude, ld longitude, ld altitude);
    
    ld getLat(){ return Latitude; }
    ld getLong() { return Longitude; }
    ld getAlt() { return Altitude; }

private:

    ld Latitude;
    ld Longitude;
    ld Altitude;
};