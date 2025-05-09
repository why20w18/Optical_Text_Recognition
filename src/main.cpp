#include "../include/debugOCR.hpp"

#include "../include/model/neuralNetwork.hpp"
#include "../include/model/loadDataset.hpp"

#include "../include/opPoint/bmpReader.hpp"
#include "../include/opPoint/brightnessOperation.hpp"
#include "../include/opPoint/thresholdOperation.hpp"

#include <algorithm>

int main(){
////////////////////////////////////////////////
    //std::cout << "->" << RandomMath::getRandom(-1,1) << "\n";
    //NeuralNetwork ann;

    /*
    bmpReader bmpFile("dataset_ab/a_001.bmp");
    auto img = bmpFile.readConvert();
    std::cout << img.size() << std::endl;
    std::cout << bmpFile.getWidth() << "<--width height--> " << bmpFile.getHeight() << std::endl;
    */

    /*
    BrightnessOp bop(120);
    bop.initalize(img,bmpFile.getWidth(),bmpFile.getHeight());
    bop.applyPointOperation();
    bop.printPixelData();
    */

    /*
    ThresholdOp top(120);
    top.initalize(img,bmpFile.getWidth(),bmpFile.getHeight());
    top.applyPointOperation();
    top.printPixelData();
    */
////////////////////////////////////////////////
    NeuralNetwork ann(0.1);

    std::vector<std::vector<double>> inputDataRaw;//(200,std::vector<double>(ann.getInputLayerSize()));
    std::vector<std::vector<double>> oneHotLabels;//(200,std::vector<double>(ann.getOutputLayerSize()));

    LoadDataset loader("/home/archw/packs/imgProcess/dataset_ab",inputDataRaw,oneHotLabels,ann.getOutputLayerSize());


    DL("inputData size: " << inputDataRaw.size());
    DL("target size: " << oneHotLabels.size());
    DL("output size: " << ann.output.size());

    for(const auto& r : oneHotLabels){
        std::cout << r[0] << " -- ";
        std::cout << r[1] << "\n";
    }

    //getchar();

    //EGITIM
    int totalEpochs = 100;

    // RNG tanımı (epok dışında bir kez tanımlanması daha verimli olabilir)
    std::random_device rd;
    std::mt19937 g(rd());
    
    for (int epoch = 0; epoch < totalEpochs; ++epoch) {
        std::cout << "Epoch: " << epoch + 1 << std::endl;
    
        std::vector<size_t> indices(inputDataRaw.size());
        std::iota(indices.begin(), indices.end(), 0);
    
        std::shuffle(indices.begin(), indices.end(), g);
    
        for (size_t idx : indices) {
            ann.train(inputDataRaw[idx], oneHotLabels[idx]);
        }
    }



    //
    for (size_t i = 0; i < 5; ++i) {
        ann.forwardPropagation(inputDataRaw[i]);
    
        std::cout << "Tahmin: ";
        for (double val : ann.output) {
            std::cout  << ann.toRound(val) << " "; //val

        }
        std::cout << " | Gercek: ";
        for (double val : oneHotLabels[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }



    std::string imgPath = "/home/archw/packs/imgProcess/dataset_ab/b_001.bmp";
    bmpReader testFile(imgPath);

    //image pre process
    std::vector<double> rawImage = testFile.readConvert();
    
    BrightnessOp bop(120);
    bop.initalize(rawImage, testFile.getWidth(), testFile.getHeight());
    bop.applyPointOperation();

    ThresholdOp top(128);
    top.initalize(rawImage, testFile.getWidth(), testFile.getHeight());
    top.applyPointOperation();
    

    ann.forwardPropagation(rawImage);
    int predictedIndex = std::distance(ann.output.begin(), std::max_element(ann.output.begin(), ann.output.end()));
    char predictedChar = (predictedIndex == 0) ? 'a' : 'b';
    std::cout << "Tahmin edilen karakter: " << predictedChar << std::endl;


    return 0x0;
}