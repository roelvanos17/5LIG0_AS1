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

    auto tstart = std::chrono::high_resolution_clock::now();
    // ------------------------
    // Place your code here!

    // Remove all Static Object vertices from the Adjacency Matrix
    for(long unsigned int i = 0; i < site.SO_positions.size(); i++) {
        unsigned int row =  site.getPointCoordinates(STATIC_OBJECT,i).first - 1;
        unsigned int col =  site.getPointCoordinates(STATIC_OBJECT,i).second - 1;

        graph.removeGridCell(row, col);
    }


    // Run Dijkstra's Algorithm for all path segments
    Dijkstra dijkstra(graph, site);

    for(unsigned int j = 0; j < site.n_Hauler; j++) {
        dijkstra.setIteration(j);

        for (long unsigned int i = 0; i < mission.data[j].size(); i++) {
            unsigned int startRow;
            unsigned int startCol;
            unsigned int goalRow;
            unsigned int goalCol;

            int pointNum = mission.data[j][i][1] - '0';

            if (mission.data[j][i].find('U') != std::string::npos) {
                goalRow = site.getPointCoordinates(UNLOADING, pointNum).first;
                goalCol = site.getPointCoordinates(UNLOADING, pointNum).second;
            } else if (mission.data[j][i].find('L') != std::string::npos) {
                goalRow = site.getPointCoordinates(LOADING, pointNum).first;
                goalCol = site.getPointCoordinates(LOADING, pointNum).second;
            }

            if (i == 0) {
                startRow = site.getPointCoordinates(START, j).first;
                startCol = site.getPointCoordinates(START, j).second;

                // Dijkstra uses 0 - 11 rows instead of 1 - 12, so subtract 1
                dijkstra.run(
                        Graph::toVertexNumber(startRow - 1, startCol - 1),
                        Graph::toVertexNumber(goalRow - 1, goalCol - 1)
                );
            } else {
                dijkstra.run(
                        dijkstra.totalPath[j].back(),
                        Graph::toVertexNumber(goalRow - 1, goalCol - 1)
                );
            }
        }
    }
    // ------------------------
    auto tend = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart).count();

    mission.completionTimes = std::vector<unsigned int>(site.n_Hauler);

    // call the writing function here
    for(unsigned long i = 0; i < site.n_Hauler; i++) {
        mission.completionTimes[i] = (unsigned int)dijkstra.totalPath[i].size() - 1;
        mission.makespan = mission.makespan > mission.completionTimes[i]? mission.makespan : mission.completionTimes[i];
    }
    mission.elapsedTime = elapsed_time;
    mission.path = Mission::createPathString(dijkstra.totalPath, mission.makespan);

    mission.writeResults();
    return 0;
}