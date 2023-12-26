# MyNeuralNetworks

This repository hosts various projects showcasing the implementation of **neural networks** in C++. These projects demonstrate the fundamental concepts of neural networks applied to logical operations and number recognition tasks.

![Neural Network](https://www.ibm.com/content/dam/connectedassets-adobe-cms/worldwide-content/cdp/cf/ul/g/3a/b8/ICLH_Diagram_Batch_01_03-DeepNeuralNetwork.component.simple-narrative-xl.ts=1694627445038.png/content/adobe-cms/id/en/topics/neural-networks/jcr:content/root/table_of_contents/intro/simple_narrative/image)

## Neural Networks and Their Applications

Neural networks are computational models inspired by the human brain's structure and function. They consist of interconnected nodes (neurons) that process and transmit information. These networks are capable of learning patterns, making them invaluable in various fields such as pattern recognition, classification, and prediction.

### Projects Included:

1. **Neural_NetworkXOR**
    - Demonstrates a neural network for the XOR logical operation.

2. **Neural_NetworkAND**
    - Implements a neural network for the logical AND operation.

3. **Neural_NetworkOR**
    - Contains a neural network for the logical OR operation.
  
4. **Training_Network_BP**
    - Provides an implementation for training neural networks using **backpropagation**.

5. **Number_Recognition**
    - Focuses on recognizing numbers based on segmented display patterns using neural networks.
    - Utilizes three different network output methods: **7 to 1, 7 to 7, and 7 to 10**.
    - During training, the concept of **epochs** is utilized. An epoch represents one complete cycle through the entire dataset during training.

## Understanding Neural Networks

### Backpropagation

**Backpropagation** is a key algorithm used to train neural networks. It involves propagating the error backward through the network's layers to adjust the weights, minimizing the difference between the predicted and actual outputs. This iterative process allows neural networks to learn from data and improve their performance.

### Mean Squared Error (MSE)

**Mean Squared Error (MSE)** is a common metric used to evaluate the performance of neural networks during training. It measures the average squared difference between predicted and actual values. Minimizing the MSE during training is a primary goal to enhance the network's accuracy in making predictions.

## Sample Code: Back Propagation

The Back Propagation used in the `Number_Recognition` project's source code illustrates the process of training. This code is provided with a sample (x,y) where x is the input value and y is the desired value.

```cpp
    // Feeding a sample to the network
    std::vector<double> outputs = run(x);

    // Calculating the Mean Squared Error
    std::vector<double> error;
    double MSE{0.0};
    for (unsigned int i{0}; i < outputs.size(); i++) {
        error.emplace_back(y[i] - outputs[i]);
        MSE += error[i] * error[i];
    }
    MSE /= layers.back();
    
    // Calculating the output error terms
    for (unsigned int i{0}; i < outputs.size(); i--) {
        d.back()[i] = outputs[i] * (1 - outputs[i]) * error[i];
    }
    // Calculating the error term of each unit on each layer    
    for (size_t i = network.size()-2; i > 0; i--)
        for (size_t h = 0; h < network[i].size(); h++){
            double fwd_error = 0.0;
            for (size_t k = 0; k < layers[i+1]; k++)
                fwd_error += network[i+1][k].weights[h] * d[i+1][k];
            d[i][h] = values[i][h] * (1-values[i][h]) * fwd_error;
        }
    
    // Calculating the deltas and update the weights
    for (size_t i = 1; i < network.size(); i++)
        for (size_t j = 0; j < layers[i]; j++)
            for (size_t k = 0; k < layers[i-1]+1; k++){
                double delta;
                if (k == layers[i-1])
                    delta = eta * d[i][j] * bias;
                else
                    delta = eta * d[i][j] * values[i-1][k];
                network[i][j].weights[k] += delta;
            }
    return MSE;
}
