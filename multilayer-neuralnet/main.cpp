#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>

int main(int argc, char *argv[]){

    Matrix *m = new Matrix(4, 2, 3);
    m->print();
    cout << endl;
    Matrix *c = m->transpose();
    c->print();

    
    return 0;
}