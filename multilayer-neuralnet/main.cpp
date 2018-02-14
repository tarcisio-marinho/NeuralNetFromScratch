#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>

int main(int argc, char *argv[]){

    Matrix *m = new Matrix(5, 5);
    m->print();

    return 0;
}