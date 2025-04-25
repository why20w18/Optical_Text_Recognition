#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include "window.hpp"
#include "enums.hpp"
#include "imageReader.hpp"


#include "detect/convert.hpp"
#include "detect/textStartEnd.hpp"
#include "detect/detectLine.hpp"


//#include "ocr/rowDetect.hpp"
//#include "ocr/characterDetect.hpp"

#include "image_manuel_header/manuelFileOperation.hpp"

#include "point_operation/brightnessOperation.hpp"
#include "point_operation/thresholdOperation.hpp"
#include "point_operation/grayscaleOperation.hpp"
#include "filter_operation/medianFilter.hpp"

#define DETECT_BUTTON_MAIN 1002

class MainWindow : public Window{
private:
    MANUEL_IMAGE_READ wxBitmap loadImage();
    bool isTextRow(int y) const;
    
    std::string imagePath;  
    wxBitmapType format;  
    std::vector<uuchar> preprocessedImage;
    int imageWidth;
    int imageHeight;
    std::vector<std::vector<int>> m_RowStartEnd;
    std::vector<std::vector<int>> m_CharacterLocation;

public:
    MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath);
    
    void OnSaveButton(wxCommandEvent &event,int width,int height,std::vector<uuchar> imageData,std::string image);
    void OnDetectButton(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
};


#endif //__MAIN_WINDOW_HPP__