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

void print(std::string data){
    std::cout << data << std::endl;
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
            /*if(ret[ret.size()-1] == "4"){
                value = 4
            }*/
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



int main(int argc, char *argv[]){

    Data* d = get_data();
    int contador= 0;
    for(auto n:d->x){
        for(int a : n){
            std::cout << a << ",";
        }
        std::cout << "Classe: "<<d->y[contador] << std::endl; 
        contador++;
    }

/*
    NeuralNet *n = new NeuralNet(2, 2, 1);
    Matrix *data = new Matrix(2, 1);
    Matrix *label = new Matrix(1, 1);
    n->fit(data, label);


    Matrix *output = n->predict(new Matrix(1, 1));
    output->print();
    
    // float (*foo)(float);
    // foo = &pi;
*/
    return 0;
}