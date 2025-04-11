#ifndef __ENUMS_HPP__
#define __ENUMS_HPP__

#define MANUEL_IMAGE_READ
#define AUTO_IMAGE_READ

typedef unsigned int uuint;
typedef unsigned char uuchar;
typedef unsigned long uulong;

enum FILE_FORMAT : int{
    BMP_FILE_FORMAT ,
    PNG_FILE_FORMAT ,
    JPEG_FILE_FORMAT ,
};

enum FILTER_KERNEL : int{
    KERNEL_3x3 = 1,
    KERNEL_5x5 = 2,
    KERNEL_7x7 = 3, //r yaricapi kernelin
    KERNEL_9x9 = 4
};

enum KERNEL_APPLY_COUNT{
    APPLY_1 = 1,
    APPLY_2,
    APPLY_3,
    APPLY_4,
    APPLY_5,
    APPLY_6,
    APPLY_7,
    APPLY_8,
    APPLY_9,
    APPLY_10
};

enum BUTTON_CONNECTION{
    SAVE_BUTTON_MAIN,
};

enum COMPONENT_POSITION : int{
    SOL,
    SAG,
    ALT,
    UST,
    ORTA,
    GENISLEYEN_SATIR,
    GENISLEYEN_SATIRSUTUN
};


#endif //__ENUMS_HPP__