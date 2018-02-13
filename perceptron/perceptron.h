#ifndef __PERCEPTRON__
#define __PERCEPTRON__

#include<vector>
#include<random>
#include<cstdlib>

using namespace std;

class Perceptron{    

public:
    vector<float> weights;
    float learning_rate = 0.1;

    Perceptron(int number_weights){
        srand (static_cast <unsigned> (time(0)));
        for (int i = 0; i< number_weights; i++){
            weights.push_back(get_random());
        }
    }
    
    // activation function
    int sign(float number){
        if(number >= 0){
            return 1;
        }
        return -1;
    }

    // random numbers to initialize weights
    float get_random(){
        return -1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-(-1))));
    }

    // make a guess
    int guess(vector<float> inputs){
        float sum = 0;
        for (int i = 0; i<weights.size(); i++){
            sum += inputs[i] * weights[i];
        }
        
        return sign(sum);
    }

    // training method
    void train(vector<float> inputs, int target){
        // get a guess
        int guess_g = guess(inputs);
        // compute the error
        int error = target - guess_g;

        // backpropagation
        for (int i = 0; i < weights.size(); i ++){
            weights[i] += error * inputs[i] * learning_rate;
        }
    }

};

#endif