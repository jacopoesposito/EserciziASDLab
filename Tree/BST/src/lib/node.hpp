using namespace std;

#include <vector>

#ifndef node_hpp
#define node_hpp

class Node{
    private:
        int value;
        Node* left;
        Node* right;
        Node* parent;
        
    public:
        Node(int value);
        
        Node* getLeftChild();
        Node* getRigthChild();
        Node* getParent();
        int getValue();
        void setLeftChild(Node *node);
        void setRightChild(Node *node);
        void setValue(int value);
        void setParent(Node *node);

};

Node::Node(int value){
    this->value = value;
    left = nullptr;
    right = nullptr;
}

Node* Node::getLeftChild(){
    return left;
}

Node* Node::getRigthChild(){
    return right;
}

int Node::getValue(){
    return value;
}

Node* Node::getParent(){
    return parent;
}

void Node::setLeftChild(Node *node){
    this->left = node;
}

void Node::setRightChild(Node *node){
    this->right = node;
}

void Node::setParent(Node *node){
    this->parent = node;
}

 

#endif