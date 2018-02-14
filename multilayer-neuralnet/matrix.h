
#ifndef __MATRIX__
#define __MATRIX__

#include<vector> 
#include<iostream>

using namespace std;

class Matrix{

public:
    
    int n_rows, n_col;
    vector<vector<float> > matrix;

    Matrix(int rows, int columns, float start){
        n_rows = rows;
        n_col = columns;

        
        for(int i = 0; i < n_rows; i++){
            vector<float> novo;
            for (int j = 0; j < n_col; j++){
                novo.push_back(start);
            }
            matrix.push_back(novo);
        }
        
    }

    void print(){
        for(int i = 0; i < n_rows; i++){
            for (int j=0; j < n_col; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(float number){
        for (int i=0; i < n_rows; i++){
            for(int j = 0; j < n_col; j++){
                matrix[i][j] += number;
            }
        }
    }

    void mul(float number){
        for (int i=0; i < n_rows; i++){
            for(int j = 0; j < n_col; j++){
                matrix[i][j] *= number;
            }
        }
    }

    void matadd(Matrix *mat){
        for (int i=0; i < n_rows; i++){
            for(int j = 0; j < n_col; j++){
                matrix[i][j] += mat->matrix[i][j];
            }
        }
    }

    Matrix * matmul(Matrix *mat){
        if(n_col != mat->n_rows){
            return NULL;
        }else{
            Matrix * nova = new Matrix(n_rows, mat->n_col, 0);
            
            for(int i = 0; i < nova->n_rows; i++){
                for(int j = 0; j < nova->n_col; j++){
                    float sum = 0;
                    for(int  k = 0; k < n_col; k++){
                        sum +=matrix[i][k]* mat->matrix[k][j]; 
                    }
                    nova->matrix[i][j] = sum;
                }
            }
            return nova;


        }
    }

};




#endif