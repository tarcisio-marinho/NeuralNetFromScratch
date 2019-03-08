
import numpy as np

def cross_entropy(x, y):
    m = y.shape[0]
    p = softmax(x)
    log_likelihood = -np.log(p[range(x), y])
    return np.sum(log_likelihood) / m


def square_sum_error(outputs, expected):
    sum_error += sum([(y - x)**2 for x, y in zip(outputs, expected)])
    return sum_error


def binary_cross_entropy():
    pass

    