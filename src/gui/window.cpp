#include "../../include/window.hpp"

Window::Window(int width , int height,const std::string &title)
: wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(width,height)){
    ILOG("'"<< title << "' ADLI PENCERE OLUSTURULDU (CLASS Window)");

}


int Window::getWidth(){
    wxSize width = this->GetSize();
    return width.GetWidth();
}

int Window::getHeight(){
    wxSize height = this->GetSize();
    return height.GetHeight();
}

std::string Window::getTitle(){
    return this->GetTitle().ToStdString();
}

void Window::printMessage(const std::string &msg,const std::string &title){
    wxMessageBox(msg,title,wxOK | wxICON_INFORMATION);
}
