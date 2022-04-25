#include "Graph.h"

template<class T>
int Graph<T>::getLabelIndex(T label) const{
    for(int i = 0; i < labelList.size(); i++){
        if(labelList[i] == label){
            return i;
        }
    }
    return -1;
}

template<class T>
int Graph<T>::getSublistIndex(T major, T minor) const{
    int majorIndex = getLabelIndex(major);
    if(majorIndex == -1){
        return -1;
    }
    int minorIndex = getLabelIndex(minor);
    if(minorIndex == -1){
        return -1;
    }
    for(int i = 0; i < adjacencyList[majorIndex].size(); i++){
        if(adjacencyList[majorIndex][i] == minorIndex){
            return i;
        }
    }
    return -1;
}

template<class T>
void Graph<T>::depthTraversalHelper(T label, void visit(T&), bool* seenArr, std::stack<T>& lstack){
    int index = getLabelIndex(label);
    if(index == -1){
        return;
    }
    if(seenArr[index]){
        return;
    }
    seenArr[index] = true;
    visit(label);
    for(int i = 0; i < adjacencyList[index].size(); i++){
        // if(!seenArr[/*adjacencyList[index][i]*/i]){
            if(adjacencyList[index][i] != 0){
                std::cout << adjacencyList[index][i] << std::endl;
            }
            depthTraversalHelper(labelList[adjacencyList[index][i]], visit, seenArr, lstack);
        // }
        // std::cout << adjacencyList[index][i] << std::endl;
        // depthTraversalHelper(labelList[i], visit, seenArr, lstack);
    }
    lstack.push(label);
}

template<class T>
void Graph<T>::breadthTraversalHelper(T label, void visit(T&), bool* seenArr, std::queue<T>& lqueue){
    int index = getLabelIndex(label);
    if(index == -1){
        return;
    }
    if(!seenArr[index]){
        seenArr[index] = true;
            visit(label);
            for(int i = 0; i < adjacencyList[index].size(); i++){
                // if(!seenArr[i]){
                    if(adjacencyList[index][i] != 0){
                        std::cout << adjacencyList[index][i] << std::endl;
                    }
                    breadthTraversalHelper(labelList[adjacencyList[index][i]], visit, seenArr, lqueue);
                // }
                // std::cout << adjacencyList[index][i] << std::endl;
                // depthTraversalHelper(labelList[i], visit, seenArr, lstack);
            }
            lqueue.push(label);
            
            // for(int i = 0; i < adjacencyList[index].size(); i++){
            //     breadthTraversalHelper(labelList[i], visit, seenArr, lqueue);
            // }
            // lqueue.push(label);
            
        }
    

}

template<class T>
Graph<T>::Graph(){

}

template<class T>
int Graph<T>::getNumVertices() const{
    return vertexNum;
}

template<class T>
int Graph<T>::getNumEdges() const{
    return edgeNum;
}

template<class T>
bool Graph<T>::add(T start, T end, int edgeWeight){
    int startIndex = getLabelIndex(start);
    int endIndex = getLabelIndex(end);
    if(startIndex == -1){
        labelList.push_back(start);
        vertexNum++;
        adjacencyList.resize(vertexNum);
        for(int i = 0; i < vertexNum; i++){
            adjacencyList[i].resize(vertexNum, 0);
        }
        startIndex = getLabelIndex(start);
    }
    if(endIndex == -1){
        labelList.push_back(end);
        vertexNum++;
        adjacencyList.resize(vertexNum);
        for(int i = 0; i < vertexNum; i++){
            adjacencyList[i].resize(vertexNum, 0);
        }
        endIndex = getLabelIndex(end);
    }
    adjacencyList[startIndex][endIndex] = edgeWeight;
    adjacencyList[endIndex][startIndex] = edgeWeight;
    edgeNum++;
    return true;
}

template<class T>
bool Graph<T>::remove(T start, T end){
    int startIndex = getLabelIndex(start);
    int endIndex = getLabelIndex(end);
    if(startIndex == -1 || endIndex == -1){
        return false;
    }
    int sublistIndex = getSublistIndex(start, end);
    if(sublistIndex == -1){
        return false;
    }
    adjacencyList[startIndex].erase(adjacencyList[startIndex].begin() + sublistIndex);
    edgeNum--;
    return true;

}

template<class T>
int Graph<T>::getEdgeWeight(T start, T end) const{
    int startIndex = getLabelIndex(start);
    int endIndex = getLabelIndex(end);
    // if(startIndex == -1 || endIndex == -1){
    //     return -1;
    // }
    // int sublistIndex = getSublistIndex(start, end);
    // if(sublistIndex == -1){
    //     return -1;
    // }
    return adjacencyList[startIndex][endIndex];   
}

template<class T>
void Graph<T>::depthFirstTraversal(T start, void visit(T&)){
    bool* seenArr = new bool[labelList.size()];
    std::stack<T> lstack;
    for(int i = 0; i < labelList.size(); i++){
        seenArr[i] = false;
    }
    depthTraversalHelper(start, visit, seenArr, lstack);
    while(!lstack.empty()){
        visit(lstack.top());
        lstack.pop();
    }
    delete[] seenArr;

}

template<class T>
void Graph<T>::breadthFirstTraversal(T start, void visit(T&)){
    bool* seenArr = new bool[labelList.size()];
    std::queue<T> lqueue;
    for(int i = 0; i < labelList.size(); i++){
        seenArr[i] = false;
    }
    breadthTraversalHelper(start, visit, seenArr, lqueue);
    while(!lqueue.empty()){
        visit(lqueue.front());
        lqueue.pop();
    }
    delete[] seenArr;
}

template<class T>
void Graph<T>::printAdjacencyList() const{
    std::cout << "\t";
    for(int i = 0; i < labelList.size(); i++){
        std::cout << i << "\t";
        // std::cout << labelList[i] << "\t";
    }
    std::cout << std::endl;
    for(int i = 0; i < labelList.size(); i++){
        std::cout << i << ":\t";
        // std::cout << labelList[i] << ":\t";
        for(int j = 0; j < adjacencyList[i].size(); j++){
            std::cout << adjacencyList[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template<class T>
std::vector<T> Graph<T>::getLabels() const{
    return labelList;
}

template<class T>
Graph<T>::~Graph(){

}