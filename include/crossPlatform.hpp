#ifndef __CROSS_PLATFORM_HPP__
#define __CROSS_PLATFORM_HPP__

//CROSS PLATFORM HPP
typedef unsigned int uuint;
//CROSS PLATFORM HPP
typedef unsigned char uuchar;
//CROSS PLATFORM HPP
typedef unsigned long uulong;



#define IMAGE1 "../images/1.bmp"
#define IMAGE2 "../images/2.jpeg"


    #ifdef _WIN32
        #include <wx/image.h>    
        #include <wx/wx.h>

    #elif __linux__
        #include <wx/image.h>
        //#include <wx-3.2/wx/compiler.h>
        //#include <wx-3.2/wx/platform.h>
        //#include <wx-3.2/wx/defs.h>
        //#include <wx-3.2/wx/frame.h>
        #include <wx-3.2/wx/wx.h>
    
    #endif


#endif //__CROSS_PLATFORM_HPP__