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

        //Setter
        void setValue(int value);
        void setVisited(bool visited);
        void setTimeVisit(int time_visit);
        void setTimeCompletation(int time_completation);
        void setColor(string color);
        void setDistance(int d);
        void setListAdiacenza(Node *nodo);
        void setParent(Node *parent);

    private:
        int value;
        int rango;
        Node *parent;
        list<Node *> lista_adiacenza;
        
};

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
    return rango;
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

void Node::setDistance(int rango){
    this->rango = rango;
}

Node::Node(int value)
{
    this->value = value;
    rango = numeric_limits<int>::max();
    parent = nullptr;
}

#endif