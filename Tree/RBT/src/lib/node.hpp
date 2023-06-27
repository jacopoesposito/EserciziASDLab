using namespace std;

#include <iostream>

#ifndef node_hpp
#define node_hpp

class Node{
    private:
        int value;
        Node* left;
        Node* right;
        Node* parent;
        string color;

    public:
        Node(int value);
        int getValue();
        Node* getLeftChild();
        Node* getRightChild();
        Node* getParent();
        string getColor();
        void setValue(int value);
        void setLeftChild(Node *node);
        void setRightChild(Node *node);
        void setParent(Node *parent);
        void setColor(string color);
};

Node::Node(int value){
    this->value = value;
}

int Node::getValue(){
    return value;
}

Node* Node::getLeftChild(){
    return left;
}

Node* Node::getRightChild(){
    return right;
}

Node* Node::getParent(){
    return parent;
}

string Node::getColor(){
    return color;
}

void Node::setValue(int value){
    this->value = value;
}

void Node::setLeftChild(Node *node){
    this->left = node;
}

void Node::setRightChild(Node *node){
    this->right = node;
}

void Node::setParent(Node *parent){
    this->parent = parent;
}

void Node::setColor(string color){
    this->color = color;
}
#endif