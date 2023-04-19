using namespace std;

#include <iostream>
#include "./lib/activity.hpp"
#include "./lib/GASHelper.hpp"

int main(int argc, char **argv){

    vector<Activity*> activity;
    int numAct;

    if(argc < 2){
        cout << "Errore input" << endl;
        return -1;
    }

    numAct = atoi(argv[1]);
    for(int i = 0; i < numAct; i++){
        int inizio, fine;
        cout << "Inserisci attività [" << i+1 << "] di " << numAct << endl;

        cout << "Inizio->";
        cin >> inizio;
        cout << "Fine->";
        cin >> fine;

        Activity *Act = new Activity(inizio, fine);
        activity.push_back(Act);
        
        cout << endl;
    }

    cout << "Stampo tutte le attività ordinate per tempo di fine (Inizio - Fine):" << endl;
    GasHelper *Gash = new GasHelper(activity);
    cout<<flush;
    Gash->GAS();
    cout << endl;
    cout << "Stampo le attività selezionate (Inizio - Fine):" << endl;
    Gash->printSelectedAct();
}