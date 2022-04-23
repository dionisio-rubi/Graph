#include "LinkedStack.h"

template<typename T>
LinkedStack<T>::LinkedStack(){
    topPtr = nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack(){
    while(!isEmpty()){
        pop();
    }
}

template<typename T>
bool LinkedStack<T>::isEmpty() const{
    return topPtr == nullptr;
}

template<typename T>
bool LinkedStack<T>::push(const T& newEntry){
    Node<T>* newNodePtr = new Node<T>(newEntry, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<typename T>
bool LinkedStack<T>::pop(){
    bool outcome = false;
    if(!isEmpty()){
        Node<T>* deletePtr = topPtr;
        topPtr = deletePtr->getNext();

        delete deletePtr;
        deletePtr = nullptr;

        outcome = true;
    }
    return outcome;
}

template<typename T>
T LinkedStack<T>::peek() const{
    return topPtr->getItem();
}