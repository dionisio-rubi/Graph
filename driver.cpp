//Created by: Rubi Dionisio

#include <iostream>
#include <fstream>
#include "Graph.h"

void print(std::string& item);

int main(){
    Graph<std::string> g;
    int mpg = 40;

    std::ifstream file;
    file.open("initialVals.txt");
    std::string c1;
    std::string c2;
    int d;
    if(file.is_open()){
        while(file >> c1 >> c2 >> d){
            g.add(c1, c2, d);
        }
    }
    file.close();
    std::cout << g.getNumEdges() << std::endl;
    std::cout << g.getNumVertices() << std::endl;

    g.printAdjacencyList();
    // g.depthFirstTraversal("Reno", print);
    // std::cout << std::endl;
    g.breadthFirstTraversal("Reno", print);
    std::cout << std::endl;
    return 0;
};

void print(std::string& item){
    // std::ofstream treeFile;
    // treeFile.open("treeFile.txt", std::ios::app);
    std::cout << item << " ";
    // treeFile << item << " ";
    // treeFile.close();
}