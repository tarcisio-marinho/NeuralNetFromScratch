
#ifndef __MATRIX__
#define __MATRIX__

#include<vector> 
#include<ctime>
#include<iostream>


class Matrix{
private: 
    float get_random();
    int n_rows, n_col;

public:
    std::vector<std::vector<float> > matrix;
    
    Matrix(int rows, int columns);
    Matrix(std::vector<std::vector<float> >);

    void print();
    void add(float number);
    void sub(float number);
    void mul(float number);
    void matadd(Matrix *mat);
    void map(float (*func)(float));
    static Matrix * map_static(Matrix * m, float (*func)(float));
    Matrix * matsub(Matrix *mat);
    Matrix * matmul(Matrix *mat);
    Matrix * transpose();
    static Matrix * fromArray(std::vector<float>);

};

#endif