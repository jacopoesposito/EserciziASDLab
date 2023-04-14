#include "node.hpp"

#ifndef tree_hpp
#define tree_hpp

class Tree{

    public:
        void treeInsert(Node *node);

    private:
        Node *root;
        Node *nil = nullptr;
};

void Tree::treeInsert(Node *newNode){
    Node *y = nullptr;
    Node *x = this->root;
    
    while(x!=nullptr){
        y = x;
        if(newNode->getFreq() < x->getFreq()){
            x = x->getLeftChild();
        }
        else{
            x = x->getLeftChild();
        }
    }

    newNode->setFather(y);

    if(y==nullptr){
        root = newNode;
    }
    else if(newNode->getFreq()<y->getFreq()){
        y->setLeftChild(newNode);
    }else{
        y->setRightChild(newNode);
    }
    
}
#endif