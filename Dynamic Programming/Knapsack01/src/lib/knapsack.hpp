using namespace std; 

#include <iostream>

#ifndef knapsack_hpp
#define knapsack_hpp

class KNP01{
    
    public:
        KNP01(int *value, int *weight, int rows, int W);
        void calKnapsack();
        int getMaxVal();
        void printMatrix();
    
    private:
        int rows, W;
        int **matrix_result;
        int *value;
        int *weight;
};

KNP01::KNP01(int *value, int *weight, int rows, int W){

    this->value = value;
    this->weight = weight;

    this->rows=rows;
    this->W = W;

    matrix_result = new int*[rows];
    for(int i = 0; i <= W; i++)
        matrix_result[i] = new int[W];

    for(int i=0; i <= rows; i++){
        for(int j=0; j <= W; j++){
            matrix_result[i][j] = 0;
        }
    }
}

int KNP01::getMaxVal(){
    return matrix_result[rows][W];
}

void KNP01::calKnapsack(){

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= W; j++){
            if(j < weight[i-1]){
                matrix_result[i][j] = matrix_result[i-1][j];
            }
            else if(matrix_result[i-1][j]>matrix_result[i-1][j-weight[i-1]]+value[i-1]){
                matrix_result[i][j]=matrix_result[i-1][j];
            }
            else 
                matrix_result[i][j]=matrix_result[i-1][j-weight[i-1]]+value[i-1];
        }
    }
}

void KNP01::printMatrix(){
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= W; j++){
            cout << matrix_result[i][j] << " ";
        }
        cout << endl;
    }
}
#endif