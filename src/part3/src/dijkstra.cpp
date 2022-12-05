//
// Created by roelv on 21/11/2022.
//
#include <iostream>
#include <algorithm>

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

void Dijkstra::removeCollisions() {
    std::vector<std::pair<unsigned long, unsigned int>> pathSize =  std::vector<std::pair<unsigned long, unsigned int>>(totalPath.size());

    for (unsigned long i = 0; i < totalPath.size(); i++) {
        pathSize[i] = {totalPath[i].size(), i};

//        std::cout << "Path size Hauler " << i << ": " << totalPath[i].size() << "\n";
    }

    std::sort(pathSize.begin(), pathSize.end());

    // TODO: Remove
//    std::cout << "Path size Order Haulers: ";
//    for (std::pair<unsigned long, unsigned int> i: pathSize) {
//        std::cout << i.second << " - " << i.first << "\n";
//    }

//    for (unsigned long i = 0; i < pathSize[pathSize.size()-1].first; i++) {
//            std::cout << i <<", " << totalPath[0][i] << " , " << totalPath[1][i] << " , " << totalPath[2][i] << "\n";
//    }


    int start = 0;
    bool updateNeeded = false;
    for (unsigned long i = start; i < pathSize[pathSize.size()-1].first; i++) {
        for (unsigned long j = 0; j < pathSize.size(); j++) {
            if (j == 0 && i < pathSize[j].first-1 && i < pathSize[pathSize.size() - 1].first-1) {
                if (checkCollision(pathSize[j].second, pathSize[pathSize.size() - 1].second, i, i)) {
//                    std::cout << "Collision! at line: " << i + 1 << " between haulers " << pathSize[j].second + 1
//                              << ", " << pathSize[pathSize.size() - 1].second + 1 << "\n";

                    insertWait(pathSize[j].second, i);
                    pathSize[j].first++;
                    updateNeeded = true;
                }
            } else if (totalPath.size() > 2 && i < pathSize[j-1].first-1 && i < pathSize[j].first-1) {
                if (checkCollision(pathSize[j - 1].second, pathSize[j].second, i, i)) {
//                    std::cout << "Collision! at line: " << i + 1 << " between haulers " << pathSize[j - 1].second + 1
//                              << ", " << pathSize[j].second + 1 << "\n";

                    insertWait(pathSize[j - 1].second, i);
                    pathSize[j].first++;
                    updateNeeded = true;
                }
            }
        }

        if (updateNeeded) {
            std::sort(pathSize.begin(), pathSize.end());
            updateNeeded = false;
        }
    }
}




bool Dijkstra::checkSwap(uint pPathIndex1, uint pPathIndex2, uint pStartIndex1, uint pStartIndex2){
    uint startPoint1 = totalPath[pPathIndex1][pStartIndex1];
    uint startPoint2 = totalPath[pPathIndex2][pStartIndex2];
    uint endPoint1 = totalPath[pPathIndex1][pStartIndex1+1];
    uint endPoint2 = totalPath[pPathIndex2][pStartIndex2+1];

    if (startPoint1 == endPoint2 && startPoint2 == endPoint1)
        return true;
    else
        return false;
}

bool Dijkstra::checkCollision(uint pPathId1, uint pPathId2, uint pStartIndex1, uint pStartIndex2){
    uint endPoint1 = totalPath[pPathId1][pStartIndex1+1];
    uint endPoint2 = totalPath[pPathId2][pStartIndex2+1];

    if (endPoint1 == endPoint2)
        return true;
    else
        return false;
}

void Dijkstra::insertWait(uint pPathId, uint pIndex) {
//    std::cout << "Insert in: " << pPathId << " at " << pIndex << "\n";

    totalPath[pPathId].insert(totalPath[pPathId].begin() + pIndex, totalPath[pPathId][pIndex]);
}

//int Dijkstra:: getSmallestMakespan(uint pPathId1, uint pPathId2, std::pair<unsigned long, unsigned int> pPathSize) {
//    pPathSize
