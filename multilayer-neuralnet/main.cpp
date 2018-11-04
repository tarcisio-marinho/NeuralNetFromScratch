#include "neuralnet.h"
#include "matrix.h"
#include<vector>
#include<iostream>
#include<cmath>

int main(int argc, char *argv[]){

    NeuralNet *n = new NeuralNet(2, 2, 1);
    Matrix *data = new Matrix(2, 1);
    Matrix *label = new Matrix(1, 1);
    n->fit(data, label);


    Matrix *output = n->predict(new Matrix(1, 1));
    output->print();
    
    // float (*foo)(float);
    // foo = &pi;

    return 0;
}