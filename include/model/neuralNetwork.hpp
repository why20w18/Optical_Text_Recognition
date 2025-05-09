#ifndef __NEURAL_NETWORK_HPP__
#define __NEURAL_NETWORK_HPP__

#include <vector>
#include "../opRandomMath.hpp"
#include "../debugOCR.hpp"

class NeuralNetwork{
private:
    int inputLayerSize = 784; //28x28 piksel
    int hiddenLayerSize = 16;
    int outputLayerSize = 2; //simdilik a ve b tespiti
    
    double learningRate;

    std::vector<double> input;
    std::vector<double> hidden;
    std::vector<double> output;


    std::vector<std::vector<double>> weightInput_Hidden;
    std::vector<std::vector<double>> weightHidden_Output;

    std::vector<double> biasHidden;
    std::vector<double> biasOutput;
public:

    NeuralNetwork(double learningRate = 0.1f);//(1)veri yapilarinin dogru boyutlarda random agirlik ve bias ile baslatma
    
    void forwardPropagation(const std::vector<double> &inputData);
    //(2)hidden ve output dolduruldu ilk seferde girilen inputa gore
    //noral ag ileri isletildi

    void backwardPropagation(std::vector<double> &outputData,std::vector<double> &hiddenData,const std::vector<double> &target);
    //(3)agirliklari duzeltmek icin hata hesaplama
    //geri yayilim


    void train(const std::vector<double> &inputData , const std::vector<double> &target);
    
    int getInputLayerSize();
    int getHiddenLayerSize();
    int getOutputLayerSize();

    double toRound(double outputValue);

    void predictTest();
    
    


};





#endif //__NEURAL_NETWORK_HPP__
/*
https://www.datacamp.com/tutorial/forward-propagation-neural-networks

*/