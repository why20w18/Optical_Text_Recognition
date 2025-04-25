#include "../../include/detect/detectLine.hpp"



DetectLine::DetectLine(int imageWidth,int imageHeight,const std::vector<std::vector<uuchar>> &image2D,
                        std::vector<std::vector<int>> &textStartEnd)
: imageWidth(imageWidth) , imageHeight(imageHeight){
    this->textStartEnd = textStartEnd;
    this->image2D = image2D;
    
}

void DetectLine::WriteLine(){
    for(const auto &row : textStartEnd){
        int rowNo = row[0];
        int startCol = row[1];
        int endCol = row[2];
        
        if(startCol == 0 && endCol == 0)
            continue;

        for(int i = rowNo ; i < imageWidth ; i++){
            for(int j = 0 ; j < imageHeight ; j++){
                if(i == rowNo && j >= startCol && j <= endCol){
                    image2D[i][j] = 255;
                    //break;
                }
            }
        }


    }

}

std::vector<uuchar> DetectLine::getWritedImage1D(){
    Converter cvt(imageWidth,imageHeight,image2D);
    cvt.to1D();
    this->image1D = cvt.get1D_Image();
    return image1D;
}