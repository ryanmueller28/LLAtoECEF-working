#include "../include/LLA.h"

LLA::LLA()
{

}

LLA::LLA(ld dtUnixEpoch, ld latitude, ld longitude, ld altitude)
{
    Latitude = latitude;
    Longitude = longitude;
    Altitude = altitude;
    TimeSinceEpoch = dtUnixEpoch;
}