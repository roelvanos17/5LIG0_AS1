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
    std::vector<int> totalPath;

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
};



#endif //INC_5LIG0_AS1_DIJKSTRA_H
