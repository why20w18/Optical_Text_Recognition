#ifndef __GRAYSCALE_OPERATION_HPP__
#define __GRAYSCALE_OPERATION_HPP__

#include "pointOperation.hpp"

class GrayscaleOp : public PointOperation{
private:

public:
    GrayscaleOp(const std::string &imagePath);
    GrayscaleOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData);

    void applyPointOperation() override;
    std::vector<uuchar> getImage() override;
    int getImageWidth() override;
    int getImageHeight() override;
};

#endif //__GRAYSCALE_OPERATION_HPP__