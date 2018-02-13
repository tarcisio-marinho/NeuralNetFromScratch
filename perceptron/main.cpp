#include<iostream>
#include "perceptron.h"
#include "point.h"

void create_dataset(int size, Perceptron *n){
    vector<Point*> points;
    srand (static_cast <unsigned> (time(0)));
    float x, y;
    int desejado, chute, acertos = 0;

    // generating data
    for (int i = 0; i<size; i++){
        points.push_back(new Point());
    }

    // training part
    for (Point *p : points){
        n->train({p->x, p->y, p->bias}, p->label);
    }

    // testing with new data
    for (int i = 0; i < 100; i++){
        Point *p = new Point();
        x = p->x;
        y = p->y;

        if(x > y){
            desejado = 1;
        }else{
            desejado = -1;
        }

        chute = n->guess({x, y});
        if(desejado == chute ){
            acertos++;
        }
    }
    cout << acertos << "%" <<endl;
        
}


int main(int argc, char * argv[]){
    
    Perceptron *n = new Perceptron(3);
    create_dataset(100, n);

    return 0;
}
