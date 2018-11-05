#include "neuralnet.h"
#include "matrix.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

class Data{
public:
    Data(std::vector<std::vector<int> > x, std::vector<int> y){
        this->x = x;
        this->y = y;
    }

    std::vector<std::vector<int> > x;
    std::vector<int> y;
};


std::vector<std::string> split(const std::string& s, const char& c)
{
	std::string buff{""};
	std::vector<std::string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") 
        v.push_back(buff);
	
	return v;
}


Data* get_data(){
    std::vector<std::vector<int> > x;
    std::vector<int> y;


    std::ifstream file("data/breast-cancer-wisconsin.data");
    if (file.is_open()) {
        std::string line;
        getline(file, line); // first line
        while (getline(file, line)) {
            std::vector<std::string> ret = split(line, ',');

            ret.erase(ret.begin()); //  removes ID

            int value = atoi(ret[ret.size()-1].c_str()); // get the class
            y.push_back(value);
            ret.erase(ret.begin() + 9); // remove the class
            
            // cleaning the '?' data
            std::vector <int> aux;
            bool achou;
            for (auto n: ret){
                if(n == "?"){
                    achou = true;
                    n = "0";
                }
                aux.push_back(atoi(n.c_str()));
            }
            x.push_back(aux);

        }
        
        file.close();
        return new Data(x, y);

    }
}

void print_data_set(Data *d){
    int contador = 0;
    for(auto n : d->x){
        for(int a : n){
            std::cout << a << ",";
        }
        std::cout << d->y[contador] << std::endl; 
        contador++;
    }
}


int main(int argc, char *argv[]){

    
    Data* d = get_data();
    print_data_set(d);

/*
    NeuralNet *n = new NeuralNet(9, 20, 2);

    n->fit(data, label);


    Matrix *output = n->predict(new Matrix(1, 1));
    output->print();
    
*/
}