using namespace std;
#include "frequencyCalculation.hpp"
#include "tree.hpp"
#include "node.hpp"
#include "queue"

#ifndef huffman_hpp
#define huffman_hpp

class Huffman
{
    private:
        struct Comp{ //Ovveriding the comparison operator to allow minqueue with the custom object node
            bool operator()(Node *a, Node *b){
                return a->getFreq()>b->getFreq();
            }
        };
        FrequencyCalculation *FreqCalc;
        priority_queue<Node*, vector<Node*>, Comp> nodeQueue;
        Node *root;
        map<unsigned char, string> encodedDictionary;
        string encodedString;
        string decodedString;
        float bitEncodedString;
        int bitOriginalString;
    
    public:
        Huffman(FrequencyCalculation *FreqCalc);
        Node* genereteHFTree();
        void createHFDictionary(Node *root, string str);
        void encodeHuffman();
        void decodeHuffman();
        Node* getRoot();
        string getEncodedString();
        void setRoot(Node *root);
        string getDecodedString();
        int getBitOriginalString();
        float getBitEncodedString();
        void calculateBitsSaving();
        ~Huffman();
};

Huffman::Huffman(FrequencyCalculation *FreqCalc)
{
    this->FreqCalc = FreqCalc;
}

Huffman::~Huffman()
{
}

void Huffman::setRoot(Node *root){
    this->root = root;
}

Node* Huffman::getRoot(){
    return root;
}

string Huffman::getEncodedString(){
    return encodedString;
}

string Huffman::getDecodedString(){
    return decodedString;
}

float Huffman::getBitEncodedString(){
    return bitEncodedString;
}

int Huffman::getBitOriginalString(){
    return bitOriginalString;
}

// Generate the HF Tree
Node* Huffman::genereteHFTree(){
    
    map<unsigned char, int> freqChar = FreqCalc->getFreq();

    for(auto it = freqChar.cbegin(); it != freqChar.cend(); ++it){
        Node *z = new Node((it)->second, (it)->first);
        nodeQueue.push(z);
    }
    
    while(!nodeQueue.empty()){
        Node *z = new Node();
        Node *x = nodeQueue.top();
        nodeQueue.pop();
        Node *y = nodeQueue.top();
        nodeQueue.pop();
        z->setFrequency(x->getFreq()+y->getFreq());

        z->setLeftChild(x);
        z->setRightChild(y);
        nodeQueue.push(z);
    }

    return nodeQueue.top();
}

/*
    Explore the HF tree to retrieve the HF code for all the character of the given input, then store it inside a map
*/
void Huffman::createHFDictionary(Node* root, string encString){ 
    if(root->getLeftChild()==nullptr && root->getRightChild()==nullptr){
        map<unsigned char, string>::iterator encDicIter = encodedDictionary.find(root->getWord());
        if(encDicIter == encodedDictionary.end()){
            cout << root->getWord() << " " << encString <<endl;
            encodedDictionary[root->getWord()]=encString;
        }
        return;
    }
    
    createHFDictionary(root->getLeftChild(), encString+"0");
    createHFDictionary(root->getRightChild(), encString+"1");
}

/*
    Use the map containing the HF code corresponding to each 
    character of the input file, to generate the encoded string containing the input characters
*/
void Huffman::encodeHuffman(){
    vector<unsigned char>::iterator iter;
    vector<unsigned char>vecBuff = FreqCalc->getBufferInput();
    
    for(iter = vecBuff.begin(); iter != vecBuff.end(); ++iter){
        map<unsigned char, string>::iterator encDicIter = encodedDictionary.find(*iter);
        encodedString+=encDicIter->second;
    }
}

void Huffman::decodeHuffman(){
    string tmp;
    char zero='0';
    Node *curr = root;

    string::iterator it;
    for(it = encodedString.begin(); it != encodedString.end(); ++it){
        if(*it==zero){
            curr = curr->getLeftChild();
        }
        else{
            curr = curr->getRightChild();
        }
        if(curr->getRightChild()==nullptr && curr->getLeftChild()==nullptr){
            tmp+=curr->getWord();
            curr=root;
        }
    }
    decodedString = tmp;
}

void Huffman::calculateBitsSaving(){
    map<unsigned char, int>freqChar = FreqCalc->getFreq();
    for(auto it = freqChar.cbegin(); it != freqChar.end(); ++it){
        //cout << 12*(it->second/100.0) << endl;
        float number = it->second/100.0;
        bitEncodedString+=(4.0*(number));
    }
    bitOriginalString=4.0*7;

}



#endif