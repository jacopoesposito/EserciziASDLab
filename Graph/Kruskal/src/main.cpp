using namespace std;

#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <list>
#include"./lib/node.hpp"
#include"./lib/graph.hpp"
#include "./lib/edge.hpp"

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

    Graph *Grp = new Graph();

    string idNode, destinationNode, weigth;
    
    while(file >> idNode >> destinationNode >> weigth){
        int idNodeInt = stoi(idNode);
        int desNodeInt = stoi(destinationNode);
        int weigthInt = stoi(weigth);

        Node *firstNode;
        Node *secondNode;
        list<Node *> nodes = Grp->getNodes(); //Recupero la lista dei nodi già presenti nel grafo

        list<Node *>::iterator firstNodeIter = find_if(nodes.begin(), nodes.end(), [idNodeInt](Node* obj){ //Verifico che il nodo che intendo inserire sia presente
            return obj->getValue() == idNodeInt;
        });

        list<Node *>::iterator secondNodeIter = find_if(nodes.begin(), nodes.end(), [desNodeInt](Node* obj){ //Verifico che il nodo che intendo inserire sia presente
            return obj->getValue() == desNodeInt;
        });

        if(firstNodeIter == nodes.end()){ //Se non è presente nel grafo, allora devo aggiungerlo
            firstNode = new Node(idNodeInt);
            Grp->addNode(firstNode);
        }
        else{ //Altrimenti semplicemente recupero il riferimento dall'iteratore
            firstNode = (*firstNodeIter);
        }
        
        if(secondNodeIter == nodes.end()){
            secondNode = new Node(desNodeInt);
            Grp->addNode(secondNode);
            firstNode->setListAdiacenza(secondNode);
            secondNode->setListAdiacenza(firstNode);
        }else{
            secondNode = (*secondNodeIter);
            firstNode->setListAdiacenza(secondNode);
            secondNode->setListAdiacenza(firstNode);
        }

        Edge *edge = new Edge(firstNode, secondNode, weigthInt);
        Grp->addEdge(edge);
    }

    list<Node*> nodes = Grp->getNodes();
    list<Node*>::iterator iter;

    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        list<Node *>::iterator adjIter;
        list<Node *> adj = (*iter)->getListAdj();
        cout << " Nodi adiacenti a " << (*iter)->getValue() << " ";
        
        for(adjIter = adj.begin(); adjIter != adj.end(); ++adjIter){
            cout << (*adjIter)->getValue() << " ";
        }
        cout << endl;
    }

    Grp->Kruskal();
    list<Edge *> A = Grp->getMinPath();
    cout << "Nodo sorgente " << " Nodo Destinazione " << " Rando NS " << " Rango ND" << endl;
    list<Edge*>::iterator edgeIter;
    for(edgeIter = A.begin(); edgeIter != A.end(); ++edgeIter){
        cout << (*edgeIter)->getSource()->getValue() << " " << (*edgeIter)->getDestination()->getValue() << " " <<
        (*edgeIter)->getSource()->getDistance() << " " << (*edgeIter)->getDestination()->getDistance() << endl;
    }


}