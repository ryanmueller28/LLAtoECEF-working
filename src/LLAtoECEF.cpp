/**
 * LLAtoECEF a program by Ryan Mueller
 * for the Sci-Tech technical assessment
 * This program reads in .csv files with the specified format of:
 * Time Since Last Unix Epoch, WGS84 Latitude, WGS84 Longitude, WGS84 altitude
 * */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "../include/WGS84Params.h"
#include "../include/LLA.h"
#include "../include/ECEF.h"


int main(int argc, char** argv)
{

    // Convert csv to file stream
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0]
                    << " dataFileName.csv " << std::endl;

        return EXIT_FAILURE;
    }
    // get input parameters from csv
    std::ifstream dataFile(argv[1]);
    std::string token;

    std::vector<ECEF> LLAsToConvert;

    if (dataFile.is_open())
    {
        while (dataFile.good())
        {
            for (int i = 0; i < 4; i++)
            {
                double deltaTime;
                double altitude;
                double longitude;
                double latitude;
                std::getline(dataFile, token, ',');

                if (i == 0)
                {
                    deltaTime = stod(token);
                }
                if (i == 1)
                {
                    latitude = stod(token);
                }
                if (i == 2)
                {
                    longitude = stod(token);
                }

                if (i == 3)
                {
                    altitude = stod(token);
                }

                ECEF tempECEF(deltaTime, latitude, longitude, altitude);

                LLAsToConvert.push_back(tempECEF);
            }
        }
    }

    for (int i = 0; i < LLAsToConvert.size(); i++)
    {
        LLAsToConvert[i].printCalculated();
    }

    // out put
    return EXIT_SUCCESS;
}