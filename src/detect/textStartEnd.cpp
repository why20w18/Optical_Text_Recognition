#include "../../include/detect/textStartEnd.hpp"


TextOp::TextOp(int imageWidth,int imageHeight,const std::vector<std::vector<uuchar>> &image2D)
: imageWidth(imageWidth) , imageHeight(imageHeight){
    this->image2D = image2D;
    this->textRowStartEnd = std::vector<std::vector<int>>(imageWidth,std::vector<int>(3,0));
    int cx = 0;

    for(int i = 0 ; i < imageWidth ; i++){  //imageWidth array icindeki array sayisini tutar
        int firstWhite = -1;
        int endWhite = -1;

        for(int j = 0 ; j < imageHeight ; j++){ //imageHeight array icinde arrayin icinde kac eleman oldugunu tutar
            if(image2D[i][j] == 255){ //beyaz piksel bulundu
                if(firstWhite == -1)
                    firstWhite = j;
                endWhite = j;
            }
        }

        if(firstWhite != -1)
            textRowStartEnd[cx++] = {i,firstWhite,endWhite};
        else 
            textRowStartEnd[cx++] = {i,0,0};
    }


}

std::vector<std::vector<int>> TextOp::getTextRowStartEnd(){
    return textRowStartEnd;
}


void TextOp::printTextRowStartEnd(){
    for(int i = 0 ; i < textRowStartEnd.size() ; i++){
        printf("[ROW-%d] text start column %d - text end column %d\n"
            ,textRowStartEnd[i][0],
            textRowStartEnd[i][1],
            textRowStartEnd[i][2]);
    }
}
