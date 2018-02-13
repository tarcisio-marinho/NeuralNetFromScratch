#include<iostream>
#include "perceptron.h"

int main(int argc, char * argv[]){
    
    Perceptron *n = new Perceptron(2);

    cout << n->guess({-1, 0.5});
    
    return 0;
}