/**
 * LLAtoECEF a program by Ryan Mueller
 * for the Sci-Tech technical assessment
 * This program reads in .csv files with the specified format of:
 * Time Since Last Unix Epoch, WGS84 Latitude, WGS84 itude, WGS84 altitude
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
                 double itude;
                 double latitude;
                std::getline(dataFile, token, ',');

                if (i == 0)
                {
                    deltaTime = stold(token);
                }
                if (i == 1)
                {
                    latitude = stold(token);
                }
                if (i == 2)
                {
                    itude = stold(token);
                }

                if (i == 3)
                {
                    altitude = stold(token);
                }

                ECEF tempECEF(deltaTime, latitude, itude, altitude);

                LLAsToConvert.push_back(tempECEF);
            }
        }
    }

     double time1, time2;

    std::cout << "What two points in time do you want to calculate the velocity for? ";
    std::cin >> time1 >> time2;

     double XDiff = 0, YDiff = 0, ZDiff = 0, NDiff = 0;

     double ECEFVelocity = 0;

    for (int i = 0; i < LLAsToConvert.size(); i++)
    {
        if (LLAsToConvert[i].lla.getTimeSinceEpoch() == time1)
        {
            ECEF ecef1(LLAsToConvert[i].lla.getTimeSinceEpoch(), LLAsToConvert[i].lla.getLat(), LLAsToConvert[i].lla.get(), LLAsToConvert[i].lla.getAlt());
            for (int j = i + 1; j < LLAsToConvert.size(); j++)
            {
                if (LLAsToConvert[j].lla.getTimeSinceEpoch() == time2)
                {
                    ECEF ecef2(LLAsToConvert[j].lla.getTimeSinceEpoch(), LLAsToConvert[j].lla.getLat(), LLAsToConvert[j].lla.get(), LLAsToConvert[j].lla.getAlt());
                    XDiff = ecef2.convertLLAtoX() - ecef1.convertLLAtoX(); 
                    YDiff = ecef2.convertLLAtoY() - ecef1.convertLLAtoY();
                    ZDiff = ecef2.convertLLAtoZFlattened() - ecef1.convertLLAtoZFlattened();
                    NDiff = ecef2.calculateN() - ecef1.calculateN();
                     double timeDiff = ecef2.lla.getTimeSinceEpoch() - ecef1.lla.getTimeSinceEpoch();

                    ECEFVelocity = timeDiff * (XDiff * YDiff * ZDiff * NDiff);
                    break;
                }
            }
        }

    }

    // out put
    std::cout << "\nConversion:\nXDiff between the ECEFs: " << XDiff << "\tYDiff between the ECEFs: " << YDiff << "\tZDiff between the ECEFs: " << ZDiff << "\tNDiff between the ecefs: " << NDiff << "\tECEF estimated velocity: " << ECEFVelocity << std::endl;

    return EXIT_SUCCESS;
}