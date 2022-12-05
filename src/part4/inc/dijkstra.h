//
// Created by roelv on 21/11/2022.
//

#ifndef INC_5LIG0_AS1_DIJKSTRA_H
#define INC_5LIG0_AS1_DIJKSTRA_H

#include <vector>
#include "../inc/hauler.h"
#include "../inc/graph.h"
#include "../inc/siteconfiguration.h"


class Dijkstra {
public:
    explicit Dijkstra(Graph graph, SiteConfiguration pSite);
    void printPath(unsigned int goalVertex);
    void run(unsigned int pStartPosition, unsigned int pGoal);
    void reset();
    void setIteration(unsigned int pIteration);
    std::vector<std::vector<int>> totalPath;
    void removeCollisions();


private:
    int getClosestVertex();
    unsigned int shortestDistance;
    void updateDistances(unsigned int pClosestVertex);
    Graph graph;
    std::vector<unsigned int> distance;
    std::vector<bool> visitedVertex;
    void printNextStep(int vertexNumber);
    unsigned int startPosition{};
    std::vector<int> origin;
    unsigned int iteration;

    bool checkSwap(uint pPathId1, uint pPathId2, uint pStartIndex1, uint pStartIndex2);
    bool checkCollision(uint pPathId1, uint pPathId2, uint pStartIndex1, uint pStartIndex2);
    void insertWait(uint pPathId, uint pIndex);
};



#endif //INC_5LIG0_AS1_DIJKSTRA_H
