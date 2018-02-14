
#ifndef __MATRIX__
#define __MATRIX__

#include<vector> 
#include<iostream>

using namespace std;

class Matrix{

public:
    Matrix(int rows, int columns){
        n_rows = rows;
        n_columns = columns;

        for (int i=0; i < n_rows; i++){
            for(int j =0; j< n_columns; j++){
                matrix[i][j].push_back(0);
            }
        }
    }

    void print(){
        for (int i = 0; i< n_rows; i++){
            for (int j : matrix[i]){
                cout << j ; 
            }
            cout << "\n";
        }
    }


private:
    int n_rows, n_columns;
    vector<vector<int>> matrix;



    
};




#endif