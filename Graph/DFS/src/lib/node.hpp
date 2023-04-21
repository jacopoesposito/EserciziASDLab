using namespace std;

#include<iostream>
#include<list>
#include<string>
#include<limits>


#ifndef node_hpp
#define node_hpp

class Node{ //Classe che rappresenta un nodo del grafo
    public:
        Node(int value, bool visited, string color);
        Node(int value, bool visited, string color, list<Node *> lista_adiacenza);

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
        void setDistance(int distance);
        void setListAdiacenza(Node *nodo);
        void setParent(Node *parent);

    private:
        int value;
        bool visited;
        int time_visit;
        int time_completation;
        string color;
        Node *parent;
        list<Node *> lista_adiacenza;
        
};

int Node::getValue(){
    return value;
}

string Node::getColor(){
    return color;
}

bool Node::getVisited(){
    return visited;
}

int Node::getTimeVisit(){
    return time_visit;
}

int Node::getTimeCompletation(){
    return time_completation;
}

list<Node *> Node::getListAdj(){
    return lista_adiacenza;
}

Node * Node::getParent(){
    return parent;
}

void Node::setValue(int value){
    this->value = value;
}

void Node::setColor(string color){
    this->color = color;
}

void Node::setVisited(bool visited){
    this->visited = visited;
}

void Node::setTimeVisit(int time_visit){
    this->time_visit = time_visit;
}

void Node::setTimeCompletation(int time_completation){
    this->time_completation = time_completation;
}

void Node::setListAdiacenza(Node* node){
    this->lista_adiacenza.push_back(node);
}

void Node::setParent(Node* parent){
    this->parent = parent;
}

Node::Node(int value, bool visited, string color)
{
    this->value = value;
    this->visited = visited;
    this->color = color;
    this->time_visit = numeric_limits<int>::max();
    this->time_completation = numeric_limits<int>::max();
    parent = nullptr;
}

Node::Node(int value, bool visited, string color, list<Node *> lista_adiacenza)
{
    this->value = value;
    this->visited = visited;
    this->color = color;
    this->lista_adiacenza = lista_adiacenza;
    parent = nullptr;
}

#endif