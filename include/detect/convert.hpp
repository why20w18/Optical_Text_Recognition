#ifndef __CONVERT_HPP__
#define __CONVERT_HPP__

#include "../imageReader.hpp"
#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>

class Converter{
private:
    int satirSay;
    int sutunSay;

    std::vector<uuchar> image_1D;
    std::vector<std::vector<uuchar>> image_2D;

public:
    Converter(int satir,int sutun,const std::vector<uuchar> &image_1D);
    Converter* to2D();
   
    Converter(int satir,int sutun,const std::vector<std::vector<uuchar>> &image_2D);
    Converter* to1D();
    
    std::vector<std::vector<uuchar>> get2D_Image();
    std::vector<uuchar> get1D_Image();

    int get2D_Width();
    int get2D_Height();

    void print1D_Image();
    void print2D_Image();
    

};

#endif //__CONVERT_HPP__