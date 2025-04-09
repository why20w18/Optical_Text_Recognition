#include "../../include/filter_operation/medianFilter.hpp"

MedianFilter::MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int filterSize,int channel)
:imageWidth(imageWidth) , imageHeight(imageHeight), filterSize(filterSize), channel(channel){
    this->imageData = imageData;
}

void MedianFilter::applyFilter(){

}

int MedianFilter::getFilterMedian(std::vector<uuchar> &filterWindow){
    std::sort(filterWindow.begin(),filterWindow.end());
    int median = filterWindow[(filterWindow.size() / 3)+1];
    return median;
}

void MedianFilter::filterSizeWindow3x3(){

}

void MedianFilter::filterSizeWindow7x7(){

}