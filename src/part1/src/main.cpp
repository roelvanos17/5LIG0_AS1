#include <iostream>
#include <chrono>

#include "../inc/siteconfiguration.h"
#include "../inc/mission.h"
#include "../inc/graph.h"
#include "../inc/hauler.h"
#include "../inc/dijkstra.h"

int main()
{
    Graph graph;
    SiteConfiguration site;
    Mission mission;

    std::string inputFolder = "../../examples/";
    std::string fileIdentifier = "";

    site.setFileName(inputFolder + fileIdentifier + "config.txt");
    mission.setMissionFileName(inputFolder + fileIdentifier + "mission.txt");
    mission.setOutputFileName(inputFolder + fileIdentifier + "output2.txt");

    site.readConfig();
    mission.readMission();

    hauler hauler1 = {0, std::vector<int>()};
    hauler hauler2 = {4, std::vector<int>()};

    auto tstart = std::chrono::high_resolution_clock::now();
    // ------------------------
    // Place your code here!
    Dijkstra dijkstra(graph);

    for(long unsigned int i = 0; i < mission.data[0].size(); i++) {
        int startRow;
        int startCol;





        int goalRow = site.getPointCoordinates(UNLOADING, 1).first;
        int goalCol = site.getPointCoordinates(UNLOADING, 1).first;



        if(i == 0) {
            startRow = site.init_haulers[0].first;
            startCol = site.init_haulers[0].second;

            dijkstra.run(
                    graph.toVertexNumber(startRow, startCol),
                    graph.toVertexNumber(goalRow, goalCol)
                    );
        } else {

        }
    }


    // ------------------------
    auto tend = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();

    // call the writing function here
    // example:
//    mission.completionTimes = {10, 15};
//    mission.makespan = 200;
//    mission.elapsedTime = elapsed_time;
//    mission.path = mission.data.front().front();
//
//    mission.writeResults();
    return 0;
}