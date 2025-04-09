#ifndef __BRIGTHNESS_OPERATION_HPP__
#define __BRIGTHNESS_OPERATION_HPP__

#include "pointOperation.hpp"

class BrightnessOp : public PointOperation{
private:
    std::vector<uuchar> imageData;
    int imageWidth;
    int imageHeight;
    int brightVal;
    
public:
    BrightnessOp(const std::string &imagePath,int brightVal);
    void applyPointOperation() override;
    std::vector<uuchar> getImage() override;
    int getImageWidth() override;
    int getImageHeight() override;
};



#endif //__BRIGTHNESS_OPERATION_HPP__