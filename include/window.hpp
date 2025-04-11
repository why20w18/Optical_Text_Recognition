#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "crossPlatform.hpp"
#include "debug.hpp"
#include "enums.hpp"

#include <string>

class Window : public wxFrame{
private:
    wxSizer *windowSizer;

public:
    void componentPosition(wxWindow* component,COMPONENT_POSITION positipn,int margin = 20);

protected:
    //constructor - virtual destructor
    Window(int width , int height,const std::string &title);
    virtual ~Window() = default;

    

    int getWidth();
    int getHeight();
    std::string getTitle();

    void printMessage(const std::string &msg,const std::string &title);
    
};


#endif //__WINDOW_HPP__