#include "neuralnet.h"

NeuralNet::NeuralNet(int inputs, int hidden, int outputs){
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

/**
 * This feedfoward algorithm performs two weighted sums
 * First weighted sum -> (input * weights_hidden_layer) + bias_hidden_layer
 * Second weighted sum ->
 * output from (first weighted sum * weighted_output_layer) + bias_output
 */
Matrix * NeuralNet::feedfoward(Matrix * input){

    Matrix *hidden_layer_output, *output_layer_output;
    // Activation function
    apply_function = &NeuralNet::sigmoid;
    
    // Generating the hidden layer outputs
    hidden_layer_output = weights_ih->matmul(input);
    hidden_layer_output->matadd(bias_h);
    hidden_layer_output->map(apply_function);

    // Generating the output layer output
    output_layer_output = weights_ho->matmul(hidden_layer_output);
    output_layer_output->matadd(bias_o);
    output_layer_output->map(apply_function);
    
    return output_layer_output; // Probability output
}

void NeuralNet::train(Matrix * inputs, Matrix * targets){
    Matrix *hidden_layer_output, *output_layer_output;
    apply_function = &NeuralNet::sigmoid;
    
    /*  FeedFoward
        Input -> Hidden
    */

    // Generating the hidden layer outputs
    hidden_layer_output = weights_ih->matmul(inputs);
    hidden_layer_output->matadd(bias_h);
    
    // Activation function
    hidden_layer_output->map(apply_function);

    /*
        Hidden -> Ouput
    */

    // Generating the output layer output
    output_layer_output = weights_ho->matmul(hidden_layer_output);
    output_layer_output->matadd(bias_o);

    // Activation function
    output_layer_output->map(apply_function);

    /*
        BackPropagation
    */

    // Calculate the erro -> ERROR = TARGET - OUTPUTS
    Matrix * output_errors = targets->matsub(output_layer_output);

    // Calculate the hidden layer errors
    Matrix * weights_ho_transposed = weights_ho->transpose();
    Matrix * hidden_errors = weights_ho_transposed->matmul(output_errors);

}

// activation function
float NeuralNet::sigmoid(float x){
    return 1/(1 + exp(-x));
}

float NeuralNet::derivate_sigmoid(float y){
    return y * (1 - y);
}
