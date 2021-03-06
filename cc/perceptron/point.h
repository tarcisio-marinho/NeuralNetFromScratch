#ifndef __POINT__
#define __POINT__

#include<random>
#include <cstdlib>
#include <ctime>

class Point{

public: 
    float x;
    float y;
    float bias;
    int label;

    Point(){
        
        x = get_random();
        y = get_random();
        bias = 1;

        if(x > y){
            label = 1;
        }else{
            label = -1;
        }
    }   

private:
    // random numbers to initialize weights
    int  get_random(){
        return  0 + (rand() % static_cast<int>(400 - 0 + 1));
    }

};



#endif