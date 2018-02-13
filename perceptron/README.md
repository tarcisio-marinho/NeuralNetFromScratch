# Perceptron model 

Implementing Perceptron model

![alt text](perceptron.png)

Perceptron is an one layer neural network.
It will try to understand the patter and map the function
Updating it's weights.

![alt text](download.png)




# Training Algorithm:

    Feed the perceptron with random data
    Train the network with the data
    Compute the error
    Adjust the weights according to the error
    Repeteat until all the dataset
    
    
# Activation function: 

    if(number >= 0){
        return 1;
    }
        return -1;

        
# Error function:

    error = label - guess
    
# Backpropagation: 
  
    learning_rate = 0.1
    weight[i] += error * input[i] * learning_rate
    
