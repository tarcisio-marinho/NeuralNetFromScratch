#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>
#include<typeinfo>

int main(int argc, char *argv[]){

    Matrix *m = new Matrix(2, 2);
    m->add(1);
    m->mul(5);
    m->print();
    cout << typeid(m);

    return 0;
}