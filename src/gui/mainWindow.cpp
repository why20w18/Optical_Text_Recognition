#include "../../include/mainWindow.hpp"


MainWindow::MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath,FILE_FORMAT format)
: Window(width,heigth,title) , format(format),imagePath(imagePath){
    
    ILOG("(CLASS MainWindow)");

    //MANUEL_IMAGE_READ(1)
    //wxBitmap bitmap = MainWindow::loadImage();
    //wxStaticBitmap* staticBitmap = new wxStaticBitmap(this, wxID_ANY,bitmap, wxPoint(10, 10));

    //AUTO_IMAGE_READ(2)
    //ImageReader img1(this,imagePath,wxBITMAP_TYPE_BMP);
    

    //POINT OPERATION SONRASI GORUNTUYU EKRANA TASIMA(3)
    BrightnessOp brop(imagePath,60);
    brop.applyPointOperation();
    std::vector<uuchar> opImage = brop.getImage();
    ImageReader img2(this,opImage,brop.getImageWidth(),brop.getImageHeight());

  
}

MANUEL_IMAGE_READ wxBitmap MainWindow::loadImage(){
    FileOperation fo(imagePath,format);
    wxBitmap bitmap = fo.getWxBitmap();
    return bitmap;
}