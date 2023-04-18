using namespace std;

#include <iostream>
#include "./lib/knapsack.hpp"

int main(int argc, char **argv){
    srand(time(NULL));

    int *value, *weigth, objectsNumb, W;

    if(argc < 3){
        cout << "Errore input" << endl;
        return -1;
    }

    objectsNumb = atoi(argv[1]);
    W = atoi(argv[2]);

    value = new int[objectsNumb];
    weigth = new int[objectsNumb];

    for(int i = 0; i < objectsNumb; i++){
        value[i] = rand() % 10 + 1;
        cout << value[i] << endl;
    }
    cout << endl;

    for(int i = 0; i < objectsNumb; i++){
        weigth[i] = rand() % 10 + 1;
        cout << weigth[i] << endl;
    }

    cout << endl;

    KNP01 *Knp = new KNP01(value, weigth, objectsNumb, W);
    Knp->printMatrix();
    Knp->calKnapsack();
    
    cout << endl;

    Knp->printMatrix();
    cout << "Valore massimo zaino->" << Knp->getMaxVal() << endl;
}