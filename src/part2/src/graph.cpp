//
// Created by roelv on 21/11/2022.
//
#include <iostream>

#include "../inc/graph.h"
#include <cmath>
/**
 * Construct graph for 12 x 12 grid.
 *
 * https://stackoverflow.com/questions/16329403/how-can-you-make-an-adjacency-matrix-which-would-emulate-a-2d-grid
 */
Graph::Graph() {
    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridWidth; j++) {
            int l = toVertexNumber(i, j);

            // Inner diagonal
            if(j>0) {
                adjacencyMatrix[l][l-1] = true;
                adjacencyMatrix[l-1][l] = true;
            }

            // Outer diagonal
            if(i>0) {
                adjacencyMatrix[l][l-gridWidth] = true;
                adjacencyMatrix[l-gridWidth][l] = true;
            }
        }
    }
}

void Graph::print() {
    for (auto & i : adjacencyMatrix) {
        for (bool j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::removeGridCell(unsigned int pRow, unsigned int pCol) {
    unsigned int l = toVertexNumber(pRow, pCol);

    for (int i = 0; i < nVertices; i++) {
        adjacencyMatrix[l][i] = false;
        adjacencyMatrix[i][l] = false;
    }
}

std::pair<unsigned int, unsigned int> Graph::toCoordinates(int pVertexNumber) {
    int row = floor((double) pVertexNumber/gridWidth);
    int col = pVertexNumber % gridWidth;

    return {row, col};
}

unsigned int Graph::toVertexNumber(unsigned long pRow, unsigned long pCol) {
    return pRow * gridWidth + pCol;
}