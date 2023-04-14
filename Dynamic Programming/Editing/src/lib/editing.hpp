using namespace std;

#include <string>
#include <iostream>

class EDITING{

    public:
        EDITING(string x, string y);
        void calEditing();
        void printMatrix();
        int getRows();
        int getCols();
        int getEditingDis();
        ~EDITING();
    private:
        string x, y;
        int rows, cols;
        int **matrix_score;
        string **matrix_path;
};

EDITING::EDITING(string x, string y){
    this->x=x;
    this->y=y;

    this->rows=x.length();
    this->cols=y.length();
    cout << rows << " " << cols << endl;

    matrix_score = new int*[rows];
    for(int i=0; i<=rows; i++)
        matrix_score[i] = new int[cols];

    matrix_path = new string*[rows];
    for(int i=0; i<=rows; i++)
        matrix_path[i] = new string[cols];
}

int EDITING::getCols(){
    return cols;
}

int EDITING::getRows(){
    return rows;
}

int EDITING::getEditingDis(){
    return matrix_score[rows][cols];
}

void EDITING::calEditing(){
    for(int i = 0; i <= rows; i++){
        matrix_score[i][0]=i;
    }
    for(int i = 0; i <= cols; i++){
        matrix_score[0][i]=i;
    }

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            if(x[i-1] == y[j-1]){
                matrix_score[i][j]=matrix_score[i-1][j-1];
            }
            else{
                int minimum = min(matrix_score[i-1][j-1], matrix_score[i-1][j]);
                matrix_score[i][j]=1+min(minimum, matrix_score[i][j-1]);
            }
            
        }
    }    
}

void EDITING::printMatrix(){
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            cout << matrix_score[i][j];
        }
        cout << endl;
    }
}