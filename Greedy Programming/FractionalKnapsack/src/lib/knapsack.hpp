using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
#include "object.hpp"

#ifndef knapsack_hpp
#define knapsack_hpp

class Knapsack
{
private:
    struct Comp{ //Ovveride del operatore di comparazione per supportare il sort degli oggetti
        bool operator()(Object *a, Object *b){
            return (a->getValue()/a->getWeigth())>=(b->getValue()/b->getWeigth());
        }
    };

    double Cap; //Capacità
    double val; //Valore dello zaino
    vector<Object *> objectsVec; //Vector rappresentante la lista completa degli oggetti
    vector<Object *> selObj; //Vector rappresentante gli oggetti selezionati
public:
    Knapsack(vector<Object *> objectsVec, int Cap);
    ~Knapsack();
    void KnCalc();
    double getVal();
};

Knapsack::Knapsack(vector<Object *> objectVec, int Cap)
{
    this->objectsVec = objectVec;
    val = 0.0;
    this->Cap = Cap;

    //Ordino gli oggetti nella lista in modo decrescente in base al rapporto v/w 
    sort(this->objectsVec.begin(), this->objectsVec.end(), Comp());
    vector<Object *>::iterator iter;

    for(iter = this->objectsVec.begin(); iter != objectsVec.end(); ++iter){
        cout << (*iter)->getValue()/(*iter)->getWeigth() << endl;
    }
}

Knapsack::~Knapsack()
{

}

void Knapsack::KnCalc(){
    vector<Object *>::iterator iter;
    for(iter = objectsVec.begin(); iter != objectsVec.end(); ++iter){ //Scorro la lista contente gli ogg ordinati
        if(Cap == 0)
            return;
        if((*iter)->getWeigth() < Cap){ //Se un oggetto pesa meno della capienza, posso prenderlo per intero
            selObj.push_back(*iter);
            val = val + (*iter)->getValue();
            Cap = Cap - (*iter)->getWeigth();
        }
        else{ //Se un ogg è più pesante della capienza allora devo prenderne una sua frazione e settare la capienza a zero
            double X = Cap/(*iter)->getWeigth(); 
            (*iter)->setWeigth(X);
            val = val + (*iter)->getValue() * X; //Calcolo il valore della frazione dell'ogg preso 
            Cap = 0.0;
            selObj.push_back(*iter);
        }
    }
}

double Knapsack::getVal(){
    return val;
}


#endif