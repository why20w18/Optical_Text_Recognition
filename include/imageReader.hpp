#ifndef __IMAGE_READER_HPP__
#define __IMAGE_READER_HPP__

#include "enums.hpp"
#include "debug.hpp"
#include "crossPlatform.hpp"
#include "window.hpp"

#include <string>


class ImageReader{
private:
    std::string imagePath;
    int channel;
    int imageWidth,imageHeight;
    uulong imageSize;
    std::vector<uuchar> imageRawData;


public:
    ImageReader(wxFrame *wthis,const std::string &imagePath,wxBitmapType format = wxBITMAP_TYPE_BMP);
    ImageReader(wxFrame *wthis,const std::vector<uuchar> imageData,
        int imageWidth , int imageHeight,wxBitmapType format = wxBITMAP_TYPE_BMP);
    

    ImageReader(const std::string &imagePath,wxBitmapType format = wxBITMAP_TYPE_BMP);
    

    std::vector<uuchar> getImageData();
    int getImageWidth();
    int getImageHeight();
};

#endif 