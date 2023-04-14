#ifndef node_hpp
#define node_hpp


class Node{

    public:
        Node();
        Node(int frequency, unsigned char word);
        Node *getFather();
        Node *getLeftChild();
        Node *getRightChild();
        int getFreq();
        unsigned char getWord();
        void setFather(Node* father);
        void setLeftChild(Node* leftChild);
        void setRightChild(Node* rightChild);
        void setFrequency(int frequency);
        void setWord(unsigned char);

    private:
        Node *leftChild;
        Node *rightChild;
        Node *father;
        int frequency;
        unsigned char word;
};

Node::Node(){}

Node::Node(int frequency, unsigned char word){
    this->frequency = frequency;
    this->word = word;
    leftChild = nullptr;
    rightChild = nullptr;
}

Node* Node::getFather(){
    return father;
}

Node* Node::getLeftChild(){
    return leftChild;
}

Node* Node::getRightChild(){
    return rightChild;
}

int Node::getFreq(){
    return frequency;
}

unsigned char Node::getWord(){
    return word;
}

void Node::setFather(Node *father)
{
    this->father = father;
}

void Node::setFrequency(int frequency){
    this->frequency = frequency;
}

void Node::setLeftChild(Node* leftChild){
    this->leftChild = leftChild;
}

void Node::setRightChild(Node* rightChild){
    this->rightChild = rightChild;
}

void Node::setWord(unsigned char word){
    this->word = word;
}

#endif