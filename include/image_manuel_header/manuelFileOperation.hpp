#ifndef __FILE_OPERATION_HPP__
#define __FILE_OPERATION_HPP__

#include "../enums.hpp"
#include "bmpHeader.hpp"

#include "../debug.hpp"
#include "../crossPlatform.hpp"

#include <fstream> //ifstream-ofstream-fstream
#include <string>
#include <vector>

class FileOperation{
private:
    std::string filePath;
    std::ifstream file;
    std::vector<uuchar> fileBytes;

    int imageWidth , imageHeight;

public:
    FileOperation(const std::string filePath,FILE_FORMAT format);
    ~FileOperation();

    void printFileBytes();
    std::vector<uuchar> getFileBytes();
    wxBitmap getWxBitmap(bool isRGB = true);
    std::vector<int> getResolution(FILE_FORMAT format);

};


#endif //__FILE_OPERATION_HPP__