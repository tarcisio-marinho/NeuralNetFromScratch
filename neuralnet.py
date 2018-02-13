import random

class Neuralnet():
   
    def __init__(self, n_weights):
        # weights -> float
        weights = []
        for i in range(n_weights):
            weights.append(random.uniform(-1, 1))

    def guess(self, input):
        soma = 0

        for i in range(len(weights)):
            soma +=input[i] * weights[i]
        
        return sign(soma)

    
    # activation function
    def sign(self, number):
        if(number < 0):
            return -1
        return 1


if __name__ == "__main__":
    a = Neuralnet(2)

    print(a.guess([-1, 0.5]))
