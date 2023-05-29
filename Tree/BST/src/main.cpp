using namespace std;

#include<vector>
#include <iostream>
#include <fstream>
#include"lib/node.hpp"
#include"lib/tree.hpp"

void displayMenu(){
    cout << "\n******************************************";
    cout << "\n**         Binary Tree                  **";
    cout << "\n**                                      **";
    cout << "\n** ------------------------------------ **";
    cout << "\n**                Menu                  **";
    cout << "\n**         1) Aggiungi nodo             **";
    cout << "\n**         2) Rimuovi nodo              **";
    cout << "\n**         3) Trova nodo                **";
    cout << "\n**         4) Mostra menu               **";
    cout << "\n**         5) Esci                      **";
    cout << "\n**         6) Stampa BST                **";
    cout << "\n******************************************";
}

int main(int argc, char **argv){
    bool exec = true;
    int scelta, valueBSTNode;

    if(argc < 2){
        cout << "Errore input" << endl;
        return -1;
    }

    string name;
    ifstream file;

    file.open(argv[1]);

    Tree *tree = new Tree();
    
    if(!file.is_open()){
        cout << "File doesn't exist" << endl;
        return -2;
    }

    Node *firstNode = new Node(0);
    tree->setRoot(firstNode);

    string value;
    while(file >> value){
        int valueInt = stoi(value);

        Node *node = new Node(valueInt);
        node->getValue();
        tree->treeInsert(node);
        tree->getRoot();

    }

    do{
        cout << "\nScelta-> ";
        cin >> scelta;

        switch(scelta){
            case 1:
            {
                cout << "Aggiungi nodo a BST" << endl;
                cin >> valueBSTNode;
                Node *node = new Node(valueBSTNode);
                tree->treeInsert(node);
            break;
            }
            case 2:
            {
                cout << "Rimuovi nodo da BST" << endl;
                cout << "Inserisci valore nodo da eliminare-> ";
                cin >> valueBSTNode;
                cout << endl;
                Node *nodeToDel = tree->treeSearch(tree->getRoot(), valueBSTNode);
                if(nodeToDel != nullptr)
                    tree->treeDelete(nodeToDel);
            break;
            }
            case 3:
            {
                cout << "Cerca nodo su BST" << endl;
                cout << "Inserisci valore nodo da cercare-> ";
                cin >> valueBSTNode;
                cout << valueBSTNode << endl;
                Node *node = tree->treeSearch(tree->getRoot(), valueBSTNode);
                if(node == nullptr)
                    cout << "Nodo non trovato" << endl;
                else 
                    cout << "Valore nodo = " << node->getValue() << " Padre: " << node->getParent() << endl;
            break;
            }
            case 4:
            {
                cout << "Mostra menu" << endl;
                displayMenu();
            break;
            }
            case 5:
            {
                cout << "Esco..." << endl;
                exec = false;
            break;
            }
            case 6:
            {
                cout << "Stampo albero" << endl;
                tree->preOrderVisit(tree->getRoot());
                cout << endl;
            break;
            }
        }

    }
    while(exec);

    return 0;
}