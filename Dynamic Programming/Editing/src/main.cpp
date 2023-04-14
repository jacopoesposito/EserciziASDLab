using namespace std;

#include <iostream>
#include <string>
#include "./lib/editing.hpp"


int main(int argc, char* argv[]){

    string x = argv[1];
    string y = argv[2];

    EDITING *Editing = new EDITING(x, y);

    Editing->calEditing();
    Editing->printMatrix();
    cout << "Distanza di Editing fra: " << x << " e " << y << " uguale a: " << Editing->getEditingDis() << endl;

    return 1;
}