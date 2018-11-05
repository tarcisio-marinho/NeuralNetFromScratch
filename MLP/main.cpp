#include "neuralnet.h"
#include "matrix.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

class Data{
public:
    Data(std::vector<std::vector<float> > x, std::vector<float> y){
        this->x = x;
        this->y = y;
    }

    std::vector<std::vector<float> > x;
    std::vector<float> y;
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
    std::vector<std::vector<float> > x;
    std::vector<float> y;


    std::ifstream file("data/breast-cancer-wisconsin.data");
    if (file.is_open()) {
        std::string line;
        getline(file, line); // first line
        while (getline(file, line)) {
            std::vector<std::string> ret = split(line, ',');

            ret.erase(ret.begin()); //  removes ID

            int value = float(atoi(ret[ret.size()-1].c_str())); // get the class
            y.push_back(value);
            ret.erase(ret.begin() + 9); // remove the class
            
            // cleaning the '?' data
            std::vector <float> aux;
            bool achou;
            for (auto n: ret){
                if(n == "?"){
                    achou = true;
                    n = "0";
                }
                aux.push_back(float(atoi(n.c_str())));
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

    // get the dataset    
    Data* d = get_data();

    // create the input matrix
    Matrix *training_dataset = new Matrix(d->x);

    // labels
    Matrix *labels = Matrix::fromArray(d->y);

    NeuralNet *n = new NeuralNet(9, 20, 2);
    
    // testing 
     Matrix * test = Matrix::fromArray(std::vector<float>{1, 1, 2, 3, 4, 5, 1, 2, 3});
     Matrix * retorno = n->predict(test);
     retorno->print();

    n->fit(training_dataset, labels);


    //Matrix *output = n->predict(new Matrix(1, 1));
   // output->print();
    

}