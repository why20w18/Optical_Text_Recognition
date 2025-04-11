#include "../../include/ocr/rowDetect.hpp"

RowDetect::RowDetect(int imageWidth, int imageHeight, std::vector<uuchar> &preprocessedImage){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->preprocessedImage = preprocessedImage;
    int totalPixel = imageWidth*imageHeight;
    
    //2d matris
    this->RowStartEnd = std::vector<std::vector<int>>(imageHeight, std::vector<int>(2, -1));
    
    int rowCount = 0;
    int currentLineStart = -1;
    int currentLineEnd = -1;
    bool isStart = false;
    
    for(int i = 0; i < totalPixel; i++){
        int locPixel = i * 3;
        
        //eger genislikte tam bolunuyorsa yeni satira gec
        if (i % imageWidth == 0 && i != 0){
            
            if (isStart){
                RowStartEnd[rowCount][1] = currentLineEnd;
                isStart = false;//
            }
            rowCount++;
            currentLineStart = -1;
            currentLineEnd = -1;
        }

        //siyah piksel kontrolu
        if(preprocessedImage[locPixel + 0] == 0 && preprocessedImage[locPixel + 1] == 0 && preprocessedImage[locPixel + 2] == 0) {
            if(!isStart){//satir basiysa kayit
                currentLineStart = i;
                isStart = true;
                RowStartEnd[rowCount][0] = currentLineStart;
            }
            currentLineEnd = i; //satir basi degilse ama siyahsa yine kaydet
        } 
        else{
            if(isStart){ //siyah degil ve basta degilse oncekini kaydet
                RowStartEnd[rowCount][1] = currentLineEnd;
                isStart = false;
            }
        }
        ILOG("row-" << rowCount << " start-" << currentLineStart << " , end-" << currentLineEnd);
    }

    //son satir
    if(isStart){
        RowStartEnd[rowCount][1] = currentLineEnd;
    }


    for(int i = 0; i < imageHeight; i++){
        ILOG("row - " << i << " : "<< RowStartEnd[i][0] << " <-> " << RowStartEnd[i][1] << " --> " << RowStartEnd[i][1]-RowStartEnd[i][0]);
    }
}

void RowDetect::ArrayConvert1Dto2D(){
    int z = 0;
    for (int i = 0; i < this->imageWidth; i++){
        for (int j = 0; j < this->imageHeight; j++){
            this->image2D[i][j] = this->preprocessedImage[z++];
        }
    }
}

std::vector<std::vector<int>> &RowDetect::getTextLocationRows(){
    for(int i = 0 ; i < imageHeight ; i++){
        if(RowStartEnd[i][1] - RowStartEnd[i][0] != imageWidth-1){
            //ILOG("FARK" << RowStartEnd[i][1] - RowStartEnd[i][0]);
            this->TextLocationRows.push_back({i,RowStartEnd[i][0],RowStartEnd[i][1]});
        }
    }
    return this->TextLocationRows;
}