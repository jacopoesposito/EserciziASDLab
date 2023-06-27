using namespace std;

#include <vector>
#include "node.hpp"

#ifndef TREE_HPP
#define TREE_HPP

class Tree{

    private:
        Node *root;
    public:
        Tree();
        
        Node* treeSearch(Node *node, int k);
        Node* treeMinimum(Node *node);
        Node* treeMaximum(Node *node);
        Node* treeSuccessor(Node *node);
        Node* treePredecessor(Node *node);
        void treeInsert(Node *node);
        void transplant(Node *u, Node *v);
        void treeDelete(Node *z);
        void setRoot(Node *node);
        Node* getRoot();
        void preOrderVisit(Node *node);
};

Tree::Tree(){

}

Node* Tree::treeSearch(Node *node, int K){
    if(node == nullptr || node->getValue() == K){
        return node;
    }
    if(node->getValue() > K)
        return treeSearch(node->getLeftChild(), K);
    else
        return treeSearch(node->getRigthChild(), K);
}

Node* Tree::treeMinimum(Node *node){
    while(node->getLeftChild() != nullptr){
        node = node->getLeftChild();
    }
    return node;
}

Node* Tree::treeMaximum(Node *node){
    while(node->getRigthChild() != nullptr){
        node = node->getRigthChild();
    }
    return node;
}

Node* Tree::treeSuccessor(Node *node){
    if(node->getRigthChild() != nullptr){
        return treeMinimum(node->getRigthChild());
    }
    Node *y = node->getParent();
    while(y != nullptr && node == y->getRigthChild()){
        node = y;
        y = y->getParent();
    }

    return y;
}

Node* Tree::treePredecessor(Node *node){
    if(node->getLeftChild() == nullptr){
        return treeMaximum(node->getLeftChild());
    }
    Node *y = node->getParent();
    while(y != nullptr && node == y->getLeftChild()){
        node = y;
        y = y->getParent();
    }
    return y;
}

void Tree::treeInsert(Node *node){
    Node *y = nullptr;
    Node *x = this->root;

    while( x != nullptr){
        y = x;
        cout << node->getValue() << endl;
        cout << x->getValue() << endl;
        if(node->getValue() < x->getValue())
            x = x->getLeftChild();
        else
            x = x->getRigthChild();
    }
        
    node->setParent(y);
    if(y == nullptr){
        this->root = node;
    }
    else if(node->getValue() < y->getValue())
        y->setLeftChild(node);
    else 
        y->setRightChild(node);
}

void Tree::transplant(Node *u, Node *v){
    if(u->getParent() == nullptr)
        this->root = v;
    else if(u == u->getParent()->getLeftChild())
        u->getParent()->setLeftChild(v);
    else 
        u->getParent()->setRightChild(v);
    if(v != nullptr)
        v->setParent(u->getParent());
}

void Tree::treeDelete(Node *node){
    if(node->getLeftChild() == nullptr)
        transplant(node, node->getRigthChild());
    else if(node->getRigthChild() == nullptr)
        transplant(node, node->getLeftChild());
    else{
        Node *y = treeMinimum(node->getRigthChild());
        if(y->getParent() != node){
            transplant(y, y->getRigthChild());
            y->setRightChild(node->getRigthChild());
            y->getRigthChild()->setParent(y);
        }
        transplant(node, y);
        y->setLeftChild(node->getLeftChild());
        y->getLeftChild()->setParent(y);
    }
}

void Tree::setRoot(Node *node){
    this->root = node;
}

Node* Tree::getRoot(){
    return root;
}

void Tree::preOrderVisit(Node *node){
    if(node != nullptr){
        cout << node->getValue();
        preOrderVisit(node->getLeftChild());
        preOrderVisit(node->getRigthChild());
    }
}

#endif