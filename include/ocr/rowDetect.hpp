#ifndef __ROW_DETECT_HPP__
#define __ROW_DETECT_HPP__

#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>

class RowDetect{
private:
    std::vector<std::vector<uuchar>> image2D;
    std::vector<uuchar> preprocessedImage;

    std::vector<std::vector<int>> RowStartEnd;

    //y ekseni == satirNo ve textin baslangic ~ bitis koordinatlarini barindirir
    std::vector<std::vector<int>> TextLocationRows; //{{rowNo-startLine-endLine}} sadece text olan satirlar

    int imageWidth , imageHeight;


public:
    RowDetect(int imageWidth,int imageHeight,std::vector<uuchar> &preprocessedImage);
    std::vector<std::vector<int>> &getTextLocationRows();

    void ArrayConvert1Dto2D();

};


#endif //__ROW_DETECT_HPP__