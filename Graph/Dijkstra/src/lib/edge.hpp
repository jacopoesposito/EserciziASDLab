using namespace std;

#include "node.hpp"
#include <list>

#ifndef edge_hpp
#define edge_hpp

class Edge{

    public:
        Edge(Node *nodeS, Node *nodeD, int weigth);
        Node *getSource();
        Node *getDestination();
        int getWeigth();
        void setWeigth(int weigth);
    
    private:
        Node *nodeS;
        Node *nodeD;
        int weigth;
    
};

Edge::Edge(Node *nodeS, Node *nodeD, int weigth){
    this->nodeS = nodeS;
    this->nodeD = nodeD;
    this->weigth = weigth;
}

Node* Edge::getSource(){
    return nodeS;
}

Node *Edge::getDestination(){
    return nodeD;
}

void Edge::setWeigth(int weigth){
    this->weigth = weigth;
}


#endif