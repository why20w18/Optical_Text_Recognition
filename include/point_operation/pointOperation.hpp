#ifndef __POINT_OPERATION_HPP__
#define __POINT_OPERATION_HPP__

#include <vector>
#include <tuple>
#include "../imageReader.hpp"

class PointOperation{
protected:
    std::vector<uuchar> imageData;
    int imageWidth;
    int imageHeight;

    virtual ~PointOperation() = default;
    virtual void applyPointOperation() = 0;

    virtual std::vector<uuchar> getImage() = 0;
    virtual int getImageWidth() = 0;
    virtual int getImageHeight() = 0;
    
public:
    //non virtual method def
    static std::tuple<int,int,std::vector<uuchar>> getImageDatas(const std::string &imagePath,wxBitmapType format=wxBITMAP_TYPE_BMP,int channel=3){
        ImageReader imread(imagePath,format);
        int imageWidth = imread.getImageWidth();
        int imageHeight = imread.getImageHeight();
        std::vector<uuchar> imageData = imread.getImageData();
        return std::make_tuple(imageWidth,imageHeight,imageData);
    }

    static int scaleRange(int val , int minRange , int maxRange){
        if(val > maxRange)
            return maxRange;
        if(val < minRange)
            return minRange;
        return val;
    }

};




#endif //__POINT_OPERATION_HPP__