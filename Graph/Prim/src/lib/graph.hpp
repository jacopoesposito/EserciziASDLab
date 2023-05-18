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
        list<Node *> getNodes();
        list<Edge *> getEdges();
        void addNode(Node *node);
        void addEdge(Edge *edge);
        void Prim(Node *s);
    private:
        struct Comp{ //Ovveride dell'operatore di confronto per supportare il confronto fra il campo distanza di due nodi del grafo
            bool operator()(Node *a, Node *b){
                return a->getDistance()>b->getDistance();
            }
        };

        list<Node *> nodes;
        vector<Edge *> edges;
        priority_queue<Node *, vector<Node *>, Comp> minQueue;
        Edge *findEdge(int NodeS, int NodeD);

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

Edge *Graph::findEdge(int NodeS, int NodeD){
    vector<Edge *>::iterator iter;
    for(iter = edges.begin(); iter != edges.end(); ++iter){
        if(((*iter)->getSource()->getValue()==NodeS) && ((*iter)->getDestination()->getValue()==NodeD))
            return *iter;
    }
    return nullptr;
}

void Graph::Prim(Node *s){

    list<Node *>::iterator iter;
    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        minQueue.push(*iter);
        (*iter)->setCheckQueue(true);
    }

    s->setDistance(0);

    while(!minQueue.empty()){
        cout << minQueue.top()->getDistance() << endl;
        Node *u = minQueue.top();
        minQueue.pop();
        u->setCheckQueue(false);
        list<Node *>::iterator iterator;
        for(iterator = nodes.begin(); iterator != nodes.end(); ++iterator){
            if((*iterator)->getCheckQueue()){
                Edge *e = findEdge(u->getValue(), (*iterator)->getValue());
                if(e != nullptr){
                    if((*iterator)->getCheckQueue() && (*iterator)->getDistance() > e->getWeigth()){
                        (*iterator)->setDistance(e->getWeigth());
                        (*iterator)->setParent(u);
                    }
                }
            }
        }
    }

}



#endif