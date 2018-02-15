
#ifndef __NEURALNET__
#define __NEURALNET__

#include "matrix.h"
#include<cmath>

class NeuralNet{
public:
    

    NeuralNet(int inputs, int hidden, int outputs){
        n_inputs = inputs;
        n_hidden = hidden;
        n_outputs = outputs;
        
        // weights matrixes
        weights_ih = new Matrix(n_hidden, n_inputs);
        weights_ho = new Matrix(n_outputs, n_hidden);

        // biases 
        bias_h = new Matrix(n_hidden, 1);
        bias_o = new Matrix(n_outputs, 1);

    }

    float feedfoward(Matrix * input){

        // Generating the hidden outputs
        Matrix * hidden = weights_ih->matmul(input);
        hidden->matadd(bias_h);

        // Activation function
        float (*sigmoid_func)(float);
        sigmoid_func = &sigmoid;
        hidden->map(sigmoid_func);
    }

    // activation function
    float sigmoid(float x){
        return 1/(1 + exp(-x));
    }


private:
    int n_inputs, n_hidden, n_outputs;
    Matrix * weights_ih;
    Matrix * weights_ho;
    Matrix * bias_h;
    Matrix * bias_o;


};


#endif