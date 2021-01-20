#pragma once

#include "WGS84Params.h"

class LLA{

public:

    // Default empty constructor
    LLA();
   
    LLA(ld dtUnixEpoch, ld latitude, ld longitude, ld altitude);
    
    ld getLat(){ return Latitude; }
    ld getLong() { return Longitude; }
    ld getAlt() { return Altitude; }
    ld getTimeSinceEpoch() { return TimeSinceEpoch; }

private:

    ld Latitude;
    ld Longitude;
    ld Altitude;
    ld TimeSinceEpoch;
};