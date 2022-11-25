//
// Created by roelv on 21/11/2022.
//

#ifndef INC_5LIG0_AS1_GRAPH_H
#define INC_5LIG0_AS1_GRAPH_H
#include <vector>


class Graph {

public:
    Graph();
    void print();
    void removeVertex(int pCol, int pRow);
    static const int gridWidth = 12;
    static const int nVertices = gridWidth * gridWidth;
    bool adjacencyMatrix[nVertices][nVertices]{};
    std::pair<unsigned int, unsigned int> toCoordinates(int pVertexNumber);
    unsigned int toVertexNumber(unsigned int pRow, unsigned int pCol);
};


#endif //INC_5LIG0_AS1_GRAPH_H
