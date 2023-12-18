// Neural_NetworksOR.cpp : This file contains the 'main' function
//This file uses neural network for OR operation

#include "MLP.h"

int main(){
    srand(time(NULL));
    rand();

    std::cout << "\n\n--------Logic Gate Example----------------\n\n";
    Perceptron p(2);

    p.set_weights({10.0,10.0,-15.0}); //AND

    std::cout << "Gate: " << std::endl;
    std::cout << p.run({0.0,0.0}) << std::endl;
    std::cout << p.run({0.0,1.0}) << std::endl;
    std::cout << p.run({1.0,0.0}) << std::endl;
    std::cout << p.run({1.0,1.0}) << std::endl;
}