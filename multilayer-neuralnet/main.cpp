#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>

int main(int argc, char *argv[]){

    Matrix *m = new Matrix(2, 2, 3);
    Matrix *n = new Matrix(2, 2, 4);
    Matrix *c;
    m->print();

    n->print();
    c = n->matmul(m);
    c->print();

    
    return 0;
}