
import numpy as np
import math




def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def softmax(x):
    return np.exp(x) / np.sum(np.exp(x))

def tanh(x):
    return (2 / 1 + np.exp(-2*x)) - 1

def softmax(x):
    e = numpy.exp(x - numpy.max(x))  # prevent overflow
    if e.ndim == 1:
        return e / numpy.sum(e, axis=0)
    else:  
        return e / numpy.array([numpy.sum(e, axis=1)]).T  # ndim = 2

def ReLU(x):
    return x * (x > 0)

def dReLU(x):
    return 1. * (x > 0)


print(softmax(np.array([3, 4, 5])), sigmoid(-1))