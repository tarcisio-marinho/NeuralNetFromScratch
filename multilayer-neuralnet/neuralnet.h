
#ifndef __NEURALNET__
#define __NEURALNET__

#include "matrix.h"
#include<iostream>
#include<cmath>

class NeuralNet{
public:
    int n_inputs, n_hidden, n_outputs; // number of nodes
    NeuralNet(int inputs, int hidden, int outputs);
    float (*sigmoid_func)(float); // pointer to function
    Matrix * weights_ih; // weights of hidden layer
    Matrix * weights_ho; // weights of output layer
    Matrix * bias_h; // bias of hidden layer
    Matrix * bias_o; // bias of output layer


};


#endif