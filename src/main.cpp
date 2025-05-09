#include "../include/debugOCR.hpp"
#include "../include/modelProp.hpp"

#include "../include/model/neuralNetwork.hpp"
#include "../include/model/loadDataset.hpp"

#include "../include/opPoint/bmpReader.hpp"
#include "../include/opPoint/brightnessOperation.hpp"
#include "../include/opPoint/thresholdOperation.hpp"



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
    NeuralNetwork ann(LEARNING_RATE);

    std::vector<std::vector<double>> inputDataRaw;//(200,std::vector<double>(ann.getInputLayerSize()));
    std::vector<std::vector<double>> oneHotLabels;//(200,std::vector<double>(ann.getOutputLayerSize()));

    //LoadDataset loader(DATASET_AB_POSXY,inputDataRaw,oneHotLabels,ann.getOutputLayerSize());
    //std::string imgPath = DATASET_AB_POSXY"/b_013.bmp";
    
    LoadDataset loader(DATASETS AZ_EN,inputDataRaw,oneHotLabels,NORMALIZE_READ);
    std::string imgPath = DATASETS AZ_EN"/k_013.bmp";


    DL("inputData SIZE: " << inputDataRaw.size());
    DL("oneHotLabels SIZE: " << oneHotLabels.size());
    DL("output SIZE: " << ann.getOutputs().size());

    /*
    for(const auto& r : oneHotLabels){
        std::cout << r[0] << " -- ";
        std::cout << r[1] << "\n";
    }
    */

    //getchar();

    //EGITIM
    ann.fit(inputDataRaw,oneHotLabels,TOTAL_EPOCH_TRAIN);
  

    //TAHMIN DEGERLERI
    ann.printPredictTest(inputDataRaw,oneHotLabels,10);


    //(1)GORUNTUYU OKU ISLE VE TAHMIN ETTIR

    //goruntuyu vektore aktarma
   
    bmpReader testFile(imgPath);
    std::vector<double> rawImage = testFile.readConvert(NORMALIZE_READ);

    //image pre process
    BrightnessOp bop(0);
    bop.initalize(rawImage, testFile.getWidth(), testFile.getHeight());
    bop.applyPointOperation();
    ThresholdOp top(90);
    top.initalize(rawImage, testFile.getWidth(), testFile.getHeight());
    top.applyPointOperation();

    ann.predictImage(rawImage);

    //(2)DOGRUDAN PATH VER ON ISLEME YAPMADAN TAHMIN ETTIR
    //ann.predictImage(imgPath);



    return 0x0;
}