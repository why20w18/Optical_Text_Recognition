#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include "window.hpp"
#include "enums.hpp"
#include "imageReader.hpp"

#include "image_manuel_header/manuelFileOperation.hpp"

#include "point_operation/brightnessOperation.hpp"
#include "point_operation/thresholdOperation.hpp"
#include "point_operation/grayscaleOperation.hpp"
#include "filter_operation/medianFilter.hpp"

class MainWindow : public Window{
private:
    std::string imagePath;  
    wxBitmapType format;  

public:
    MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath,wxBitmapType format = wxBITMAP_TYPE_BMP);
    wxBitmap loadImage();
    
};


#endif //__MAIN_WINDOW_HPP__