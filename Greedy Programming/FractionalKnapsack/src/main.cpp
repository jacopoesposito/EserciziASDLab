using namespace std;


#include <iostream>
#include "./lib/knapsack.hpp"
#include "./lib/object.hpp"

int main(int argc, char **argv){
    srand(time(NULL));

    if(argc < 3){
        cout << "Errore input" << endl;
        return -1;
    }

    int numObj = atoi(argv[1]);
    int cap = atoi(argv[2]);
    vector<Object *> objVec;

    cout << "Genero e stampo oggetti (Valore - Peso)" << endl;
    for(int i = 0; i < numObj; i++){
        Object *Obj = new Object(rand() % 20 + 1, rand() % 20 + 1);
        cout << Obj->getValue() << " " <<Obj->getWeigth() << endl;
        objVec.push_back(Obj);
    }

    cout << "Stampo ogg ordinati in ordine decrescente rispetto a v/w" << endl;
    Knapsack *Knp = new Knapsack(objVec, cap);
    Knp->KnCalc();
    cout << "Valore zaino->" << Knp->getVal() << endl;
}