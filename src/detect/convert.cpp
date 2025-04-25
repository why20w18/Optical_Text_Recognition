#include "../../include/detect/convert.hpp"

Converter::Converter(int satir,int sutun,const std::vector<uuchar> &image_1D)
: satirSay(satir) , sutunSay(sutun){
    this->image_1D = image_1D;
    image_2D.resize(satirSay, std::vector<uuchar>(sutunSay));
}

Converter* Converter::to2D(){
    int cx = 0;
    for(int i = 0 ; i < satirSay ; i++){
        for(int j = 0 ; j < sutunSay ; j++){
            image_2D[i][j] = image_1D[cx++];
        }
    }

    return this;
}

Converter::Converter(int satir,int sutun,const std::vector<std::vector<uuchar>> &image_2D)
: satirSay(satir) , sutunSay(sutun){
    this->image_2D = image_2D;
    this->image_1D = std::vector<uuchar>(satirSay*sutunSay);

}

Converter* Converter::to1D(){
    image_1D.resize(satirSay * sutunSay);
    
    int cx = 0;
    for(int i = 0; i < satirSay; i++){
        for(int j = 0; j < sutunSay; j++){
            if(cx < satirSay*sutunSay){
                image_1D[cx++] = image_2D[i][j];
            }
        }
    }

    return this;
}


std::vector<uuchar> Converter::get1D_Image(){
    return image_1D;
}


std::vector<std::vector<uuchar>> Converter::get2D_Image(){
    return image_2D;
}

int Converter::get2D_Width(){
    return satirSay;
}

int Converter::get2D_Height(){
    return sutunSay;
}

void Converter::print1D_Image(){
    for(int i = 0 ; i < satirSay*sutunSay ; i++){
        printf("%d ,",image_1D[i]);
    }
}

void Converter::print2D_Image(){
    for(int i = 0 ; i < satirSay ; i++){
        for(int j = 0 ; j < sutunSay ; j++){
            printf("%d , ",image_2D[i][j]);
        }
        std::cout << "\n\n";
    }
}

