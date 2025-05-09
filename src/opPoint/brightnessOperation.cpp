#include "../../include/opPoint/brightnessOperation.hpp"


BrightnessOp::BrightnessOp(int brightVal) : brightVal(brightVal){}

void BrightnessOp::applyPointOperation(){
    int totalPixel = width * height;
    DL("total pixel brightness : " << totalPixel);
    for(int i = 0 ; i < totalPixel ; i++){
        this->pixelData[i] = PointOperation::scaleRange<double>(this->pixelData[i]+brightVal,0,255);
    }
}


int BrightnessOp::getWidth(){
    return this->width;
}

int BrightnessOp::getHeight(){
    return this->height;
}

std::vector<double> BrightnessOp::getRawPixelData(){
    return this->pixelData;
}