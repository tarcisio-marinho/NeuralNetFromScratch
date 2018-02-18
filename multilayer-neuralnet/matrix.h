
#ifndef __MATRIX__
#define __MATRIX__

#include<vector> 
#include<ctime>
#include<iostream>

using namespace std;

class Matrix{

public:
    vector<vector<float> > matrix;

    Matrix(int rows, int columns);
    float get_random();
    void print();
    void add(float number);
    void sub(float number);
    void mul(float number);
    void matadd(Matrix *mat);
    void map(float (*func)(float));
    Matrix * matsub(Matrix *mat);
    Matrix * matmul(Matrix *mat);
    Matrix * transpose();
    static Matrix * fromArray(float vector[]);

private:
    int n_rows, n_col;
};

#endif