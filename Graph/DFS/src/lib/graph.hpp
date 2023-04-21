using namespace std;

#include "node.hpp"
#include <list>
#include <iostream>


#ifndef graph_hpp
#define graph_hpp

class Graph{

    public:
        Graph();
        void DFS();
        list<Node *> getNodes();
        void addNode(Node* node);
    
    private:
        void DFSVisit(Node *node);
        list<Node *> nodes;
        int time;
};

Graph::Graph(){
    time = 0;
}

void Graph::DFS(){
    list<Node *>::iterator iter;
    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        if((*iter)->getColor()=="white"){
            DFSVisit(*iter);
        }
    }
}

void Graph::DFSVisit(Node *node){
    time+=1;
    node->setTimeVisit(time);
    node->setColor("gray");

    list<Node *> adj = node->getListAdj();
    list<Node *>::iterator adjIter;
    
    for(adjIter = adj.begin(); adjIter != adj.end(); ++adjIter){

        if((*adjIter)->getColor() == "white"){
            (*adjIter)->setParent(node);
            DFSVisit(*adjIter);
        }
    }

    time+=1;
    node->setTimeCompletation(time);
    node->setColor("black");
}

list<Node *> Graph::getNodes(){
    return nodes;
}

void Graph::addNode(Node *node){
    this->nodes.push_back(node);
}

#endif