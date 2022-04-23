#ifndef LINKED_STACK
#define LINKED_STACK
#include "StackInterface.h"
#include "Node.h"

template<typename T>
class LinkedStack : public StackInterface <T>{
    private:
    Node<T>* topPtr; //top of the stack

    public:
    //constructors and destructors first
    LinkedStack();
    virtual ~LinkedStack();
    //Other functions
    bool isEmpty() const;
    bool push(const T& newEntry);
    bool pop();
    T peek() const;
};

#include "LinkedStack.cpp"
#endif