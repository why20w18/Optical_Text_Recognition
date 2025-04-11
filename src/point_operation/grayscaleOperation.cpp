#include "../../include/point_operation/grayscaleOperation.hpp"
//https://support.ptc.com/help/mathcad/r9.0/en/index.html#page/PTC_Mathcad_Help/example_grayscale_and_color_in_images.html

GrayscaleOp::GrayscaleOp(const std::string &imagePath){
    std::tie(this->imageWidth,this->imageHeight,this->imageData) = PointOperation::getImageDatas(imagePath);
    ILOG("GrayscaleOp-1 : " << imageWidth << " , " << imageHeight);

}

GrayscaleOp::GrayscaleOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->imageData = imageData;
    ILOG("GrayscaleOp-2 : " << imageWidth << " , " << imageHeight);

}

void GrayscaleOp::applyPointOperation(){
    int totalPixel = imageWidth * imageHeight;
    
    for(int i = 0 ; i < totalPixel ; i++){
        int locPixel = i * 3;
        
        uuchar red = this->imageData[locPixel+0];   //R
        uuchar green = this->imageData[locPixel+1]; //G
        uuchar blue = this->imageData[locPixel+2];  //B

        uuchar gray = red*0.299 + green*0.587 + blue*0.114;

        this->imageData[locPixel+0] = gray;
        this->imageData[locPixel+1] = gray;
        this->imageData[locPixel+2] = gray;
    }
}

std::vector<uuchar> GrayscaleOp::getImage(){
    return this->imageData;
}

int GrayscaleOp::getImageWidth(){
    return this->imageWidth;
}

int GrayscaleOp::getImageHeight(){
    return this->imageHeight;
}