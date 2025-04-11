#include "../../include/imageReader.hpp"

//CONSTRUCTOR_1 GUI EKLEME
ImageReader::ImageReader(Window *wthis,const std::string &imagePath)
:imagePath(imagePath){
    wxInitAllImageHandlers();

    if(!wxFileExists(imagePath)) {
        ELOG("DOSYA YOK '" << imagePath << "'");
        return;
    }

    wxImage image(imagePath.c_str(), wxBITMAP_TYPE_ANY);

    if(!image.IsOk()){
        ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-1)");
        return;
    }

    this->imageHeight = image.GetHeight();
    this->imageWidth = image.GetWidth();
    uuchar *RawData = image.GetData();
    this->imageSize = 3 * imageHeight * imageWidth;
    
    this->imageRawData = std::vector<uuchar>(RawData,RawData+imageSize);

    wxBitmap bitmap(image);
    wxStaticBitmap* staticBitmap = new wxStaticBitmap(wthis,wxID_ANY, bitmap, wxPoint(10, 10), 
                                                      wxSize(imageWidth,imageHeight)
                                                     );

   wthis->componentPosition(staticBitmap,SOL);
    
}

ImageReader::ImageReader(const std::string &imagePath)
:imagePath(imagePath){
    wxInitAllImageHandlers();

    if(!wxFileExists(imagePath)) {
        ELOG("DOSYA YOK '" << imagePath << "'");
        return;
    }


    wxImage image(imagePath.c_str(), wxBITMAP_TYPE_ANY);

    

    if(!image.IsOk()){
        ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-2)");
        return;
    }

    this->imageHeight = image.GetHeight();
    this->imageWidth = image.GetWidth();
    uuchar *RawData = image.GetData();
    this->imageSize = 3 * imageHeight * imageWidth;
    
    this->imageRawData = std::vector<uuchar>(RawData,RawData+imageSize);
}

ImageReader::ImageReader(Window *wthis,const std::vector<uuchar> imageData,
    int imageWidth , int imageHeight)
    : imageWidth(imageWidth) , imageHeight(imageHeight), imageRawData(imageData){
        wxInitAllImageHandlers();
    
        wxImage image(imageWidth, imageHeight, const_cast<uuchar*>(imageRawData.data()), true);
    
        if (!image.IsOk()){
            ELOG("GORUNTU YUKLENEMEDI (CLASS ImageReader-3)");
            return;
        }
    
        wxBitmap bitmap(image);
        wxStaticBitmap* staticBitmap = new wxStaticBitmap(wthis, wxID_ANY, bitmap, wxPoint(10, 10), wxSize(imageWidth, imageHeight));
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