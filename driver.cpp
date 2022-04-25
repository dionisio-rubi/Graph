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

    std::ofstream outfile;
    outfile.open("paths.txt");
    if(outfile.is_open()){
        std::vector<std::string> cities = g.getLabels();
        std::vector<std::string> possiblePaths;
        std::vector<std::string> shortPath = {cities[0], cities[1], cities[2], cities[3], cities[4]};
        int smallWeight = g.getEdgeWeight(cities[0], cities[1]) + g.getEdgeWeight(cities[1], cities[2]) + g.getEdgeWeight(cities[2], cities[3]) + g.getEdgeWeight(cities[3], cities[4]) + g.getEdgeWeight(cities[4], cities[0]);
        // int numCities = cities.size();
        std::string cinNums = "01234";
        do{
            possiblePaths.push_back(cinNums);
        }while(std::next_permutation(cinNums.begin(), cinNums.end()));

        for(int i = 0; i < possiblePaths.size(); i++){
            int one = possiblePaths[i][0] - '0';
            int two = possiblePaths[i][1] - '0';
            int three = possiblePaths[i][2] - '0';
            int four = possiblePaths[i][3] - '0';
            int five = possiblePaths[i][4] - '0';
            
            int ctotWeight = g.getEdgeWeight(cities[one], cities[two]) + g.getEdgeWeight(cities[two], cities[three]) + g.getEdgeWeight(cities[three], cities[four]) + g.getEdgeWeight(cities[four], cities[five]) + g.getEdgeWeight(cities[five], cities[one]);

            outfile << cities[one] << " -> " << cities[two] << " -> " << cities[three] << " -> " << cities[four] << " -> " << cities[five] << " -> " << cities [one] << " | Total Miles: " << ctotWeight << " miles | Total Gas: "<< ctotWeight/mpg << std::endl;

            if(ctotWeight < smallWeight){
                smallWeight = ctotWeight;
                shortPath = {cities[one], cities[two], cities[three], cities[four], cities[five]};
            }
        } 

        outfile << "\nShortest Path: " << shortPath[0] << " -> " << shortPath[1] << " -> " << shortPath[2] << " -> " << shortPath[3] << " -> " << shortPath[4] << " -> " << shortPath[0] << " | Total Miles: " << smallWeight << " miles | Total Gas: "<< smallWeight/mpg << std::endl;
        std::cout << "Shortest Path: " << shortPath[0] << " -> " << shortPath[1] << " -> " << shortPath[2] << " -> " << shortPath[3] << " -> " << shortPath[4] << " -> " << shortPath[0] << " | Total Miles: " << smallWeight << " miles | Total Gas: "<< smallWeight/mpg << std::endl;

    }
    outfile.close();

    g.printAdjacencyList();

    // g.depthFirstTraversal("Reno", print);
    // std::cout << std::endl;
    // g.breadthFirstTraversal("Reno", print);
    // std::cout << std::endl;
    return 0;
};

void print(std::string& item){
    // std::ofstream treeFile;
    // treeFile.open("treeFile.txt", std::ios::app);
    std::cout << item << " ";
    // treeFile << item << " ";
    // treeFile.close();
}

/*

shortestPath(theGraph: Graph, weight: WeightArray) 
 // Step 1: initialization 
Create a set vertexSet that contains only vertex 0
n = number of vertices in theGraph
for (v = 0 through n - 1)
weight[v] = matrix[0][v] 
// Steps 2 through n
// Invariant: For v not in vertexSet, weight[v] is the 
 // smallest weight of all paths from 0 to v that pass 
 // through only vertices in vertexSet before reaching 
 // v. For v in vertexSet, weight[v] is the smallest 
 // weight of all paths from 0 to v (including paths 
 // outside vertexSet), and the shortest path 
 // from 0 to v lies entirely in vertexSet.
for (step = 2 through n)
{
Find the smallest weight[v] such that v is not in vertexSet
Add v to vertexSet 
// Check weight[u] for all u not in vertexSet
for (all vertices u not in vertexSet)
if (weight[u] > weight[v] + matrix[v][u]) 
weight[u] = weight[v] + matrix[v][u]

*/