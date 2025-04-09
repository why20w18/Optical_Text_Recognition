#include "../../include/mainWindow.hpp"


MainWindow::MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath,FILE_FORMAT format)
: Window(width,heigth,title) , format(format),imagePath(imagePath){
    
    ILOG("(CLASS MainWindow)");

    //MANUEL_IMAGE_READ(1)
    //wxBitmap bitmap = MainWindow::loadImage();
    //wxStaticBitmap* staticBitmap = new wxStaticBitmap(this, wxID_ANY,bitmap, wxPoint(10, 10));

    //AUTO_IMAGE_READ(2)
    //ImageReader img1(this,imagePath,wxBITMAP_TYPE_BMP);
    
    //BRIGHTNESS OPERATION(3)
    /*
    BrightnessOp brop(imagePath,0);
    brop.applyPointOperation();
    std::vector<uuchar> opImage = brop.getImage();
    ImageReader img2(this,opImage,brop.getImageWidth(),brop.getImageHeight());
    */

    //THRESHOLD OPERATION(4)
    /*
    ThresholdOp thop(imagePath,150);
    thop.applyPointOperation();
    std::vector<uuchar> opImage = thop.getImage();
    ImageReader img3(this,opImage,thop.getImageWidth(),thop.getImageHeight());
    */

    //POINT OPERATION SONRASI GORUNTUYU EKRANA TASIMA(3)
    //BRIGHTNESS AND THRESHOLDING OPERATION
    /*
    BrightnessOp brop(imagePath,0);
    brop.applyPointOperation();
    std::vector<uuchar> opImage = brop.getImage();
    ThresholdOp thop(brop.getImageWidth(),brop.getImageHeight(),opImage,150);
    thop.applyPointOperation();
    ImageReader img3(this,thop.getImage(),thop.getImageWidth(),thop.getImageHeight());
    */

    //GRAYSCALE POINT OPERATION AND THRESHOLDING
    GrayscaleOp grop(imagePath);
    grop.applyPointOperation();
    std::vector<uuchar> opImage = grop.getImage();
    //ImageReader img4(this,opImage,grop.getImageWidth(),grop.getImageHeight());

    ThresholdOp thop(grop.getImageWidth(),grop.getImageHeight(),opImage,150);
    thop.applyPointOperation();

    
    ImageReader img5(this,thop.getImage(),thop.getImageWidth(),thop.getImageHeight());
  
}

MANUEL_IMAGE_READ wxBitmap MainWindow::loadImage(){
    FileOperation fo(imagePath,format);
    wxBitmap bitmap = fo.getWxBitmap();
    return bitmap;
}