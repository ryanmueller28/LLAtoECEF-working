#include "../include/LLA.h"

LLA::LLA()
{

}

LLA::LLA( double dtUnixEpoch,  double latitude,  double itude,  double altitude)
{
    Latitude = latitude;
    itude = itude;
    Altitude = altitude;
    TimeSinceEpoch = dtUnixEpoch;
}
