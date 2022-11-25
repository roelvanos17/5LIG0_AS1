//
// Created by roelv on 21/11/2022.
//

#ifndef INC_5LIG0_AS1_DIJKSTRA_H
#define INC_5LIG0_AS1_DIJKSTRA_H

#include <vector>
#include "../inc/hauler.h"
#include "../inc/graph.h"

class Dijkstra {
public:
    explicit Dijkstra(Graph graph);
    void printPath(unsigned int goalVertex);
    void run(unsigned int pStartPosition, unsigned int pGoal);
    void reset();

private:
    int getClosestVertex();
    int shortestDistance;
    void updateDistances(unsigned int pClosestVertex);
    Graph graph;
    std::vector<unsigned int> distance;
    std::vector<int> path;
    std::vector<bool> visitedVertex;
    void printNextStep(int vertexNumber);
    unsigned int startPosition{};
};



#endif //INC_5LIG0_AS1_DIJKSTRA_H
