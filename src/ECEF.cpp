#include "../include/ECEF.h"

ECEF::ECEF(LLA latlongalt)
{

}

ld ECEF::convertLLAtoX()
{
    X = params.SEMI_MAJOR_AXIS / (sqrt(1 - pow(M_E, 2) ))
}

ld ECEF::convertLLAtoY()
{

}

ld ECEF::convertLLAtoZ()
{

}