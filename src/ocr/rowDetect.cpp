#include "../../include/ocr/rowDetect.hpp"

RowDetect::RowDetect(int imageWidth, int imageHeight, std::vector<uuchar> &preprocessedImage){
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->signedImage = preprocessedImage;
    this->orgImg = preprocessedImage;
    this->RowStartEnd = std::vector<std::vector<int>>(imageHeight, std::vector<int>(2, -1));

    firstWhiteLoc();
    //lastBlackAfterWhite();

    rightDetect();

    for(int i = 0 ; i < firstWhite.size() - 1 ; i++)
        ILOG("row : " << i << " value : " << firstWhite[i]);
    
        
    
 
    
}

    //TextLocationCols baslangicini alicagiz
    //ilk beyaz noktayi bulacagiz
    //ilk beyaz nokta ile textlocationcols arasini cizecegiz


void RowDetect::firstWhiteLoc() {
    firstWhite.clear();
    firstWhite.resize(imageHeight, -1);  

    int totalPixel = imageWidth * imageHeight;

    for (int i = 0; i < totalPixel; i++) {
        int row = i / imageWidth;  
        int col = i % imageWidth;  
        int idx = i * 3;  

        if (orgImg[idx] == 255 && orgImg[idx + 1] == 255 && orgImg[idx + 2] == 255 && firstWhite[row] == -1) {
            firstWhite[row] = i;  // Bu satırdaki ilk beyazın kolonunu kaydet
        }
    }
    
    for (int row = 0; row < imageHeight; row++) {
        if (firstWhite[row] == -1) {
            ILOG("Satır " << row << " için beyaz piksel bulunamadı.");
        }
    }
}

void RowDetect::lastBlackAfterWhite(){
    lastBlack.clear();
    lastBlack.resize(imageHeight, -1);  

    int totalPixel = imageWidth * imageHeight;


}





void RowDetect::rightDetect(){
    int totalPixel = imageWidth*imageHeight;
    
    //2d matris
    
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
        if(signedImage[locPixel + 0] == 0 && signedImage[locPixel + 1] == 0 && signedImage[locPixel + 2] == 0) {
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
        //ILOG("row-" << rowCount << " start-" << currentLineStart << " , end-" << currentLineEnd);
    }

    //son satir
    if(isStart){
        RowStartEnd[rowCount][1] = currentLineEnd;
    }
}

void RowDetect::ArrayConvert1Dto2D(){
    for (int i = 0; i < this->imageWidth; i++){
        for (int j = 0; j < this->imageHeight; j++){
            int z = i*imageWidth+j;
            this->image2D[i][j] = this->signedImage[z];
        }
    }
}


std::vector<std::vector<int>> &RowDetect::getTextLocationCols(){
    for(int i = 0 ; i < imageHeight ; i++){
        if(RowStartEnd[i][1] - RowStartEnd[i][0] != imageWidth-1){
            //ILOG("FARK" << RowStartEnd[i][1] - RowStartEnd[i][0]);
            this->TextLocationCols.push_back({i,RowStartEnd[i][0],RowStartEnd[i][1]});
        }
    }
    return this->TextLocationCols;
}

std::vector<uuchar> RowDetect::getResultRight(){

    for(const auto &row : TextLocationCols){
        int rowNum = row[0];
        int startCol = row[1] % imageWidth;  
        int endCol = row[2] % imageWidth;    
        
        for(int col = startCol; col <= endCol; col++){
            signedImage[(rowNum * imageWidth + col) * 3 + 0] = 255;  // R
            signedImage[(rowNum * imageWidth + col) * 3 + 1] = 0;    // G
            signedImage[(rowNum * imageWidth + col) * 3 + 2] = 0;    // B
        }
    }

    return this->signedImage;
}


std::vector<uuchar> RowDetect::getResultRight(std::vector<uuchar> &img){

    for(const auto &row : TextLocationCols){
        int rowNum = row[0];
        int startCol = row[1] % imageWidth;  
        int endCol = row[2] % imageWidth;    
        
        for(int col = startCol; col <= endCol; col++) {
            img[(rowNum * imageWidth + col) * 3 + 0] = 255;  // R
            img[(rowNum * imageWidth + col) * 3 + 1] = 0;    // G
            img[(rowNum * imageWidth + col) * 3 + 2] = 0;    // B
        }
    }

    return img;
}

std::vector<uuchar> RowDetect::getResult() {
    //get result right gibi calisacak ama 
    //startCol firstWhitedaki doldurdugumuz ilk piksel
    //endCol TextLocationCols 2.kolonu aliriz
    //startCol ve endCol arasini yesile boyamali

    for(const auto &row : TextLocationCols){
        int rowNum = row[0];   
        int startCol = firstWhite[rowNum] %imageWidth;  
        int endCol = row[2] %imageHeight;    

        
        
        
            for(int col = startCol; col <= endCol; col++){
                signedImage[(rowNum * imageWidth + col) * 3 + 0] = 0;  // R
                signedImage[(rowNum * imageWidth + col) * 3 + 1] = 255;    // G
                signedImage[(rowNum * imageWidth + col) * 3 + 2] = 0;    // B
            }
        }
    

    return this->signedImage;
}
