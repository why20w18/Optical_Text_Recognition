#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include "window.hpp"
#include "enums.hpp"
#include "manuelFileOperation.hpp"
#include "imageReader.hpp"

#include "point_operation/brightnessOperation.hpp"

class MainWindow : public Window{
private:
    std::string imagePath;  
    FILE_FORMAT format;  

public:
    MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath,FILE_FORMAT format);
    wxBitmap loadImage();
    
};


#endif //__MAIN_WINDOW_HPP__