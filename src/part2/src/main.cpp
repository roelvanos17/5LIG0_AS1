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

    std::string inputFolder = "";
    std::string fileIdentifier = "";

    site.setFileName(inputFolder + fileIdentifier + "config.txt");
    mission.setMissionFileName(inputFolder + fileIdentifier + "mission.txt");
    mission.setOutputFileName(inputFolder + fileIdentifier + "output.txt");

    site.readConfig();
    mission.readMission();

    hauler hauler1 = {0, std::vector<int>()};
    hauler hauler2 = {4, std::vector<int>()};

    auto tstart = std::chrono::high_resolution_clock::now();
    // ------------------------
    // Place your code here!
    for(long unsigned int i = 0; i < site.SO_positions.size(); i++) {
        unsigned int row =  site.getPointCoordinates(STATIC_OBJECT,i).first - 1;
        unsigned int col =  site.getPointCoordinates(STATIC_OBJECT,i).second - 1;

        graph.removeGridCell(row, col);
    }

    Dijkstra dijkstra(graph);

    for(long unsigned int i = 0; i < mission.data[0].size(); i++) {
        unsigned int startRow;
        unsigned int startCol;
        unsigned int goalRow;
        unsigned int goalCol;
        int pointNum = mission.data[0][i][1] - '0';

        if (mission.data[0][i].find('U') != std::string::npos) {
            goalRow = site.getPointCoordinates(UNLOADING, pointNum).first;
            goalCol = site.getPointCoordinates(UNLOADING, pointNum).second;
        } else if (mission.data[0][i].find('L') != std::string::npos) {
            goalRow = site.getPointCoordinates(LOADING, pointNum).first;
            goalCol = site.getPointCoordinates(LOADING, pointNum).second;
        }

        if (i == 0) {
            startRow = site.getPointCoordinates(START, 1).first;
            startCol = site.getPointCoordinates(START, 1).second;

            // Dijkstra uses 0 - 11 rows instead of 1 - 12, so subtract 1
            dijkstra.run(
                    Graph::toVertexNumber(startRow - 1, startCol - 1),
                    Graph::toVertexNumber(goalRow - 1, goalCol - 1)
            );
        } else {
            dijkstra.run(
                    dijkstra.totalPath.back(),
                    Graph::toVertexNumber(goalRow - 1, goalCol - 1)
            );
        }
    }

    // ------------------------
    auto tend = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();

    // call the writing function here
    mission.completionTimes = {(unsigned int)dijkstra.totalPath.size() - 1};
    mission.makespan = mission.completionTimes[0];
    mission.elapsedTime = elapsed_time;
    mission.path = Mission::createPathString(dijkstra.totalPath);

    mission.writeResults();
    return 0;
}