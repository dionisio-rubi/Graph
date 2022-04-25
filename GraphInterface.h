#ifndef GRAPH_INTERFACE
#define GRAPH_INTERFACE

template <class T>
class GraphInterface{
    public:
    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;
    virtual bool add(T start, T end, int edgeWeight) = 0;
    virtual bool remove(T start, T end) = 0;
    virtual int getEdgeWeight(T start, T end) const = 0;
    virtual void depthFirstTraversal(T start, void visit(T&)) = 0;
    virtual void breadthFirstTraversal(T start, void visit(T&)) = 0;
    virtual ~GraphInterface() { }
};

#endif