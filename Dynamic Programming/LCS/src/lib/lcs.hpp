using namespace std;

#include <string>
#include <iostream>

#ifndef LCS_CLASS
#define LCS_CLASS

class LCS{
    
    public:
        LCS(string x, string y);
        void printMatrix();
        void calLCS();
        void printLCS(int i, int j);
        int getLCSLength();
        int getRows();
        int getCols();
        ~LCS();
    private:
        string x, y;
        int rows, cols;
        int **matrix_score;
        string **matrix_path;
};


LCS::LCS(string x, string y){
    this->x=x;
    this->y=y;

    this->rows=x.length();
    this->cols=y.length();
    cout<< rows << " " << cols << endl;
    matrix_score = new int*[rows];
    for(int i=0; i<=rows; i++)
        matrix_score[i] = new int[cols+1];

    matrix_path = new string*[rows];
    for(int i=0; i<=rows; i++)
        matrix_path[i] = new string[cols+1];
}

int LCS::getLCSLength(){
    return matrix_score[rows][cols];
}

int LCS::getRows(){
    return rows;
}

int LCS::getCols(){
    return cols;
}

void LCS::calLCS(){
    for(int i = 0; i <= rows; i++){
        matrix_score[i][0]=0;
    }
    for(int i = 0; i <= cols; i++){
        matrix_score[0][i]=0;
    }

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            if(x[i-1] == y[j-1]){
                matrix_score[i][j]=matrix_score[i-1][j-1]+1;
                matrix_path[i][j]="\\";
            }
            else if(matrix_score[i-1][j]>=matrix_score[i][j-1]){
                matrix_score[i][j]=matrix_score[i-1][j];
                matrix_path[i][j]="|";
            }else{
                matrix_score[i][j]=matrix_score[i][j-1];
                matrix_path[i][j]="<";
            }
        }
    }    
}

void LCS::printMatrix(){
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            cout << matrix_score[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            cout << matrix_path[i][j] << " ";
        }
        cout<<endl;
    }
}

void LCS::printLCS(int i, int j){
    if(i == 0 || j == 0)
        return;
    if(matrix_path[i][j]=="\\"){
        printLCS(i-1, j-1);
        cout << x[i-1];
    }
    else if(matrix_path[i][j]=="|"){
        printLCS(i-1, j);
    }
    else{
        printLCS(i, j-1);
    }
}

#endif 