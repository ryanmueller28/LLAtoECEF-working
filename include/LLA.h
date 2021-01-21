#pragma once

#include <iostream>
#include "WGS84Params.h"


class LLA{

public:

    // Default empty constructor
    LLA();
   
    LLA(long double dtUnixEpoch, long double latitude, long double longitude, long double altitude);
    
    long double getLat(){ return Latitude; }
    long double getLong() { return Longitude; }
    long double getAlt() { return Altitude; }
    long double getTimeSinceEpoch() { return TimeSinceEpoch; }

private:

    long double Latitude;
    long double Longitude;
    long double Altitude;
    long double TimeSinceEpoch;
};