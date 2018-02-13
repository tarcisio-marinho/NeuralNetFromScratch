#include<iostream>
#include "perceptron.h"
#include "point.h"

void create_dataset(int size, Perceptron *n){
    vector<Point*> points;

    for (int i = 0; i<size; i++){
        points.push_back(new Point());
    }

    for (Point *p : points){
        cout << p->x << " " << p->y << " " << p->label << "\n";
    }

    // for (Point *p : points){
    //     n->train({p->x, p->y}, p->label);
    // }

    // cout << n->guess({114, 216});
}


int main(int argc, char * argv[]){
    
    Perceptron *n = new Perceptron(2);
    create_dataset(5, n);

    return 0;
}
