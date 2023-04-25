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
        void addNode(Node *node);
        void addEdge(Edge *edge);
        bool BellmanFord(Node *node);
    private:
        struct Comp{ //Ovveride dell'operatore di confronto per supportare il confronto fra il campo distanza di due nodi del grafo
            bool operator()(Node *a, Node *b){
                return a->getDistance()>b->getDistance();
            }
        };

        Edge *getEdge(int nodeS, int nodeD);
        void relax(Node *nodeS, Node *nodeD, Edge *edge);
        priority_queue<Node *, vector<Node *>, Comp> nodeQueue;
        list<Node *> nodes;
        list<Edge *> edges;        
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

Edge* Graph::getEdge(int nodeS, int nodeD){
    list<Edge *>::iterator iter;
    for(iter = edges.begin(); iter != edges.end(); ++iter){
        if(((*iter)->getSource()->getValue()==nodeS) && ((*iter)->getDestination()->getValue()==nodeD))
            return *iter;
    }
    return nullptr;
}

void Graph::relax(Node *nodeS, Node *nodeD, Edge *edge){
    //Calcolo la stima della distanza del nodo di destinazione dalla sorgente e inserisco il nodo nella lista
    if((nodeS->getDistance() != numeric_limits<int>::max()) && (nodeD->getDistance() > (nodeS->getDistance() + edge->getWeigth()))){
        nodeD->setParent(nodeS);
        int d = nodeS->getDistance() + edge->getWeigth();
        nodeD->setDistance(d);
    }
}

bool Graph::BellmanFord(Node *nodeS){
    nodeS->setDistance(0);

    list<Edge*>::iterator edgeIter;

    for(int i = 0; i < nodes.size()-1; i++){
        for(edgeIter = edges.begin(); edgeIter != edges.end(); ++edgeIter){
            relax((*edgeIter)->getSource(), (*edgeIter)->getDestination(), *edgeIter);
        }
    }
    for(edgeIter = edges.begin(); edgeIter != edges.end(); ++edgeIter){
        if((*edgeIter)->getDestination()->getDistance() > ((*edgeIter)->getSource()->getDistance() + (*edgeIter)->getWeigth()))
            return false;
    }
    return true;
}


#endif