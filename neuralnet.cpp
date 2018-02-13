#include<iostream>
#include<array>
//#include<random>

using namespace std;

class Neuralnet{    

public:
    array<float, 2> weights;
    Neuralnet(){
        weights[0] = 10.0;
        weights[1] = 20.0;
    }
};


int main(){

    Neuralnet *n = new Neuralnet();
    for (float k : n->weights){
        cout << k << "\n";
    }


    return 0;
}