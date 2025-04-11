#ifndef __CROSS_PLATFORM_HPP__
#define __CROSS_PLATFORM_HPP__

    #ifdef _WIN32
        #define IMAGE1 "../images/1.bmp"
        #define IMAGE2 "../images/2.jpeg"
        #define METIN1 "../images/metin.png"
        
        #include <wx/image.h>    
        #include <wx/wx.h>

    #elif __linux__
        #define IMAGE1_BMP "../images/1.bmp"
        #define IMAGE2_JPEG "../images/2.jpeg"
        #define METIN_PNG "../images/metin.png"
        #define METIN_GOOGLE_PNG "../images/google.png"
        

        #include <wx/image.h>
        //#include <wx-3.2/wx/compiler.h>
        //#include <wx-3.2/wx/platform.h>
        //#include <wx-3.2/wx/defs.h>
        //#include <wx-3.2/wx/frame.h>
        #include <wx-3.2/wx/wx.h>
    
    #endif


#endif //__CROSS_PLATFORM_HPP__