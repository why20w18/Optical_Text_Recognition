#ifndef __NEURAL_NETWORK_HPP__
#define __NEURAL_NETWORK_HPP__

#include <vector>
#include <iomanip>
#include <algorithm>


#include "../opPoint/bmpReader.hpp"
#include "../opRandomMath.hpp"
#include "../debugOCR.hpp"
#include "../modelProp.hpp"

enum PREDICT_CHARACTER {
    A = 0, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z
};

class NeuralNetwork{
private:
    int inputLayerSize = 784; //28x28 piksel
    int hiddenLayerSize = 16;
    int outputLayerSize = OUTPUT_LAYER;//2; //simdilik a ve b tespiti
    
    double learningRate;

    std::vector<double> input;
    std::vector<double> hidden;
    std::vector<double> output;


    std::vector<std::vector<double>> weightInput_Hidden;
    std::vector<std::vector<double>> weightHidden_Output;

    std::vector<double> biasHidden;
    std::vector<double> biasOutput;

    void predictIndexSwitch(int predictIndex);

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

    void printPredictTest(const std::vector<std::vector<double>> &inputDataRaw
                    ,const std::vector<std::vector<double>> &oneHotLabels,
                     int loopCount);
    
    std::vector<double>& getOutputs();

    void predictImage(const std::string &pathfile,bool normalized);
    void predictImage(std::vector<double> rawImageData);

    void fit(const std::vector<std::vector<double>> &inputDataRaw
            ,const std::vector<std::vector<double>> &oneHotLabels
            ,int totalEpoch = 100);
                
    void fillRange(std::vector<int> &sortedVec,int startValue,int increment = 1);
    
    template<typename T>
    void print1D(const std::vector<T> &v){
        for(int i = 0 ; i < v.size() ; i++)
        std::cout << v[i] << " ";
        printf("\n");
    }

    
    
};





#endif //__NEURAL_NETWORK_HPP__
/*
https://www.datacamp.com/tutorial/forward-propagation-neural-networks

*/