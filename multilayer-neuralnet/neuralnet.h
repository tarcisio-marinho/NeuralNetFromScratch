
#ifndef __NEURALNET__
#define __NEURALNET__

#include "matrix.h"
#include<iostream>
#include<cmath>

using namespace std;

class NeuralNet{

public:
    int n_inputs, n_hidden, n_outputs; // number of nodes
    NeuralNet(int inputs, int hidden, int outputs);
    Matrix * feedfoward(Matrix * input);
    void train(Matrix * input, Matrix * targets);
    static float sigmoid(float x);
    static float derivate_sigmoid(float y);

    float (*apply_function)(float); // pointer to function
    Matrix * weights_ih; // weights of hidden layer
    Matrix * weights_ho; // weights of output layer
    Matrix * bias_h; // bias of hidden layer
    Matrix * bias_o; // bias of output layer


};


#endif