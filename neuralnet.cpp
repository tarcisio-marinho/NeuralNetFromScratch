#include<iostream>
#include<vector>
#include<random>
#include <cstdlib>

using namespace std;

class Neuralnet{    

public:
    vector<float> weights;

    Neuralnet(int number_weights){
        srand (static_cast <unsigned> (time(0)));
        for (int i = 0; i< number_weights; i++){
            weights.push_back(get_random());
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



int main(int argc, char * argv[]){
    
    Neuralnet *n = new Neuralnet(2);

    for(float k : n->weights){
        cout << k << "\n";
    }
    
    return 0;
}