#ifndef __DETECT_LINE_HPP__
#define __DETECT_LINE_HPP__

#include "convert.hpp"
#include "textStartEnd.hpp"

#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>

class DetectLine{
private:
    int imageWidth;
    int imageHeight;
    std::vector<std::vector<uuchar>> image2D;
    std::vector<uuchar> image1D;

    std::vector<std::vector<int>> textStartEnd;

public:
    DetectLine(int imageWidth,int imageHeight,const std::vector<std::vector<uuchar>> &image2D,
               std::vector<std::vector<int>> &textStartEnd);

    void WriteLine();
    std::vector<uuchar> getWritedImage1D();

};


#endif //__DETECT_LINE_HPP__