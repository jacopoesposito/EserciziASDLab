using namespace std;

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "./lib/fastestway.hpp"

int main(int argc, char **argv){
    srand(time(NULL));

    if(argc < 2){
        cout << "Errore input" << endl;
        return -1;
    }

    int n = atoi(argv[1]); //Numero di stazioni nella catena di montaggio 
    int e[2] = {2, 4}, x[2] = {3, 2}; //Tempo di lavoro nelle stazioni iniziali array e, tempo di lavoro stazioni in uscita array x
    
    int **a, **t; 
    a = new int*[n]; //matrice contenente il tempo necessario per passare da una stazione j alla stazione j+1 sulla medesima linea i
    for(int i = 0; i < n; i++)
        a[i] = new int[2];
    
    t = new int*[n-1]; //matrice contenente il tempo necessario per passare da una linea all'altra 
    for(int i = 0; i < n-1; i++){
        t[i] = new int[2];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            int time = rand() % 10 + 1;
            cout<<time;
            a[i][j]=time;
        }
        cout<<endl;
    }
    cout << endl;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < 2; j++){
            int time = rand() % 10 + 1;
            cout<<time;
            t[i][j]= time;
        }
        cout<<endl;
    }

    FastestWay *FsWay = new FastestWay(n, a, t, e, x); 

    FsWay->calcFasWay();
    cout << "Tempo migliore->" << FsWay->getFFinal() << endl;
    cout << "Linea migliore->" << FsWay->getLFinal() << endl;
}