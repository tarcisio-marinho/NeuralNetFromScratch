#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>
#include<typeinfo>

int main(int argc, char *argv[]){

    Matrix *m = new Matrix(2, 2);
    Matrix *n = new Matrix(2, 2);
    m->add(1);

    n->add(3);
    n->matadd(m);
    n->print();
    
    return 0;
}