#include "../../include/model/neuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(double learningRate){
    this->learningRate = learningRate;

    //(1) veri yapilarini dogru boyutlarda baslatma 2D arrayleri kurma
    input.resize(this->inputLayerSize);
    hidden.resize(this->hiddenLayerSize);
    output.resize(this->outputLayerSize);

    weightInput_Hidden.resize(inputLayerSize,std::vector<double>(hiddenLayerSize));
    weightHidden_Output.resize(hiddenLayerSize,std::vector<double>(outputLayerSize));

    biasHidden.resize(this->hiddenLayerSize);
    biasOutput.resize(this->outputLayerSize);

    //(2) bias degerlerini random -1 ve 1 arasinda baslatma
    for(int i = 0 ; i < hiddenLayerSize ; i++)
        biasHidden[i] = RandomMath::getRandom();

    for(int i = 0 ; i < outputLayerSize ; i++)
        biasOutput[i] = RandomMath::getRandom(-1,1);

    
    //(3) agirlik matrislerini random sekilde baslatma
    for(int i = 0 ; i < inputLayerSize ; i++)
        for(int j = 0 ; j < hiddenLayerSize ; j++)
            weightInput_Hidden[i][j] = RandomMath::getRandom();

    for(int i = 0 ; i < hiddenLayerSize ; i++)
        for(int j = 0 ; j < outputLayerSize ; j++)
            weightHidden_Output[i][j] = RandomMath::getRandom();

    DL("NEURAL NETWORK AGIRLIKLARI VE BIASLARI RANDOM SEKILDE BASLATILDI");
}

void NeuralNetwork::forwardPropagation(const std::vector<double> &inputData){
    //(1)INPUT LAYERDAN HIDDEN LAYERA GECIS ==> kisacasi SIGMOID(input_Nx x hidden_Nx) = hidden olarak tuttuk , kartezyen yapildi
    //input -> hidden
    input = inputData;

    for(int i = 0 ; i < hiddenLayerSize ; i++){
        hidden[i] = biasHidden[i]; //bias degerini direkt kopyaladik
        for(int j = 0 ; j < inputLayerSize ; j++){
            hidden[i] += weightInput_Hidden[j][i] * input[j]; //w*x + bias = y 
        }
        hidden[i] = RandomMath::sigmoidExp(hidden[i]); //sigmoid ciktisi olarak degistirilir 
    }

    //(2)HIDDEN LAYERDAN OUTPUT LAYERA GECIS ==> 1 output seciliyor tum hiddenler icin hesaplama yapilip sigmoidden geciriliyor
    //hidden -> output
    for(int i = 0 ; i < outputLayerSize ; i++){
        output[i] = biasOutput[i];
        for(int j = 0 ; j < hiddenLayerSize ; j++){
            output[i] += weightHidden_Output[j][i] * hidden[j];
        }
        output[i] = RandomMath::sigmoidExp(output[i]);
    }
}

void NeuralNetwork::backwardPropagation(std::vector<double> &outputData,std::vector<double> &hiddenData,const std::vector<double> &target){
    //(1)OUTPUT->HIDDEN
    std::vector<double> errorOutput(outputLayerSize,0.);
    for(int i = 0 ; i < outputLayerSize ; i++){
        errorOutput[i] = (target[i] - outputData[i]) * RandomMath::derOut_sigmoidExp(outputData[i]);
    }
    //errorOutput dolduruldu hidden layerdaki hatalari hesaplamak icin geri yayacagiz

    //(2)HIDDEN LAYER ERROR
    //hidden layerdaki 1 noron output layerdaki 1'den fazla noronla hesaplama yapiyor bu sebeple
    /*
        h1          o1      h1_o1_err + h1_o2_err = h1_total_err
        h2          o2      h2_o1_err + h2_o2_err = h2_total_err
        ...         ...
    */ 
    std::vector<double> errorHidden(hiddenLayerSize,0.);
    for(int i = 0 ; i < hiddenLayerSize ; i++){
        double hi_total_err = 0.0f;
        for(int j = 0 ; j < outputLayerSize ; j++){
            hi_total_err += errorOutput[j] * weightHidden_Output[i][j];
        }
        errorHidden[i] = hi_total_err * RandomMath::derOut_sigmoidExp(hiddenData[i]);
    }

    //learning burada gerceklesiyor esasinda eski weightsleri silmeden guncelleme:
    //(3)HIDDEN->OUTPUT WEIGHTS guncelleme
    for(int i = 0 ; i < hiddenLayerSize ; i++)
        for(int j = 0 ; j < outputLayerSize ; j++){
            weightHidden_Output[i][j] += this->learningRate * errorOutput[j] * hiddenData[i]; 
        }

    //(4)INPUT->HIDDEN WEIGHTS guncelleme
    for(int i = 0 ; i < inputLayerSize ; i++){
        for(int j = 0 ; j < hiddenLayerSize ; j++){ //tum hidden layer noronlari ile isleniyor 1 input noronu
            weightInput_Hidden[i][j] += this->learningRate * errorHidden[j] * input[i];
        }
    }
    
    //eski bias degerlerini silmeden guncelleme:
    //(4)OUTPUT BIAS
    for(int i = 0 ; i < outputLayerSize ; i++)
        biasOutput[i] += this->learningRate * errorOutput[i];

    //(5)HIDDEN BIAS
    for(int i = 0 ; i < hiddenLayerSize ; i++){
        biasHidden[i] += this->learningRate * errorHidden[i];
    }

    
}

void NeuralNetwork::train(const std::vector<double> &inputData , const std::vector<double> &target){
    forwardPropagation(inputData);
    backwardPropagation(output,hidden,target);
}

int NeuralNetwork::getInputLayerSize(){
    return this->inputLayerSize;
}

int NeuralNetwork::getHiddenLayerSize(){
    return this->hiddenLayerSize;
}

int NeuralNetwork::getOutputLayerSize(){
    return this->outputLayerSize;
}

double NeuralNetwork::toRound(double outputValue){
    if(outputValue < 1e-4) return 0;
    else return outputValue;
}


void NeuralNetwork::predictTest(){}
