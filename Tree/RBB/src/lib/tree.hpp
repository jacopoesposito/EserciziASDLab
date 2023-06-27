using namespace std;

#include <iostream>
#include "node.hpp"

#ifndef tree_hpp
#define tree_hpp

class Tree{

    private:
        Node *root;
    
    public:
        Tree(Node *root);
        void setRoot(Node *root);
        Node* treeSearch(Node *node, int k);
        Node* getRoot();
        Node* treeMinimum(Node *node);
        Node* treeMaximum(Node *node);
        Node* treeSuccessor(Node *node);
        Node* treePredecessor(Node *node);
        void leftRotate(Node *x);
        void rightRotate(Node *x);
        void treeInsert(Node *x);
        void RBTransplant(Node *u, Node *v);
        void RBDelete(Node *z);
        void RBDeleteFixUp(Node *x);
        void preOrderVisit(Node *node);
};

Tree::Tree(Node *root){
    this->root = root;
}

void Tree::setRoot(Node *root){
    this->root = root;
}

Node* Tree::getRoot(){
    return root;
}

Node* Tree::treeSearch(Node *node, int K){
    if(node == nullptr || node->getValue() == K){
        return node;
    }
    if(node->getValue() > K)
        return treeSearch(node->getLeftChild(), K);
    else
        return treeSearch(node->getRightChild(), K);
}

Node* Tree::treeMaximum(Node *node){
    while(node->getRightChild() != nullptr){
        node = node->getRightChild();
    }
    return node;
}

Node* Tree::treeMinimum(Node *node){
    while(node->getLeftChild() != nullptr){
        node = node->getLeftChild();
    }
    return node;
}

Node* Tree::treeSuccessor(Node *node){
    if(node->getRightChild() != nullptr){
        return treeMinimum(node->getRightChild());
    }
    Node *y = node->getParent();
    while(y != nullptr && node == y->getRightChild()){
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

void Tree::leftRotate(Node *x){
    Node *y = x->getRightChild();

    x->setRightChild(y->getLeftChild());
    if(y->getLeftChild() == nullptr){
        y->getLeftChild()->setParent(x);
    }
    y->setParent(x->getParent());
    if(x->getParent() == nullptr){
        this->root = y;
    }
    else if(x == x->getParent()->getLeftChild()){
        x->getParent()->setLeftChild(y);
    }
    else{
        x->getParent()->setRightChild(y);
    }

    y->setLeftChild(x);
    x->setParent(y);

}

void Tree::rightRotate(Node *x){
    Node *y = x->getLeftChild();

    x->setLeftChild(y->getRightChild());
    if(y->getRightChild() == nullptr){
        y->getRightChild()->setParent(x);
    }

    y->setParent(x->getParent());
    if(x->getParent() == nullptr){
        this->root = y;
    }
    else if(x == x->getParent()->getRightChild()){
        x->getParent()->setRightChild(y);
    }
    else{
        x->getParent()->setLeftChild(y);
    }

    y->setRightChild(x);
    x->setParent(y);    
}

void Tree::treeInsert(Node *x){
    x->setColor("red");

    while(x != this->root && x->getParent()->getColor() == "red"){
        if(x->getParent() == x->getParent()->getParent()->getLeftChild()){
            Node *y = x->getParent()->getParent()->getRightChild();
            if(y->getColor() == "red"){
                x->getParent()->setColor("black");
                y->setColor("black");
                x->getParent()->getParent()->setColor("red");
                x = x->getParent()->getParent();
            }
            else if(x == x->getParent()->getRightChild()){
                x = x->getParent();
                leftRotate(x);
                x->getParent()->setColor("black");
                x->getParent()->getParent()->setColor("red");
                rightRotate(x->getParent()->getParent());
            }
        }
        else{
            Node *y = x->getParent()->getParent()->getLeftChild();
            if(y->getColor() == "red"){
                x->getParent()->setColor("black");
                y->setColor("black");
                x->getParent()->getParent()->setColor("red");
                x = x->getParent()->getParent();
            }
            else if(x == x->getParent()->getLeftChild()){
                x = x->getParent();
                leftRotate(x);
                x->getParent()->setColor("black");
                x->getParent()->getParent()->setColor("red");
                rightRotate(x->getParent()->getParent());
            }

        }

    }
    this->root->setColor("black");
}

void Tree::RBTransplant(Node *u, Node *v){
    if(u->getParent() == nullptr){
        this->root = v;
    }
    else if( u == u->getParent()->getLeftChild()){
        u->getParent()->setLeftChild(v);
    }
    else{
        u->getParent()->setRightChild(v);
    }
    v->setParent(u);
}

void Tree::RBDelete(Node *z){
    Node *x;
    Node *y = z;
    string yOriginalColor = y->getColor();
    if(z->getLeftChild() == nullptr){
        x = z->getRightChild();
        RBTransplant(z, z->getRightChild());
    }
    else if(z->getRightChild() == nullptr){
        x = z->getLeftChild();
        RBTransplant(z, z->getLeftChild());
    }
    else{
        y = treeMinimum(z->getRightChild());
        yOriginalColor = y->getColor();
        x = y->getRightChild();
        if(y->getParent() == z){
            x->setParent(y);
        }
        else{
            RBTransplant(y, y->getRightChild());
            y->setRightChild(z->getRightChild());
            y->getRightChild()->setParent(y);
        }

    }
    if(yOriginalColor == "black")
        RBDeleteFixUp(x);
}

void Tree::RBDeleteFixUp(Node *x){
    while(x != this->root && x->getColor() == "black"){
        if(x == x->getParent()->getLeftChild()){
            Node *w = x->getParent()->getRightChild();
            if(w->getColor() == "red"){
                w->setColor("black");
                x->getParent()->setColor("red");
                leftRotate(x->getParent());
                w = x->getParent()->getRightChild();
            }
            if(w->getLeftChild()->getColor() == "black" && w->getRightChild()->getColor() == "black"){
                w->setColor("red");
                x = x->getParent();
            }
            else if(w->getRightChild()->getColor() == "black"){
                w->getLeftChild()->setColor("black");
                w->setColor("red");
                rightRotate(w);
                w = x->getParent()->getRightChild();
                w->setColor(x->getParent()->getColor());
                w->getParent()->setColor("black");
                w->getRightChild()->setColor("black");
                leftRotate(x->getParent());
                x = this->root;
            }
        }
        else{
            Node *w = x->getParent()->getLeftChild();
            if(w->getColor() == "red"){
                w->setColor("black");
                x->getParent()->setColor("red");
                leftRotate(x->getParent());
                w = x->getParent()->getLeftChild();
            }
            if(w->getRightChild()->getColor() == "black" && w->getLeftChild()->getColor() == "black"){
                w->setColor("red");
                x = x->getParent();
            }
            else if(w->getLeftChild()->getColor() == "black"){
                w->getRightChild()->setColor("black");
                w->setColor("red");
                rightRotate(w);
                w = x->getParent()->getLeftChild();
                w->setColor(x->getParent()->getColor());
                w->getParent()->setColor("black");
                w->getLeftChild()->setColor("black");
                leftRotate(x->getParent());
                x = this->root;
            }

        }
    }
    x->setColor("black");
}


void Tree::preOrderVisit(Node *node){
    if(node != nullptr){
        cout << node->getValue();
        preOrderVisit(node->getLeftChild());
        preOrderVisit(node->getRightChild());
    }
}

#endif