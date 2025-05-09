#ifndef __BRIGTHNESS_OPERATION_HPP__
#define __BRIGTHNESS_OPERATION_HPP__

#include "pointOperation.hpp"

class BrightnessOp : public PointOperation{
private:
    int brightVal;
    
public:
    BrightnessOp(int brightVal);

    int getWidth() override;
    int getHeight() override;
    std::vector<double> getRawPixelData() override;
    void applyPointOperation() override;

};



#endif //__BRIGTHNESS_OPERATION_HPP__