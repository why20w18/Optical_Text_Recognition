#include "../../include/filter_operation/medianFilter.hpp"

MedianFilter::MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,FILTER_KERNEL kernel357)
:imageWidth(imageWidth) , imageHeight(imageHeight),kernel357(kernel357){
    this->filteredImage = imageData;
}

void MedianFilter::applyFilter(){
    //windowRGB == KERNEL

    switch(kernel357){
        case KERNEL_3x3:
        filterSizeWindow3x3();
        break;

        case KERNEL_5x5:

        break;

        case KERNEL_7x7:

        break;
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

void MedianFilter::filterSizeWindow3x3(){
    std::vector<uuchar> resultImage = filteredImage;
    for(int y = KERNEL_3x3 ; y < imageHeight - KERNEL_3x3 ; y++){
        for(int x = KERNEL_3x3 ; x < imageWidth - KERNEL_3x3 ; x++){
            std::vector<uuchar> windowR;
            std::vector<uuchar> windowG;
            std::vector<uuchar> windowB;    

            //PENCERENIN ICINI GEZME yani olusturulan pencereyi kaydirma
            for (int dy = -KERNEL_3x3; dy <= KERNEL_3x3; dy++) { //y hareket ettirme
                for (int dx = -KERNEL_3x3; dx <= KERNEL_3x3; dx++) { //x hareket ettirme
                    int nx = x + dx;
                    int ny = y + dy;
                    int index = (ny * imageWidth + nx) * 3; //RGB

                    windowR.push_back(filteredImage[index + 0]);
                    windowG.push_back(filteredImage[index + 1]);
                    windowB.push_back(filteredImage[index + 2]);
                }
            }


            int outIndex = (y * imageWidth + x) * 3;
            resultImage[outIndex + 0] = getFilterMedian(windowR, KERNEL_3x3);
            resultImage[outIndex + 1] = getFilterMedian(windowG, KERNEL_3x3);
            resultImage[outIndex + 2] = getFilterMedian(windowB, KERNEL_3x3);
        }
    }

    filteredImage = resultImage;
    /*
    +yani sebebi merkez üzerinden kaydırmaya devam etmek istememiz mi ?
    -evet cunku kenarlara gidersek bu sefer dista kalir yani resmin disina erismemek istiyoruz bu sebeple
    1 kala baslayip 1 kala bitiriyoruz
    */
    /*
    (y-1,x-1)  (y-1,x)  (y-1,x+1)
    (y  ,x-1)  (y  ,x)  (y  ,x+1)
    (y+1,x-1)  (y+1,x)  (y+1,x+1)
    */

/*
1, 0, 1 Arası Kaydırma
Bu kaydırmanın yatay (x) ve dikey (y) iki bileşeni vardır.

dy = -KERNEL_3x3; dy <= KERNEL_3x3; dy++ ile yapılan işlem, pencereyi dikey yönde kaydırmaktır.
Yani, yukarı ve aşağıya doğru hareket etmeyi ifade eder.
dy = -1 demek, pencerenin bir piksel yukarıya kaymasıdır.
dy = 0 demek, pencerenin merkezdeki pikselin olduğu yeri gösterir (yani şu an pencereyi tam o pikselin üzerinde tutuyoruz).
dy = 1 demek, pencerenin bir piksel aşağıya kaymasıdır.

dx = -KERNEL_3x3; dx <= KERNEL_3x3; dx++ ile yapılan işlem, pencereyi yatay yönde kaydırmaktır. 
Yani, sola ve sağa doğru hareket etmeyi ifade eder.
dx = -1 demek, pencerenin bir piksel sola kaymasıdır.
dx = 0 demek, pencerenin merkezdeki pikselin olduğu yeri gösterir (yani şu an pencereyi tam o pikselin üzerinde tutuyoruz).
dx = 1 demek, pencerenin bir piksel sağa kaymasıdır.

dy ve dx değerlerinin -1, 0 ve 1 olması, pencerenin merkezini sabit tutarak, onu yukarı-aşağı ve sola-sağa doğru 
kaydırmamızı sağlar.Pencereyi kaydırırken, merkezdeki pikseli her zaman değiştirecek şekilde hareket ediyoruz.

Bu kaydırma işlemi, pencerenin etrafındaki pikselleri toplar ve bunlar üzerinden medyan değeri hesaplanarak, 
merkezdeki pikselin yeni değeri belirlenir.


*/
}

void MedianFilter::filterSizeWindow7x7(){

}

std::vector<uuchar> MedianFilter::getFilteredImage(){
    return this->filteredImage;
}
