#include "../../include/opPoint/thresholdOperation.hpp"


ThresholdOp::ThresholdOp(int threshold,int minThreshold , int maxThreshold)
:threshold(threshold) , minThreshold(minThreshold),maxThreshold(maxThreshold){
}

void ThresholdOp::applyPointOperation(){
    int totalPixel = width * height;
    DL("total pixel threshold :  " << width << " , " << height);

    for(int i = 0 ; i < totalPixel ; i++){
        pixelData[i] = (pixelData[i] > threshold) ? maxThreshold : minThreshold;
    }

}

int ThresholdOp::getWidth(){
    return this->width;
}

int ThresholdOp::getHeight(){
    return this->height;
}

std::vector<double> ThresholdOp::getRawPixelData(){
    return this->pixelData;
}