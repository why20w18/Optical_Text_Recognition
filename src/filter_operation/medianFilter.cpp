#include "../../include/filter_operation/medianFilter.hpp"
#include "../../include/debug.hpp"

MedianFilter::MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,KERNEL_APPLY_COUNT applyCount,
                           FILTER_KERNEL kernel357){
    
    this->filteredImage = imageData;
    this->imageWidth = imageWidth;
    this->imageHeight = imageHeight;
    this->applyCount = applyCount;
    this->kernel357 =kernel357;
    ILOG("");
}

void MedianFilter::applyFilter(){
    std::vector<uuchar> resultImage = filteredImage;
    
    //ana goruntunun disina cikmayalim diye filtrenin yaricapini cikartip
    //sadece merkez piksellerde hareket etmek icin
    //x ve y merkez pikselin konumu
    int i = 0;
    while(i < applyCount){
        ILOG("MedianFilter HESAPLANIYOR MEVCUT LOOP = " << i+1);
        for(int y = kernel357 ; y < imageHeight - kernel357 ; y++){
            for(int x = kernel357 ; x < imageWidth -kernel357 ; x++){
                std::vector<uuchar> filterWindowRed;
                std::vector<uuchar> filterWindowGreen;
                std::vector<uuchar> filterWindowBlue;
    
                //yaricap uzerinden filtre kernelinin icinde gezme ve koorinatlari cikartma
                for(int gezici_y = -kernel357 ; gezici_y <= kernel357 ; gezici_y++){
                    for(int gezici_x = -kernel357 ; gezici_x <= kernel357 ; gezici_x++){
                        int komsu_x = x + gezici_x;
                        int komsu_y = y + gezici_y;
                        
                        //satir * goruntu genisligi + bulundugu konum
                        //y=satir x=kolon
                        int currentPixelLocation = (komsu_y * imageWidth + komsu_x) *3;
                        
                        filterWindowRed.push_back(filteredImage[currentPixelLocation +0]);  //red
                        filterWindowGreen.push_back(filteredImage[currentPixelLocation +1]);//green
                        filterWindowBlue.push_back(filteredImage[currentPixelLocation +2]); //blue
                    }
                }
    
                int locIndex = (y*imageWidth+x) *3;
                resultImage[locIndex+0] = getFilterMedian(filterWindowRed,kernel357);
                resultImage[locIndex+1] = getFilterMedian(filterWindowGreen,kernel357);
                resultImage[locIndex+2] = getFilterMedian(filterWindowBlue,kernel357);
            }
        }
    
        filteredImage = resultImage;
        i++;
    }
}

int MedianFilter::getFilterMedian(std::vector<uuchar> &filterWindow,FILTER_KERNEL kernel357){
    std::sort(filterWindow.begin(),filterWindow.end());

    int medianIndex = -1;
    switch(kernel357){
        case KERNEL_3x3:
            medianIndex = 4; 
        break;

        case KERNEL_5x5:
            medianIndex = 12;
        break;

        case KERNEL_7x7:
            medianIndex = 24;
        break;
    }
    return filterWindow[medianIndex];
}

std::vector<uuchar> MedianFilter::getFilteredImage(){
    return this->filteredImage;
}
