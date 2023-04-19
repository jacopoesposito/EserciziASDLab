using namespace std;

#include "node.hpp"
#include<list>
#include<iostream>

#ifndef graph_hpp
#define graph_hpp

class Graph{
    public:
        Graph();
        void BFS(Node *s);
        list<Node *> getNodes();
        void setNodes(Node *node);

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
        Node *u = (*Q.begin());
        Q.pop_front();

        list<Node *>::iterator iter;
        for(iter = u->getListAdj().begin(); iter != u->getListAdj().end(); ++iter){
            if((*iter)->getColor()=="white"){
                (*iter)->setParent(u);
                (*iter)->setDistance(u->getDistance()+1);
                Q.push_back(*iter);
            }
        }
        u->setColor("black");
    }

}

void Graph::setNodes(Node *node){
    this->nodes = nodes;
}

list<Node *> Graph::getNodes(){
    return nodes;
}

#endif 