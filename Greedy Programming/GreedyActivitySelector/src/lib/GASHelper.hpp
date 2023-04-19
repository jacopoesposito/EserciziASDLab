using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
#include "activity.hpp"

#ifndef gashelper_hpp
#define gashelper_hpp

//Classe helper contenente tutti i metodi e gli attributi necessari all'esecuzione di un greedy activity selector

class GasHelper{

    public:
        GasHelper(vector<Activity*> unorderedActivity);
        void printSelectedAct();
        void GAS();

    private:
        struct Comp{ //Ovveride del operatore di comparazione per supportare il sort delle attività
            bool operator()(Activity *a, Activity *b){
                if(a->getEnd()==b->getEnd())
                    return a->getStart()<b->getStart();
                return a->getEnd()<b->getEnd();
            }
        };

        vector<Activity*> unorderedActivity; //Vettori contenenti tutte le attività e quelle selezionate
        vector<Activity*> selectedActivity;

};

GasHelper::GasHelper(vector<Activity*> unorderedActivity){
    this->unorderedActivity = unorderedActivity; 

    //Uso del metodo sorting per ordinare le attivita per tempo di fine crescente 
    sort(this->unorderedActivity.begin(), this->unorderedActivity.end(), Comp());
    vector<Activity*>::iterator iter;
    for(iter = this->unorderedActivity.begin(); iter != this->unorderedActivity.end(); ++iter){
        cout << (*iter)->getStart() << " - " << (*iter)->getEnd() << endl;
    }
}

void GasHelper::GAS(){
    selectedActivity.push_back(*unorderedActivity.begin());

    vector<Activity*>::iterator iter;
    vector<Activity*>::iterator k = unorderedActivity.begin();
    
    for(iter = next(unorderedActivity.begin()); iter != unorderedActivity.end(); ++iter){
        if((*iter)->getStart()>=(*k)->getEnd()){
            selectedActivity.push_back(*iter);
            k = iter;
        }
    }
}

void GasHelper::printSelectedAct(){
    vector<Activity*>::iterator iter;
    for(iter = selectedActivity.begin(); iter != selectedActivity.end(); ++iter){
        cout << (*iter)->getStart() << " - " << (*iter)->getEnd() << endl;
    }
}
#endif