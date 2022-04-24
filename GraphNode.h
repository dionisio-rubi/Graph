#ifndef GRAPH_NODE
#define GRAPH_NODE

template<class T>
class GraphNode{
    T item; // A data item
    int weight; // A weight
    GraphNode<T>* next; // Points to next GraphNode
public:
    GraphNode();
    GraphNode(const T& anItem, const int anEdgeWeight);
    GraphNode(const T& anItem, const int anEdgeWeight, GraphNode<T>* nextGraphNodePtr);
    void setItem(const T& anItem, const int anEdgeWeight);
    void setNext(GraphNode<T>* nextGraphNodePtr);
    T getItem() const;
    int getWeight() const;
    GraphNode<T>* getNext() const;
}; 
#include "GraphNode.cpp"
#endif