#ifndef __BRIGTHNESS_OPERATION_HPP__
#define __BRIGTHNESS_OPERATION_HPP__

#include "pointOperation.hpp"

class BrightnessOp : public PointOperation{
private:
    int brightVal;
    
public:
    BrightnessOp(const std::string &imagePath,int brightVal);
    BrightnessOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int brightVal);
    
    void applyPointOperation() override;
    std::vector<uuchar> getImage() override;
    int getImageWidth() override;
    int getImageHeight() override;
};



#endif //__BRIGTHNESS_OPERATION_HPP__