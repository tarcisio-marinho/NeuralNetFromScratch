#ifndef __POINT__
#define __POINT__

#include<random>
#include <cstdlib>
#include <ctime>

class Point{

public: 
    float x;
    float y;
    int label;

    Point(){
        srand (static_cast <unsigned> (time(0)));
        x = get_random();
        y = get_random();

        if(x > y){
            label = 1;
        }else{
            label = -1;
        }
    }   

    // random numbers to initialize weights
    int  get_random(){
        return 400 + static_cast <int> (rand()) /( static_cast <int> (RAND_MAX/(0-(400))));
    }

};



#endif