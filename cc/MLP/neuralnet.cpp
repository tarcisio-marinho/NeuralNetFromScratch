#include "neuralnet.h"

void print(int a){
    std::cerr << a <<std::endl;
}

NeuralNet::NeuralNet(int inputs, int hidden, int outputs, float lr){
    this->n_inputs = inputs;
    this->n_hidden = hidden;
    this->n_outputs = outputs;
    
    // weights matrixes
    this->weights_ih = new Matrix(n_hidden, n_inputs);
    this->weights_ho = new Matrix(n_outputs, n_hidden);

    // biases 
    this->bias_h = new Matrix(n_hidden, 1);
    this->bias_o = new Matrix(n_outputs, 1);
    this->learning_rate = lr;
    this->n_epochs = n_epochs;

    // Activation function
    this->apply_function = &NeuralNet::sigmoid;
    this->apply_function2 = &NeuralNet::derivate_sigmoid;
   
}

/**
 * This feedfoward algorithm performs two weighted sums
 * First weighted sum -> (input * weights_hidden_layer) + bias_hidden_layer
 * Second weighted sum ->
 * output from (first weighted sum * weighted_output_layer) + bias_output
 */
Matrix * NeuralNet::predict(Matrix * input){

    // Generating the hidden layer outputs
    Matrix *hidden_layer_output = weights_ih->matmul(input);
    hidden_layer_output->matadd(bias_h);
    hidden_layer_output->map(apply_function);

    // Generating the output layer output
    Matrix* output_layer_output = weights_ho->matmul(hidden_layer_output);
    output_layer_output->matadd(bias_o);
    output_layer_output->map(apply_function);
    
    return output_layer_output; // Probability output
}

// Train the neuralnet 
void NeuralNet::fit(Matrix * inputs, Matrix * targets){

    /*  FeedFoward
        Input -> Hidden
    */
    // Generating the hidden layer outputs
    Matrix *hidden_layer_output = weights_ih->matmul(inputs);
    hidden_layer_output->matadd(bias_h); 
    
    // Activation function
    hidden_layer_output->map(apply_function);
    /*
        Hidden -> Ouput
    */

    // Generating the output layer output
    Matrix* output_layer_output = weights_ho->matmul(hidden_layer_output);
    output_layer_output->matadd(bias_o);
    // Activation function
    output_layer_output->map(apply_function);

    /*
        BackPropagation
    */

    // Calculate the erro -> ERROR = TARGET - OUTPUTS
    Matrix * output_errors = targets->matsub(output_layer_output);
    
    // Calculate gradient
    Matrix * gradients = Matrix::map_static(output_layer_output, apply_function2);
    gradients->matmul(output_errors);
    gradients->mul(learning_rate);

    // Calculate deltas
    Matrix * hidden_transposed = hidden_layer_output->transpose();
    Matrix * weight_ho_deltas = gradients->matmul(hidden_transposed);
    
    // adjust the weights by deltas
    weights_ho->matadd(weight_ho_deltas);
    
    // adjust the bias by its deltas
    bias_o->matadd(gradients);
    

    // Calculate the hidden layer errors
    Matrix * weights_ho_transposed = weights_ho->transpose();
    weight_ho_deltas->print();
    weight_ho_deltas->print_rows_cols();
    output_errors->print();
    output_errors->print_rows_cols();
    Matrix * hidden_errors = weights_ho_transposed->matmul(output_errors); // ta retornando nulo

    // Calculate hidden gradient
    Matrix * hidden_gradient = Matrix::map_static(hidden_layer_output, apply_function2);
    hidden_gradient->matmul(hidden_errors); // PAU
    hidden_gradient->mul(learning_rate);

    // Calculate input -> hidden deltas
    Matrix * inputs_transposed = inputs->transpose();
    Matrix * weight_ih_deltas = hidden_gradient->matmul(inputs_transposed);

    // update the weights
    weights_ih->matadd(weight_ih_deltas);

    // update the bias
    bias_h->matadd(hidden_gradient);
}

// activation function
float NeuralNet::sigmoid(float x){
    return 1/(1 + exp(-x));
}

// derivate of the activation function for back propagation
float NeuralNet::derivate_sigmoid(float y){
    return y * (1 - y);
}

// Funciton to store on disk the neuralnet state
void NeuralNet::save_neuralnet(NeuralNet * n, const char * name){
    FILE *f;
    f = fopen(name, "wb");
    if(f != NULL){
        fwrite(n, sizeof(n), 1, f);
    }

    fclose(f);
}

// Function to load from disk a neuralnet
NeuralNet * NeuralNet::load_neuralnet(const char *path){
    NeuralNet *n;
    FILE *f;
    f = fopen(path, "rb");
    if(f != NULL){
        fread(n, sizeof(n), 1, f);
    }
    fclose(f);
    return n;
}