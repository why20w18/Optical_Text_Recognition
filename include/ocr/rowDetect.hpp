#ifndef __ROW_DETECT_HPP__
#define __ROW_DETECT_HPP__

#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>
#include <map>

class RowDetect{
private:
    std::vector<std::vector<uuchar>> image2D;
    std::vector<uuchar> signedImage;
    std::vector<uuchar> orgImg;

    std::vector<std::vector<int>> RowStartEnd;

    //y ekseni == satirNo ve textin baslangic ~ bitis koordinatlarini barindirir
    //y ekseniNo,textBaslangicKolonu,textBitisKolonu
    std::vector<std::vector<int>> TextLocationCols; //{{rowNo-startLine-endLine}} sadece text olan satirlar
    std::vector<int> firstWhite;
    std::vector<int> lastBlack;
    
    

    int imageWidth , imageHeight;

    void rightDetect();

    void firstWhiteLoc();
    void lastBlackAfterWhite();



public:
    RowDetect(int imageWidth,int imageHeight,std::vector<uuchar> &preprocessedImage);
    std::vector<std::vector<int>> &getTextLocationCols();

    void ArrayConvert1Dto2D();

    std::vector<uuchar> getResultRight();
    std::vector<uuchar> getResultRight(std::vector<uuchar> &img);
    std::vector<uuchar> getResult();


};


#endif //__ROW_DETECT_HPP__