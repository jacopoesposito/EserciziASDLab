using namespace std;

#include "node.hpp"
#include "edge.hpp"
#include <list>
#include <iostream>

#ifndef graph_hpp
#define graph_pp

class Graph{

    public:
        Graph();
        void Djikstra();
        list<Node *> getNodes();
        list<Node *> getMinPath();
        void addNode(Node *node);
    private:
        void relax(Node *nodeS, Node *nodeD, Edge *edge);
        list<Node *> nodes;
        list<Node *> minPath;
        
};

Graph::Graph(){}

void Graph::addNode(Node *node){
    this->nodes.push_back(node);
}

list<Node *> Graph::getNodes(){
    return nodes;
}

list<Node *> Graph::getMinPath(){
    return minPath;
}

void Graph::relax(Node *nodeS, Node *nodeD, Edge *edge){
    if(nodeD->getDistance() > nodeS->getDistance() + edge->getWeigth()){
        nodeD->setParent(nodeS);
        nodeD->setDistance((nodeS->getDistance() + edge->getWeigth()));
    }
}



#endif