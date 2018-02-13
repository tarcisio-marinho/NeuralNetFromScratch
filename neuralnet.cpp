#include<iostream>
#include<array>
#include<random>

using namespace std;

class Neuralnet{    

public:
    array<float, 2> weights;
    Neuralnet(){
        int valor = 1;
        for (int i = 0; i < weights.size(); i++){
            weights[i] = valor;
            valor ++;
        }
    }
    
    void get_1(){
        for (float n : weights){
            cout << n << "\n";
        }

    }
};


int main(){

    Neuralnet *n = new Neuralnet();
    n->get_1();


    return 0;
}