#include<iostream>
#include<vector>
#include<random>
#include <cstdlib>

using namespace std;

class Neuralnet{    

public:
    vector<float> weights;

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

float get_random()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(-1, 1); // rage 0 - 1
    return dis(e);
}

int main(){
    Neuralnet *n = new Neuralnet();
    //n->get_1();
    cout << get_random();

    return 0;
}