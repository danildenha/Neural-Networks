#include "MLP.h"
#include <sstream>

std::vector<double> read_vector(){
    std::vector<double> values = {0,1};
    std::string input;

    while(values.size() != 7){
        values = {};
        std::cout << "Input pattern \"a b c d e f g\": ";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        double value;
        while(ss >> value){
            values.push_back(value);
            if (ss.peek() == ' ')
                ss.ignore();
        }
        if(values[0] < 0.0)
          break;
        if(values.size() != 7) 
            std::cout << "Error: Input must contain exactly 7 floating point values separated spaces." << std::endl;
    }
    return values;
}

int main(){
    
    // Test code - Segment Display Recognition System

    std::cout << std::endl << "Segment Display Recognition System" << std::endl;
    std::cout << "How many epochs? ";
    size_t epochs;
    std::cin >> epochs;
    std::cin.ignore();
    
    MultiLayerPerceptron mlp1 = MultiLayerPerceptron({7,7,1});
    MultiLayerPerceptron mlp2 = MultiLayerPerceptron({7,7,10});
    MultiLayerPerceptron mlp3 = MultiLayerPerceptron({7,7,7});


    // Dataset for the 7 to 7 network
    std::cout << "Training 7 to 7 network..." << std::endl;
    double MSE;

    for (int i = 0; i < epochs; i++){
        MSE = 0.0;
        MSE += mlp3.bp({1,1,1,1,1,1,0}, {1,1,1,1,1,1,0}); //0 pattern
        MSE += mlp3.bp({0,1,1,0,0,0,0}, {0,1,1,0,0,0,0}); //1 pattern
        MSE += mlp3.bp({1,1,0,1,1,0,1}, {1,1,0,1,1,0,1}); //2 pattern
        MSE += mlp3.bp({1,1,1,1,0,0,1}, {1,1,1,1,0,0,1}); //3 pattern
        MSE += mlp3.bp({0,1,1,0,0,1,1}, {0,1,1,0,0,1,1}); //4 pattern
        MSE += mlp3.bp({1,0,1,1,0,1,1}, {1,0,1,1,0,1,1}); //5 pattern
        MSE += mlp3.bp({1,0,1,1,1,1,1}, {1,0,1,1,1,1,1}); //6 pattern
        MSE += mlp3.bp({1,1,1,0,0,0,0}, {1,1,1,0,0,0,0}); //7 pattern
        MSE += mlp3.bp({1,1,1,1,1,1,1}, {1,1,1,1,1,1,1}); //8 pattern
        MSE += mlp3.bp({1,1,1,1,0,1,1}, {1,1,1,1,0,1,1}); //9 pattern
    }
    MSE /= 10.0;
    std::cout << "7 to 7  network MSE: " << MSE << std::endl << std::endl;

    // Test the Classifiers

    std::vector<double> pattern = {1.2};
    while(pattern[0] >= 0.0){
        pattern = read_vector();
        if(pattern[0] < 0.0)
            break;
        std::cout << "The number recognized by the 7 to 1 network is " << (int) (mlp1.run(pattern)[0]*10) << std::endl;

        auto temp = mlp2.run(pattern);
        auto max_iter = std::max_element(temp.begin(), temp.end());
        auto max_index = std::distance(temp.begin(), max_iter);
        std::cout << "The number recognized by the 7 to 10 network is " << max_index << std::endl;

        temp = mlp3.run(pattern);
        std::cout << "The pattern recognized by the 7 to 7 network is [";
        for (auto i : temp)
            std::cout << " " << int(i + 0.5);
        std::cout << " ]" << std::endl << std::endl;
    }
    std::cout << std::endl;
}
