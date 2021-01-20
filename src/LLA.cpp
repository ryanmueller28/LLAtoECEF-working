#include "../include/LLA.h"

LLA::LLA()
{

}

LLA::LLA(double dtUnixEpoch, double latitude, double longitude, double altitude)
{
    Latitude = latitude;
    Longitude = longitude;
    Altitude = altitude;
    TimeSinceEpoch = dtUnixEpoch;
}
