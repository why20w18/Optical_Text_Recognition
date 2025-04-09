#include "../../include/manuelFileOperation.hpp"


FileOperation::FileOperation(const std::string filePath,FILE_FORMAT format)
: filePath(filePath){
    file.open(filePath,std::ios::binary);

    if(!file){
        ELOG("DOSYA ACILAMADI ! (CLASS FileOperation)");
        return;
    }
    std::vector<int> resolution(2);
    resolution = getResolution(format);

    this->imageWidth = resolution[2];
    this->imageHeight = resolution[3];

    char byte;
    while(!file.eof()){
        file.get(byte);
        fileBytes.push_back(static_cast<uuchar>(byte));
    }
    
    ///////!!!!!!
    int rowSize = imageWidth * 3;
        
    for (int row = 0; row < imageHeight / 2; ++row) {
        for (int col = 0; col < rowSize; ++col) {
            std::swap(fileBytes[row * rowSize + col], fileBytes[(imageHeight - row - 1) * rowSize + col]);
        }
    }

}

FileOperation::~FileOperation(){
    file.close();   
    ILOG(filePath << " KONUMUNDAKI DOSYA KAPATILDI !");
}
    


std::vector<uuchar> FileOperation::getFileBytes(){
    return fileBytes;
}

void FileOperation::printFileBytes(){
    for(uuint i = 0; i < fileBytes.size(); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(fileBytes[i]) << std::endl;
    }
}

wxBitmap FileOperation::getWxBitmap(bool isRGB){
    wxImage image(imageWidth,imageHeight,fileBytes.data(),isRGB);
    wxBitmap bitmap(image);

    return bitmap;
}

std::vector<int> FileOperation::getResolution(FILE_FORMAT format){

    std::ifstream readerHeader(filePath,std::ios::binary);
    std::vector<int> resolution(2);

    switch(format){
        case BMP_FILE_FORMAT:
            ILOG("BMP FILE GET RESOULUTON");
            char header[BMP_HEADER];
            readerHeader.read(header,BMP_HEADER);

            char infoheader[BMP_INFO_HEADER];
            readerHeader.read(infoheader,BMP_INFO_HEADER);
            int width = *reinterpret_cast<int*>(&infoheader[BMP_RES_WIDTH_INDEX]);
            int height = *reinterpret_cast<int*>(&infoheader[BMP_RES_HEIGHT_INDEX]);

            resolution.push_back(width);
            resolution.push_back(height);

            ILOG("BMP FILE GET RESOULUTON : " << width << " , " << height);
        break;
    }

    readerHeader.close();
    return resolution;
}