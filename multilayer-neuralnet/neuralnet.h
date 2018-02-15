
#ifndef __NEURALNET__
#define __NEURALNET__

#include "matrix.h"

class NeuralNet{
public:
    

    NeuralNet(int inputs, int hidden, int outputs){
        n_inputs = inputs;
        n_hidden = hidden;
        n_outputs = outputs;
        weights_ih = new Matrix(n_hidden, n_inputs);
        weights_ho = new Matrix(n_outputs, n_hidden);
        bias_h = new Matrix(n_hidden, 1);
        bias_o = new Matrix(n_outputs, 1);

    }


private:
    int n_inputs, n_hidden, n_outputs;
    Matrix * weights_ih;
    Matrix * weights_ho;
    Matrix * bias_h;
    Matrix * bias_o;


};


#endif