#include "../include/LLA.h"

LLA::LLA()
{

}

LLA::LLA(long double dtUnixEpoch, long double latitude, long double longitude, long double altitude)
{
    Latitude = latitude;
    Longitude = longitude;
    Altitude = altitude;
    TimeSinceEpoch = dtUnixEpoch;
}
