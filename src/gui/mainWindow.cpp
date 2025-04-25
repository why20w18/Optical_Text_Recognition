#include "../../include/mainWindow.hpp"


MainWindow::MainWindow(int width,int heigth,const std::string &title,const std::string &imagePath)
: Window(width,heigth,title) , format(format),imagePath(imagePath){
    ILOG("(CLASS MainWindow)");


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

    //////////////TEXT DETECTION/////////////
    Converter convert(imageHeight,imageWidth,img);
    std::vector<std::vector<uuchar>> img2D = convert.to2D()->get2D_Image();
    //convert.print1D_Image();
    std::cout << "\n\n\n\n\n\n\n-*-*-*-*-*-**-*-**-*-**-*-*-*-*-*-*--**-\n\n";
    //convert.print2D_Image();

    std::cout << "\n\n\n\n\n\n\n-*-*-*-*-*-**-*-**-*-**-*-*-*-*-*-*--**-\n\n";
    TextOp textop(convert.get2D_Width(),convert.get2D_Height(),img2D);
    textop.printTextRowStartEnd();    
    std::vector<std::vector<int>> textStartEnd = textop.getTextRowStartEnd();


    DetectLine dtl(convert.get2D_Width(),convert.get2D_Height(),img2D,textStartEnd);
    dtl.WriteLine();
    img = dtl.getWritedImage1D();


    ILOG("Height : " << imageHeight << " Width : " << imageWidth);

    ImageReader img4(this,img,imageWidth,imageHeight);

  


    /////////////GUI COMPONENTS/////////////
    wxButton *saveButton = new wxButton(this,SAVE_BUTTON_MAIN,"Save Image");
    this->componentPosition(saveButton,SAG);

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