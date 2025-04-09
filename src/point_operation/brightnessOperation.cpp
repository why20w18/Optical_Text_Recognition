#include "../../include/point_operation/brightnessOperation.hpp"

BrightnessOp::BrightnessOp(const std::string &imagePath,int brightVal)
:brightVal(brightVal){
    std::tie(this->imageWidth,this->imageHeight,this->imageData) = PointOperation::getImageDatas(imagePath);
    ILOG("BrightnessOP-1 : " << imageWidth << " , " << imageHeight);
}

BrightnessOp::BrightnessOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int brightVal)
:brightVal(brightVal){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->imageData = imageData;
    ILOG("BrightnessOP-2 : " << imageWidth << " , " << imageHeight);

}


void BrightnessOp::applyPointOperation(){
    int totalPixel = imageWidth * imageHeight;

    for(int i = 0 ; i < totalPixel ; i++){
        int locPixel = i * 3;
        
        this->imageData[locPixel+0] = PointOperation::scaleRange(this->imageData[locPixel+0]+brightVal,0,255);
        this->imageData[locPixel+1] = PointOperation::scaleRange(this->imageData[locPixel+1]+brightVal,0,255);
        this->imageData[locPixel+2] = PointOperation::scaleRange(this->imageData[locPixel+2]+brightVal,0,255);
    }
}

std::vector<uuchar> BrightnessOp::getImage(){
    return this->imageData;
}

int BrightnessOp::getImageWidth(){
    return this->imageWidth;
}

int BrightnessOp::getImageHeight(){
    return this->imageHeight;
}