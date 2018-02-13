#include<iostream>
#include<vector>
#include<random>
#include <cstdlib>

using namespace std;

class Neuralnet{    

public:
    vector<float> weights;

    Neuralnet(){
        srand (static_cast <unsigned> (time(0)));
        int valor = 1;
        for (int i = 0; i < weights.size(); i++){

        }
    }
    
    int sign(float number){
        if(number < 0){
            return -1;
        }
        return 1;
    }

    float get_random(){
        return -1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-(-1))));
    }

};



int main(){
    
    Neuralnet *n = new Neuralnet();

    for (int i = 0; i<10 ;i ++){
        cout << n->get_random() << "\n";
    }
    
    return 0;
}