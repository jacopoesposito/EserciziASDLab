using namespace std;

#include<iostream>
#include<fstream>
#include<filesystem>
#include<list>
#include<algorithm>
#include<limits>
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
    
    Graph *Grp = new Graph();

    string idNode, destinationNode;
    while(file >> idNode >> destinationNode){
        int idNodeInt = stoi(idNode);
        int desNodeInt = stoi(destinationNode);

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
            firstNode = new Node(idNodeInt, false, "white");
            Grp->AddNode(firstNode);
        }
        else{ //Altrimenti semplicemente recupero il riferimento dall'iteratore
            firstNode = (*firstNodeIter);
        }
        
        if(secondNodeIter == nodes.end()){
            secondNode = new Node(desNodeInt, false, "white");
            Grp->AddNode(secondNode);
            firstNode->setListAdiacenza(secondNode);
        }else{
            secondNode = (*secondNodeIter);
            firstNode->setListAdiacenza(secondNode);
        }

        
    }

    list<Node*> nodes = Grp->getNodes();
    list<Node *>::iterator iter;

    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        list<Node *>::iterator adjIter;
        list<Node *> adj = (*iter)->getListAdj();
        cout << " Nodi adiacenti a " << (*iter)->getValue() << " ";
        for(adjIter = adj.begin(); adjIter != adj.end(); ++adjIter){
            cout << (*adjIter)->getValue() << " ";
        }
        cout << endl;
    }

    cout << "Valore - Padre - Distanza" << endl;
    Grp->BFS(nodes.front());
    for(iter = nodes.begin(); iter != nodes.end(); ++iter){
        if(((*iter)->getParent() == nullptr) && (*iter)->getDistance() != numeric_limits<int>::max())
            cout << (*iter)->getValue() << "   " << "NULL" << "   " << (*iter)->getDistance() << endl;
        else if((*iter)->getDistance() == numeric_limits<int>::max())
            cout << (*iter)->getValue() << "   " << "NULL" << "   " << "NON RAGGIUNGIBILE" << endl;
        else
            cout << (*iter)->getValue() << "   " << (*iter)->getParent()->getValue() << "   " << (*iter)->getDistance() << endl;
    }

    return 0;
}