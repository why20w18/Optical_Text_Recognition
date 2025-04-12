#include "../../include/mainWindow.hpp"


MainWindow::MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath)
: Window(width,heigth,title) , format(format),imagePath(imagePath){
    
    ILOG("(CLASS MainWindow)");

    //MANUEL_IMAGE_READ(1)
    //wxBitmap bitmap = MainWindow::loadImage();
    //wxStaticBitmap* staticBitmap = new wxStaticBitmap(this, wxID_ANY,bitmap, wxPoint(10, 10));

    //AUTO_IMAGE_READ(2)
    //ImageReader img1(this,imagePath);
    
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
    /*
    GrayscaleOp grop(imagePath);
    grop.applyPointOperation();
    std::vector<uuchar> opImage = grop.getImage();
    //ImageReader img4(this,opImage,grop.getImageWidth(),grop.getImageHeight());

    ThresholdOp thop(grop.getImageWidth(),grop.getImageHeight(),opImage,150);
    thop.applyPointOperation();
    
    //ImageReader img5(this,thop.getImage(),thop.getImageWidth(),thop.getImageHeight(),format);
    */

    //MEDIAN FILTER
    /*
    BrightnessOp brop(imagePath,120);
    brop.applyPointOperation();
    std::vector<uuchar> opImage = brop.getImage();

    MedianFilter mf(brop.getImageWidth(),brop.getImageHeight(),opImage,APPLY_10,KERNEL_7x7);
    mf.applyFilter();

    ImageReader img2(this,mf.getFilteredImage(),brop.getImageWidth(),brop.getImageHeight());
    //ImageReader img2(this,opImage,brop.getImageWidth(),brop.getImageHeight());
    */

    BrightnessOp brop(imagePath,0);
    auto img = brop.getImage();
    int imageWidth = brop.getImageWidth();
    int imageHeight = brop.getImageHeight();

    
    MedianFilter mf(imageWidth,imageHeight,img,APPLY_1,KERNEL_5x5);
    //mf.applyFilter();
    img = mf.getFilteredImage();
    
    
    GrayscaleOp grop(imageWidth,imageHeight,img);
    grop.applyPointOperation();
    img = grop.getImage();
    
    ThresholdOp thop(imageWidth,imageHeight,img,150);
    thop.applyPointOperation();
    img = thop.getImage();

   
    RowDetect rd(imageWidth,imageHeight,img);
    auto textStartEndCols = rd.getTextLocationCols();
    img = rd.getResult();
    //img = rd.getResultRight(img);
   

    wxButton *saveButton = new wxButton(this,SAVE_BUTTON_MAIN,"Save Image");
    this->componentPosition(saveButton,SAG);

    //Bind(wxEVT_BUTTON,&MainWindow::OnSaveButton,this);
    

    for(const auto &r : textStartEndCols){
        ILOG("row : " << r[0] << " sutunBaslangic :" << r[1] << " <-> sutunBitis : " << r[2]);
    }
    
    
    ILOG("Height : " << imageHeight << " Width : " << imageWidth);

    ImageReader img4(this,img,imageWidth,imageHeight);
    

    saveButton->Bind(wxEVT_BUTTON,
        [this,img,imageWidth,imageHeight,imagePath](wxCommandEvent &e){
            this->OnSaveButton(e,imageWidth,imageHeight,img,imagePath);
        }
    );
}

MANUEL_IMAGE_READ wxBitmap MainWindow::loadImage(){
    //FileOperation fo(imagePath,format);
    //wxBitmap bitmap = fo.getWxBitmap();
    //return bitmap;
}

void MainWindow::OnSaveButton(wxCommandEvent &event,int width,int height,std::vector<uuchar> imageData,std::string imagePath){
    ILOG("GORUNTU KAYDEDILIYOR ...");

    wxImage image(width, height, const_cast<uuchar*>(imageData.data()), true);

    if(!image.IsOk()){
        ELOG("GORUNTU KAYDEDILEMEDI !" << imagePath);
        return;
    }

    size_t dotPos = imagePath.rfind('.');
    std::string ext = (dotPos != std::string::npos) ? imagePath.substr(dotPos,-1) : imagePath;
    ILOG("DOSYA UZANTISI : " << ext);

    image.SaveFile("OTR_OUT"+ext);
}