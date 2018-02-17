#include "matrix.h"

Matrix::Matrix(int rows, int columns){
    n_rows = rows;
    n_col = columns;
    srand (static_cast <unsigned> (time(0)));

    
    for(int i = 0; i < n_rows; i++){
        vector<float> novo;
        for (int j = 0; j < n_col; j++){
            novo.push_back(get_random());
        }
        matrix.push_back(novo);
    }
}

Matrix::float get_random(){
    return -1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-(-1))));
}

Matrix::void print(){
    for(int i = 0; i < n_rows; i++){
        for (int j=0; j < n_col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix::void add(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] += number;
        }
    }
}

Matrix::void sub(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] -= number;
        }
    }
}

Matrix::void mul(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] *= number;
        }
    }
}

Matrix::void matadd(Matrix *mat){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] += mat->matrix[i][j];
        }
    }
}

Matrix::void map(float (*func)(float)){

    for (int i = 0; i< n_rows; i++){
        for(int j = 0; j < n_col; j++){
            float valor = matrix[i][j];
            matrix[i][j] = func(valor);
        }
    }
}

Matrix::Matrix * matsub(Matrix *mat){
    Matrix * nova = new Matrix(n_rows, mat->n_col);
    
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            nova->matrix[i][j] = matrix[i][j] - mat->matrix[i][j];
        }
    }
    return nova;
}

Matrix::Matrix * matmul(Matrix *mat){
    if(n_col != mat->n_rows){
        return NULL;
    }else{
        Matrix * nova = new Matrix(n_rows, mat->n_col);
        
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

Matrix::Matrix * transpose(){
    Matrix * nova = new Matrix(n_col, n_rows);

    for(int i = 0; i< n_rows; i++){
        for(int j = 0; j< n_col; j++){
            nova->matrix[j][i] = matrix[i][j]; 
        }
    }
    return nova;
}