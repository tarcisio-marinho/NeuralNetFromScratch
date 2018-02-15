#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>
#include<cmath>

int main(int argc, char *argv[]){

    NeuralNet *n = new NeuralNet(2, 2, 1);
    Matrix *m = new Matrix(2, 1);
    Matrix * output;
    output = n->feedfoward(m);
    output->print();
    
    // float (*foo)(float);
    // foo = &pi;

    return 0;
}