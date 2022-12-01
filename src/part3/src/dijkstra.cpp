//
// Created by roelv on 21/11/2022.
//
#include <iostream>

#include "../inc/dijkstra.h"

Dijkstra::Dijkstra(Graph pGraph, SiteConfiguration pSite) {
    graph = pGraph;
    visitedVertex = std::vector<bool>(Graph::nVertices);
    distance = std::vector<unsigned int>(Graph::nVertices);
    origin = std::vector<int>(Graph::nVertices);
    totalPath = std::vector<std::vector<int>>(pSite.n_Hauler);

    for(auto & i : totalPath) {
        i.insert(i.end(), 0);
    }
}

void Dijkstra::reset() {
    for (int i = 0; i < Graph::nVertices; i++) {
        visitedVertex[i] = false;

        if((unsigned) i != startPosition){
            distance[i] = INT32_MAX;
        } else {
            distance[i] = 0;
            origin[i] = -1;
        }
    }

    totalPath[iteration].pop_back();
}

void Dijkstra::run(unsigned int pStartPosition, unsigned int pGoal) {

    startPosition = pStartPosition;

    reset();

    for (int i = 0; i < Graph::nVertices; i++) {
        int closestVertex = getClosestVertex();

        if(closestVertex != -1) {
            visitedVertex[closestVertex] = true;

            updateDistances(closestVertex);
        }
    }

    printPath(pGoal);
}

/**
 * Function for determining the closest vertex to explore
 *
 * @return closestVertex to update distance
 * @return -1 when all conncected vertices are explored
 */
int Dijkstra::getClosestVertex() {
    shortestDistance = INT32_MAX;
    int closestVertex = -1;

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
            origin[i] = pClosestVertex;
            distance[i] = shortestDistance + 1;
        }
    }
}


void Dijkstra::printPath(unsigned int goalVertex) {
//    std::cout << "Distance: " << distance[goalVertex] << "\t\t";
//    std::cout << "Path: ";
    printNextStep(goalVertex);
//    std::cout << "\n";
}


void Dijkstra::printNextStep(int pVertexNumber) {
    if (pVertexNumber == -1) {
        return;
    }
    printNextStep(origin[pVertexNumber]);
//    std::cout << pVertexNumber << " ";
    totalPath[iteration].insert(totalPath[iteration].end(), pVertexNumber);
}

void Dijkstra::setIteration(unsigned int pIteration) {
    iteration = pIteration;
}

