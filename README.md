# LLAtoECEF Solution by Ryan Mueller for SciTech Technical Assessment

## This program is designed to convert WGS84 Latitude, Longitude, and Altitude into ECEF coordinates and calculate velocity based on time between UNIX epochs. See reasoning for structure and execution decisions below

## To generate the Makefile to compile
It is preferred to call CMake in the build folder using the recursive 
backtrace command: ```CMake ..```. The purpose of the build folder is
to keep the project organized and to ensure that the project output is 
placed in its own folder.

## Once the Makefile is generated
In the build folder, simply type ```make``` and the program will be
constructed into the proper format in the build folder.

## To Execute the program
The program uses two parameters in the command line. The name of the program:
```LLAtoECEF``` and the name and path of the CSV file to run.

## Reasoning for structure
### The program's class design
I designed the program from the WGS84 constants upward. Given the constants in the provided PDF resource,
I built a struct for those constants. Latitude, Longitude, and Altitude (LLA), and Earth-Centered, Earth-Fixed(ECEF)
were each given separate classes to calculate their individual parameters. There was simply a large amount of
incoming data with the parameters of: Unix Epoch Time, Latitude, Longitude, and Altitude that I decided having
a class of the data would work well, so that a data structure such as a Vector or List could store class objects.

### Reason for command line argument for CSV file
This decision was made because it allows for reading of other CSV files in the same formatting by passing
the argument through the command line parameter. Instead of using a path variable constant, it allows different CSV files
to be read in.