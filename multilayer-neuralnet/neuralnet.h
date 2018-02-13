
#ifndef __NEURALNET__
#define __NEURALNET__

class NeuralNet{
public:
    

    NeuralNet(int inputs, int hidden, int outputs){
        n_inputs = inputs;
        n_hidden = hidden;
        n_outputs = outputs;
    }


private:
    int n_inputs, n_hidden, n_outputs;




};


#endif