using namespace std;

#include "node.hpp"
#include<list>
#include<iostream>

#ifndef graph_hpp
#define graph_hpp

class Graph{ //Classe che rappresenta un grafo e contiene il metodo BFS
    public:
        Graph();
        void BFS(Node *s);
        list<Node *> getNodes();
        void AddNode(Node *node);

    private:
        list<Node *> Q;
        list<Node *> nodes;
};

Graph::Graph(){}

void Graph::BFS(Node *s){
    s->setDistance(0);
    s->setColor("gray");

    Q.push_back(s);

    while(!Q.empty()){
        Node *u = Q.front();
        Q.pop_front();

        list<Node *>::iterator iter;
        list<Node *> adj = u->getListAdj();
        for(iter = adj.begin(); iter != adj.end(); ++iter){
            if((*iter)->getColor()=="white"){
                (*iter)->setParent(u);
                (*iter)->setDistance(u->getDistance()+1);
                Node *v = *iter;
                Q.push_back(v);
            }
        }
        u->setColor("black");
    }

}

void Graph::AddNode(Node* node){
    this->nodes.push_back(node);
}

list<Node *> Graph::getNodes(){
    return nodes;
}

#endif 