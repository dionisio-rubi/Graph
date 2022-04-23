#ifndef GRAPH_H
#define GRAPH_H

#include "GraphInterface.h"

template <class T>
class Graph: public GraphInterface<T>{
    
    public:
    Graph();
    int getNumVertices() const;
    int getNumEdges() const;
    boolean add(T start, T end, int edgeWeight);
    boolean remove(T start, T end);
    int getEdgeWeight(T start, T end) const;
    void depthFirstTraversal(T start, void visit(T&));
    void breadthFirstTraversal(T start, void visit(T&));
    ~Graph();
};

#include "Graph.cpp"

#endif