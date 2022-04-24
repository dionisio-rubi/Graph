#include "GraphNode.h"

template<class T>
GraphNode<T>:: GraphNode() : next(nullptr){} // end default constructor

template<class T>
GraphNode<T>::GraphNode(const T& anItem, const int anEdgeWeight) : item(anItem), weight(anEdgeWeight), next(nullptr){} // end constructor

template<class T>
GraphNode<T>::GraphNode(const T& anItem, const int anEdgeWeight, GraphNode<T>* nextGraphNodePtr) : item(anItem), weight(anEdgeWeight), next(nextGraphNodePtr){} // end constructor

template<class T>
void GraphNode<T>::setItem(const T& anItem, const int anEdgeWeight){
    item = anItem;
    weight = anEdgeWeight;
} // end setItem

template<class T>
void GraphNode<T>::setNext(GraphNode<T>* nextGraphNodePtr){
    next = nextGraphNodePtr;
} // end setNext

template<class T>
T GraphNode<T>::getItem() const{
    return item;
} // end getItem

template<class T>
int GraphNode<T>::getWeight() const{
    return weight;
} // end getWeight

template<class T>
GraphNode<T>* GraphNode<T>::getNext() const{
    return next;
} // end getNext