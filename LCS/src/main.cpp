using namespace std;

#include <iostream>
#include "./lib/lcs.hpp"

int main(int argc, char* argv[]){

    

    if(argc < 3){
        cout << "Errore input" << endl;
        return -1;
    }
    string x = argv[1];
    string y = argv[2];
    LCS *Lcs = new LCS(x, y);
    Lcs->calLCS();
    Lcs->printMatrix();
    cout << "Lunghezza LCS-> " << Lcs->getLCSLength() << " LCS String-> ";
    Lcs->printLCS(Lcs->getRows()-1, Lcs->getCols()-1);
    cout << endl;

}
