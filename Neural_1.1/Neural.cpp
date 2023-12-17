#include "Neural.h"

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}


// Constructor for a New Perceptron object with the specified number of inputs +1 for the bias.
Perceptron::Perceptron(size_t inputs, double bias){
    this->bias = bias;
    weights.resize(inputs + 1);
    generate(weights.begin(), weights.end(), frand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(std::vector<double> x){
	x.push_back(bias);
    
}