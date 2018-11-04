
#ifndef __NEURALNET__
#define __NEURALNET__

#include "matrix.h"
#include<iostream>
#include<cmath>

using namespace std;

class NeuralNet{
private:
    int n_inputs, n_hidden, n_outputs; // number of nodes
    int n_epochs;
    float learning_rate;
    Matrix * weights_ih; // weights of hidden layer
    Matrix * weights_ho; // weights of output layer
    Matrix * bias_h; // bias of hidden layer
    Matrix * bias_o; // bias of output layer

    static float sigmoid(float x);
    static float derivate_sigmoid(float y);
    float (*apply_function)(float); // pointer to function sigmoid
    float (*apply_function2)(float); // pointer to function derivate_sigmoid
    
public:
    NeuralNet(int inputs, int hidden, int outputs, float lr=0.1, int n_epochs=50);
    Matrix * predict(Matrix * input);
    void fit(Matrix * input, Matrix * targets);
    static void save_neuralnet(NeuralNet * n, const char * name);
    static NeuralNet * load_neuralnet(const char *path);



};


#endif