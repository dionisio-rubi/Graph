#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>

#include "GraphInterface.h"

template <class T>
class Graph: public GraphInterface<T>{
    private:
        std::vector<T> labelList; //holds the "keys" for  adjacency list
        std::vector<std::vector<int>> adjacencyList; // the "values" for matrix
        int vertexNum = 0;
        int edgeNum = 0;

    protected:
        int getLabelIndex(T label) const; //get index of label in labelList, -1 if not present
        int getSublistIndex(T major, T minor) const; // get index of weight in adjacencyList

        void depthTraversalHelper(T label, void visit(T&), bool* seenArr, std::stack<T>& lstack);
        void breadthTraversalHelper(T label, void visit(T&), bool* seenArr, std::queue<T>& lqueue);
    public:
        Graph();
        int getNumVertices() const override;
        int getNumEdges() const override;

        bool add(T start, T end, int edgeWeight) override;
        bool remove(T start, T end) override;

        int getEdgeWeight(T start, T end) const override;

        void depthFirstTraversal(T start, void visit(T&)) override;
        void breadthFirstTraversal(T start, void visit(T&)) override;

        // not normally available as part of the graph ADT but extremely helpful
        void printAdjacencyList() const;
        std::vector<T> getLabels() const;

        ~Graph();
};

#include "Graph.cpp"

#endif