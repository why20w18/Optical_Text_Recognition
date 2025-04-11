#ifndef __MEDIAN_FILTER_HPP__
#define __MEDIAN_FILTER_HPP__

#include "filterOperation.hpp"

class MedianFilter : public FilterOperation{
private:
    int getFilterMedian(std::vector<uuchar> &filterWindow,FILTER_KERNEL kernel357=KERNEL_3x3);

public:
    MedianFilter(int imageWidth,int imageHeight,std::vector<uuchar> &imageData,KERNEL_APPLY_COUNT
                 applyCount=APPLY_1,FILTER_KERNEL kernel357=KERNEL_3x3);
    
    void applyFilter() override;
    std::vector<uuchar> getFilteredImage() override;
};

#endif //__MEDIAN_FILTER_HPP__
/*
Medyan filtresi, normal olarak mean filtresi gibi bir resimdeki gürültüyü azaltmak için kullanılır. Ancak
resim üzerindeki detayların kaybolmaması noktasında mean filtresinden çok daha iyi sonuç verir

Medyan filtre de mean filtresi gibi her pikselin değerini hesaplamak için yakınındaki komşularına bakar
komşu pikselleri sıralayıp sıranın ortasındaki değeri alır
*/