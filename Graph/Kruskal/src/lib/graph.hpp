using namespace std;

#include <iostream>
#include <list>
#include <limits>

using namespace std;

#include "node.hpp"
#include "edge.hpp"
#include <list>
#include <algorithm>
#include <iostream>
#include <queue>

#ifndef graph_hpp
#define graph_pp

class Graph{ //Classe che rappresenta il grafo e contiene i metodi per eseguire Dijkstra

    public:
        Graph();
        void Djikstra();
        list<Node *> getNodes();
        list<Edge *> getEdges();
        list<Edge *> getMinPath();
        void addNode(Node *node);
        void addEdge(Edge *edge);
        void Kruskal();
    private:
        struct Comp{ //Ovveride dell'operatore di confronto per supportare il confronto fra il campo distanza di due nodi del grafo
            bool operator()(Edge *a, Edge *b){
                return a->getWeigth()<b->getWeigth();
            }
        };

        Edge *getEdge(int nodeS, int nodeD);
        void makeSet(Node *node);   
        Node* FindSet(Node *nodeS);
        void link(Node *nodeS, Node *nodeD);
        list<Node *> nodes;
        vector<Edge *> edges;
        list<Edge *> A;
        
};

Graph::Graph(){}

void Graph::addNode(Node *node){
    this->nodes.push_back(node);
}

void Graph::addEdge(Edge *edge){
    this->edges.push_back(edge);
}

list<Node *> Graph::getNodes(){
    return nodes;
}

list<Edge *> Graph::getMinPath(){
    return A;
}

void Graph::Kruskal(){
    list<Node *>::iterator iter;
    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        makeSet(*iter);
    }

    sort(edges.begin(), edges.end(), Comp());

    vector<Edge *>::iterator edgeIter;
    for(edgeIter = edges.begin(); edgeIter != edges.end(); ++edgeIter)
        cout << (*edgeIter)->getSource()->getValue() << " " << (*edgeIter)->getDestination()->getValue() << endl;
    for(edgeIter = edges.begin(); edgeIter != edges.end(); ++edgeIter){
        if(FindSet((*edgeIter)->getSource()) != FindSet((*edgeIter)->getDestination())){
            A.push_back(*edgeIter);
            link(FindSet((*edgeIter)->getSource()), FindSet((*edgeIter)->getDestination()));
        }
    }

}

void Graph::makeSet(Node *nodeS){
    nodeS->setDistance(0);
    nodeS->setParent(nodeS);
}

Node* Graph::FindSet(Node *nodeS){
    if(nodeS != nodeS->getParent()){
        nodeS->setParent(FindSet(nodeS->getParent()));
    }
    return nodeS->getParent();
}

void Graph::link(Node *nodeS, Node *nodeD){
    if(nodeS->getDistance() > nodeD->getDistance()){
        nodeD->setParent(nodeS);
    }
    else{
        nodeS->setParent(nodeD);
        if(nodeS->getDistance() == nodeD->getDistance()){
            nodeD->setDistance((nodeD->getDistance()+1));
    }
    }

}

#endif