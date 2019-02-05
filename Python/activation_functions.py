
import numpy as np
import math




def sigmoid(x):
    return 1 / 1 + np.exp(-x) 

def softmax(x):
    return np.exp(x) / np.sum(np.exp(x))

def tanh(x):
    return (2 / 1 + np.exp(-2*x)) - 1

print(softmax([3, 4, 5]), sigmoid(3))