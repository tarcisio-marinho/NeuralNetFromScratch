
import numpy as np
import math




def sigmoid(x):
    return 1 / 1 + np.exp(-x) 

def softmax(x):
    return np.exp(x) / np.sum(np.exp(x))

def tanh(x):
    pass

print(softmax([3, 4, 5]), sigmoid(3))