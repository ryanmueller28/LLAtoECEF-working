#pragma once

#include <iostream>
#include "WGS84Params.h"


class LLA{

public:

    // Default empty constructor
    LLA();
   
    LLA(double dtUnixEpoch, double latitude, double longitude, double altitude);
    
    double getLat(){ return Latitude; }
    double getLong() { return Longitude; }
    double getAlt() { return Altitude; }
    double getTimeSinceEpoch() { return TimeSinceEpoch; }

private:

    double Latitude;
    double Longitude;
    double Altitude;
    double TimeSinceEpoch;
};