//
// Created by roelv on 21/11/2022.
//

#ifndef INC_5LIG0_AS1_GRAPH_H
#define INC_5LIG0_AS1_GRAPH_H


class Graph {

public:
    Graph();
    void print();
    void removeVertex(int pCol, int pRow);

private:
    static const int gridWidth = 3;
    static const int nVertices = gridWidth * gridWidth;
    bool adjacencyMatrix[nVertices][nVertices]{};
};


#endif //INC_5LIG0_AS1_GRAPH_H
