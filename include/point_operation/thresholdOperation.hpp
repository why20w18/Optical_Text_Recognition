#ifndef __THRESHOLD_OPERATION_HPP__
#define __THRESHOLD_OPERATION_HPP__

#include "pointOperation.hpp"

class ThresholdOp : public PointOperation{
private:
    int minThreshold;
    int maxThreshold;
    int threshold;

public:
    ThresholdOp(const std::string &imagePath,int threshold,int minThreshold = 0, int maxThreshold = 255);
    ThresholdOp(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,int threshold,
                int minThreshold = 0 , int maxThreshold = 255);

    void applyPointOperation() override;
    std::vector<uuchar> getImage() override;
    int getImageWidth() override;
    int getImageHeight() override;
};


#endif // __THRESHOLD_OPERATION_HPP__