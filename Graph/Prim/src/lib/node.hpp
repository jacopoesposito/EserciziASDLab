using namespace std;

#include<iostream>
#include<list>
#include<string>
#include<limits>


#ifndef node_hpp
#define node_hpp

class Node{ //Classe che rappresenta un nodo del grafo
    public:
        Node(int value);

        //Getter
        int getValue();
        string getColor();
        bool getVisited();
        int getTimeVisit();
        int getTimeCompletation();
        int getDistance();
        list<Node *> getListAdj();
        Node *getParent();
        bool getCheckQueue();

        //Setter
        void setValue(int value);
        void setVisited(bool visited);
        void setTimeVisit(int time_visit);
        void setTimeCompletation(int time_completation);
        void setColor(string color);
        void setDistance(int d);
        void setListAdiacenza(Node *nodo);
        void setParent(Node *parent);
        void setCheckQueue(bool isInQueue);

    private:
        int value;
        int d;
        bool isInQueue;
        Node *parent;
        list<Node *> lista_adiacenza;
        
};

bool Node::getCheckQueue(){
    return isInQueue;
}

int Node::getValue(){
    return value;
}

list<Node *> Node::getListAdj(){
    return lista_adiacenza;
}

Node * Node::getParent(){
    return parent;
}

int Node::getDistance(){
    return d;
}

void Node::setValue(int value){
    this->value = value;
}

void Node::setListAdiacenza(Node* node){
    this->lista_adiacenza.push_back(node);
}

void Node::setParent(Node* parent){
    this->parent = parent;
}

void Node::setDistance(int d){
    this->d = d;
}

void Node::setCheckQueue(bool isInQueue){
    this->isInQueue = isInQueue;
}

Node::Node(int value)
{
    this->value = value;
    d = numeric_limits<int>::max();
    parent = nullptr;
}

#endif