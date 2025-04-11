#include "../../include/point_operation/thresholdOperation.hpp"


ThresholdOp::ThresholdOp(const std::string &imagePath,int threshold,int minThreshold , int maxThreshold)
: threshold(threshold) , minThreshold(minThreshold) , maxThreshold(maxThreshold){
    std::tie(this->imageWidth,this->imageHeight,this->imageData) = PointOperation::getImageDatas(imagePath);
    ILOG("ThrehsoldOp-1 : " << imageWidth << " , " << imageHeight);
}

ThresholdOp::ThresholdOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int threshold,
                         int minThreshold , int maxThreshold)
:threshold(threshold) , minThreshold(minThreshold),maxThreshold(maxThreshold){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->imageData = imageData;
    ILOG("ThrehsoldOp-2 : " << imageWidth << " , " << imageHeight);
}

void ThresholdOp::applyPointOperation(){
    int totalPixel = imageWidth * imageHeight;
    
    for(int i = 0 ; i < totalPixel ; i++){
        int locPixel = i*3;
        imageData[locPixel+0] = (imageData[locPixel+0] > threshold) ? maxThreshold : minThreshold;
        imageData[locPixel+1] = (imageData[locPixel+1] > threshold) ? maxThreshold : minThreshold;
        imageData[locPixel+2] = (imageData[locPixel+2] > threshold) ? maxThreshold : minThreshold;        
    }

}

std::vector<uuchar> ThresholdOp::getImage(){
    return this->imageData;
}

int ThresholdOp::getImageWidth(){
    return this->imageWidth;
}

int ThresholdOp::getImageHeight(){
    return this->imageHeight;
}
