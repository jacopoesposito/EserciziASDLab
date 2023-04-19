using namespace std;

#include<iostream>
#include<fstream>
#include<filesystem>
#include<list>
#include<algorithm>
#include"./lib/node.hpp"
#include"./lib/graph.hpp"

int main(int argc, char **argv){

    if(argc < 2){
        cout << "Errore input" << endl;
        return -1;
    }

    ifstream file;
    file.open(argv[1]);

    if(!file.is_open()){
        cout << "File doesn't exist" << endl;
        return -2;
    }
    
    list<Node *> nodes;
    Node* findValue;
    string idNode, destinationNode;
    while(file >> idNode >> destinationNode){

        list<Node *>::iterator iter = find_if(nodes.begin(), nodes.end(), [findValue](Node *value){
            return (findValue->getValue() == value->getValue());
        });

        if(iter != nodes.end()){
            
        }
    }
}