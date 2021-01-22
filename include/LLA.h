#pragma once

#include <iostream>
#include "WGS84Params.h"


class LLA{

public:

    // Default empty constructor
    LLA();
   
    LLA( double dtUnixEpoch,  double latitude,  double itude,  double altitude);
    
     double getLat(){ return Latitude; }
     double get() { return itude; }
     double getAlt() { return Altitude; }
     double getTimeSinceEpoch() { return TimeSinceEpoch; }

private:

     double Latitude;
     double itude;
     double Altitude;
     double TimeSinceEpoch;
};