#include "matrix.h"

void Matrix::print_rows_cols(){
    std::cout  << "Rows: " << this->n_rows << " Col: " << this->n_col << std::endl;
}


Matrix::Matrix(int rows, int columns){
    n_rows = rows;
    n_col = columns;
    srand (static_cast <unsigned> (time(0)));

    
    for(int i = 0; i < n_rows; i++){
        std::vector<float> novo;
        for (int j = 0; j < n_col; j++){
            novo.push_back(get_random());
        }
        matrix.push_back(novo);
    }
}

Matrix::Matrix(std::vector<std::vector<float> > mat ){
    this->matrix = mat;
    this->n_rows = mat.size();
    this->n_col = mat[0].size();
}


// Return random float number
float Matrix::get_random(){
    return -1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-(-1))));
}

// Print the matrix
void Matrix::print(){
    for(int i = 0; i < n_rows; i++){
        for (int j=0; j < n_col; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Add scalar number to matrix
void Matrix::add(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] += number;
        }
    }
}

// Sub scalar number to matrix
void Matrix::sub(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] -= number;
        }
    }
}


// Multiply scalar number to matrix
void Matrix::mul(float number){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] *= number;
        }
    }
}

// Add two matrixes
void Matrix::matadd(Matrix *mat){
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            matrix[i][j] += mat->matrix[i][j];
        }
    }
}

// Apply function to all elements from matrix
void Matrix::map(float (*func)(float)){

    for (int i = 0; i< n_rows; i++){
        for(int j = 0; j < n_col; j++){
            float valor = matrix[i][j];
            matrix[i][j] = func(valor);
        }
    }
}


Matrix * Matrix::map_static(Matrix * m, float (*func)(float)){
    Matrix * nova = new Matrix(m->n_rows, m->n_col);

    for (int i = 0; i < m->n_rows; i++){
        for (int j = 0; j < m->n_col; j++){
            float valor = m->matrix[i][j];
            nova->matrix[i][j] = valor;
        }
    }
    return nova;
}

// Sub two matrixes
Matrix * Matrix::matsub(Matrix *mat){
    Matrix * nova = new Matrix(n_rows, mat->n_col);
    
    for (int i=0; i < n_rows; i++){
        for(int j = 0; j < n_col; j++){
            nova->matrix[i][j] = matrix[i][j] - mat->matrix[i][j];
        }
    }
    return nova;
}

// Multiply two matrixes
Matrix * Matrix::matmul(Matrix *mat){
    if(n_col != mat->n_rows){
        throw "n_col != n_rols";

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


// The transpose of a matrix
Matrix * Matrix::transpose(){
    Matrix * nova = new Matrix(n_col, n_rows);

    for(int i = 0; i< n_rows; i++){
        for(int j = 0; j< n_col; j++){
            nova->matrix[j][i] = matrix[i][j]; 
        }
    }
    return nova;
}


// Create a new Matrix from an std::vector
Matrix * Matrix::fromArray(std::vector<float> vector){
    Matrix * nova = new Matrix(vector.size(), 1);
    for (int i = 0; i < vector.size(); i++){
        nova->matrix[i][0] = vector[i];
    }
    return nova;
}
