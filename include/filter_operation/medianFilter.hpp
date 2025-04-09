#ifndef __MEDIAN_FILTER_HPP__
#define __MEDIAN_FILTER_HPP__

#include <vector>
#include <algorithm>
#include "../crossPlatform.hpp"
#include "../enums.hpp"

class MedianFilter{
private:
    int imageWidth , imageHeight;
    FILTER_KERNEL kernel357;
    std::vector<uuchar> filteredImage;
   

    int getFilterMedian(std::vector<uuchar> &filterWindow,FILTER_KERNEL kernel357=KERNEL_3x3);
    void filterSizeWindow3x3();
    void filterSizeWindow7x7();

public:
    MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,FILTER_KERNEL kernel357=KERNEL_3x3);
    void applyFilter();
    std::vector<uuchar> getFilteredImage();
};

#endif //__MEDIAN_FILTER_HPP__
/*
Medyan filtresi, normal olarak mean filtresi gibi bir resimdeki gürültüyü azaltmak için kullanılır. Ancak
resim üzerindeki detayların kaybolmaması noktasında mean filtresinden çok daha iyi sonuç verir

Medyan filtre de mean filtresi gibi her pikselin değerini hesaplamak için yakınındaki komşularına bakar
komşu pikselleri sıralayıp sıranın ortasındaki değeri alır
*/