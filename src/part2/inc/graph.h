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
    void removeGridCell(unsigned int pRow, unsigned int pCol);
    static const int gridWidth = 12;
    static const int nVertices = gridWidth * gridWidth;
    bool adjacencyMatrix[nVertices][nVertices]{};
    static std::pair<unsigned int, unsigned int> toCoordinates(int pVertexNumber);
    static unsigned int toVertexNumber(unsigned long pRow, unsigned long pCol);
};


#endif //INC_5LIG0_AS1_GRAPH_H
