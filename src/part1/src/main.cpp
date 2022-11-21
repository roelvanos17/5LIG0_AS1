#include <iostream>
#include <chrono>

#include "../inc/siteconfiguration.h"
#include "../inc/mission.h"

int main()
{
    SiteConfiguration site;
    Mission mission;
    /*
    Replace your input files location and name.

    functions:
        read_config     -> input: config file name
                        -> output: all variables in config file
                        NOTICE: the cordinates defined as a std::pair (look at the bellow example)
                        example:
                            if you want the x position of second LP:
                                 LP_positions[1].first
                            similarly, if you want the y position of second LP:
                                 LP_positions[1].second



        read_mission    -> input: mission file name
                        -> output: mission for each hauler
                        example:
                            if you want second goal of second hauler:
                                mission[1][1]
                                
        
        write_output    -> input: scenario makespan, completion time of each hauler, elapsed time of program,
                                     path to the final points, output file name
                        -> output: void
    */
    site.setFileName("../../examples/config.txt");
    site.readConfig();

    mission.setMissionFileName("../../examples/mission.txt");
    mission.setOutputFileName("../../examples/output2.txt");
    mission.readMission();

    auto tstart = std::chrono::high_resolution_clock::now();
    // ------------------------
    // Place your code here!

    std::cout << "SO : " << site.n_SO << "\n";

    // ------------------------
    auto tend = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();

    // call the writing function here
    // example:
    mission.completionTimes = {10, 15};
    mission.makespan = 200;
    mission.elapsedTime = elapsed_time;
    mission.path = mission.data.front().front();

    mission.writeResults();
    return 0;
}