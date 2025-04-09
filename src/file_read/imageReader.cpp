#include "../../include/imageReader.hpp"

//CONSTRUCTOR_1 GUI EKLEME
ImageReader::ImageReader(wxFrame *wthis,const std::string &imagePath,wxBitmapType format,int channel)
:channel(channel) , imagePath(imagePath){
    wxInitAllImageHandlers();
    wxImage image(imagePath.c_str(), format);

    if(!image.IsOk()){
        ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-1)");
        return;
    }

    this->imageHeight = image.GetHeight();
    this->imageWidth = image.GetWidth();
    uuchar *RawData = image.GetData();
    this->imageSize = channel * imageHeight * imageWidth;
    
    this->imageRawData = std::vector<uuchar>(RawData,RawData+imageSize);

    wxBitmap bitmap(image);
    wxStaticBitmap* staticBitmap = new wxStaticBitmap(wthis,wxID_ANY, bitmap, wxPoint(10, 10), 
                                                      wxSize(imageWidth,imageHeight)
                                                     );
}

ImageReader::ImageReader(const std::string &imagePath,wxBitmapType format,int channel )
:channel(channel) , imagePath(imagePath){
    wxInitAllImageHandlers();
    wxImage image(imagePath.c_str(), format);

    if(!image.IsOk()){
        ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-2)");
        return;
    }

    this->imageHeight = image.GetHeight();
    this->imageWidth = image.GetWidth();
    uuchar *RawData = image.GetData();
    this->imageSize = channel * imageHeight * imageWidth;
    
    this->imageRawData = std::vector<uuchar>(RawData,RawData+imageSize);
}

ImageReader::ImageReader(wxFrame *wthis,const std::vector<uuchar> imageData,
    int imageWidth , int imageHeight,wxBitmapType format,int channel )
    : channel(channel) , imageWidth(imageWidth) , imageHeight(imageHeight), imageRawData(imageData){


        wxInitAllImageHandlers();

        if (channel != 3) {
            ELOG("SADECE 3 KANALLI (RGB) DESTEKLENIYOR (CLASS ImageReader-3)");
            return;
        }
    
        wxImage image(imageWidth, imageHeight, const_cast<uuchar*>(imageRawData.data()), true);
    
        if (!image.IsOk()) {
            ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-3)");
            return;
        }
    
        wxBitmap bitmap(image);
        new wxStaticBitmap(wthis, wxID_ANY, bitmap, wxPoint(10, 10), wxSize(imageWidth, imageHeight));
}



std::vector<uuchar> ImageReader::getImageData(){
    return this->imageRawData;
}

int ImageReader::getImageWidth(){
    return this->imageWidth;
}

int ImageReader::getImageHeight(){
    return this->imageHeight;
}