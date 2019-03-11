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

        for layer in range(self.__n_hidden_layers):

            if(layer != 0):
                self.__n_input = len(net[-1])

            hidden_layer = [{'weights': np.random.uniform(size=self.__n_input)} for i in range(self.__n_hidden)]
            self.__net.append(hidden_layer)

        output_layer = [ { 'weights': np.random.uniform(size=self.__n_hidden)} for i in range(self.__n_output)]
        self.__net.append(output_layer)


    def __relu(x, deriv=False):
        if(deriv):
            return 1. * (x > 0)
        return x * (x > 0)


    def __softmax(x):
        return np.exp(x) / np.sum(np.exp(x))


    def __feed_foward(self, data):
        
        for layer in self.__net:


        pass



    def fit(self, x, y, batch_size=None, epochs=None):

        pass


    def predict(self, x):
        pass
    

    def score(self, x, y):
        loss = 0.0
        accuracy = 1.0
        return loss, accuracy
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