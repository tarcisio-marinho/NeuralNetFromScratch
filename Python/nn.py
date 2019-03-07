import numpy as np

class MLP():

    def __init__(self, n_input, n_hidden, n_output, lr):
        self.score = None
        self.__n_input = n_input
        self.__n_hidden = n_hidden
        self.__n_output = n_output
        self.__n_hidden_layers = 1
        self.__lr = lr

        self.__net = []


    def __relu(x, deriv=False):
        if(deriv):
            return 1. * (x > 0)
        return x * (x > 0)


    def __softmax(x):
        return np.exp(x) / np.sum(np.exp(x))

    def fit(self, x):

        pass

    def predict(self, x):
        pass
    
    def score(self):
        pass

    def print(self):
        for i,layer in enumerate(self.__net,1):
            print("Layer {} ".format(i))
            for j,neuron in enumerate(layer,1):
                print("neuron {} :".format(j),neuron)

if __name__ == "__main__":




    clf = MLP()
    clf.fit()

    result = clf.predict()
    score = clf.score()