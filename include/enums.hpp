#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

#define MANUEL_IMAGE_READ
#define AUTO_IMAGE_READ

enum FILE_FORMAT : int{
    BMP_FILE_FORMAT ,
    PNG_FILE_FORMAT ,
    JPEG_FILE_FORMAT ,
};

enum FILTER_KERNEL{
    KERNEL_3x3 = 1,
    KERNEL_5x5 = 2,
    KERNEL_7x7 = 3 //r yaricapi kernelin
};



#endif //__ENUMS_HPP__