#ifndef __MEDIAN_FILTER_HPP__
#define __MEDIAN_FILTER_HPP__

#include <vector>
#include <algorithm>
#include "../crossPlatform.hpp"

class MedianFilter{
private:
    int imageWidth , imageHeight , filterSize , channel;
    std::vector<uuchar> imageData;

    int getFilterMedian(std::vector<uuchar> &filterWindowSize);
    void filterSizeWindow3x3();
    void filterSizeWindow7x7();

public:
    MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int filterSize=3,int channel = 3);
    void applyFilter();

};

#endif //__MEDIAN_FILTER_HPP__