//
// Created by roelv on 21/11/2022.
//
#include <iostream>

#include "../inc/dijkstra.h"

Dijkstra::Dijkstra(Graph pGraph) {
    graph = pGraph;
    visitedVertex = std::vector<bool>(Graph::nVertices);
    distance = std::vector<unsigned int>(Graph::nVertices);
    path = std::vector<int>(Graph::nVertices);
}

void Dijkstra::reset() {
    for (int i = 0; i < Graph::nVertices; i++) {
        visitedVertex[i] = false;

        if(i != startPosition){
            distance[i] = INT32_MAX;
        } else {
            distance[i] = 0;
            path[i] = -1;
        }
    }
}

void Dijkstra::run(unsigned int pStartPosition, unsigned int pGoal) {
    startPosition = pStartPosition;

    reset();

    for (int i = 0; i < Graph::nVertices; i++) {
        int closestVertex = getClosestVertex();

        visitedVertex[closestVertex] = true;

        updateDistances(closestVertex);
    }

    printPath(pGoal);
}

int Dijkstra::getClosestVertex() {
    shortestDistance = INT32_MAX;
    int closestVertex;

    for (int i = 0; i < Graph::nVertices; i++) {
        if (!visitedVertex[i] && distance[i] < shortestDistance) {
            closestVertex = i;
            shortestDistance = distance[i];
        }
    }

    return closestVertex;
}

void Dijkstra::updateDistances(unsigned int pClosestVertex) {
    for (int i = 0; i < Graph::nVertices; i++) {
        if(graph.adjacencyMatrix[pClosestVertex][i] && (shortestDistance + 1 < distance[i])) {
            path[i] = pClosestVertex;
            distance[i] = shortestDistance + 1;
        }
    }
}


void Dijkstra::printPath(unsigned int goalVertex) {
    std::cout << "Distance: " << distance[goalVertex] << "\t\t";
    std::cout << "Path: ";
    printNextStep(goalVertex);
    std::cout << "\n";
}


void Dijkstra::printNextStep(int pVertexNumber) {
    /**
     * TODO: Remove
     */
    if (pVertexNumber == -1) {
        return;
    }
    printNextStep(path[pVertexNumber]);
    std::cout << pVertexNumber << " ";
}