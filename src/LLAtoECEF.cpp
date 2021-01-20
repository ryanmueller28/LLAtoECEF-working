/**
 * LLAtoECEF a program by Ryan Mueller
 * for the Sci-Tech technical assessment
 * This program reads in .csv files with the specified format of:
 * Time Since Last Unix Epoch, WGS84 Latitude, WGS84 Longitude, WGS84 altitude
 * */
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "../include/WGS84Params.h"
#include "../include/LLA.h"
#include "../include/ECEF.h"


int main(int argc, char** argv)
{
    
    // Convert csv to file stream
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] <<
                    << " dataFileName.csv " << std::endl;

        return EXIT_FAILURE;
    }
    // get input parameters from csv

    // run functions

    // out put
    return EXIT_SUCCESS;
}