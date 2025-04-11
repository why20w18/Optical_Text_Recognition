#include "../../include/window.hpp"

Window::Window(int width , int height,const std::string &title)
: wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(width,height)){
    CenterOnScreen();

    ILOG("'"<< title << "' ADLI PENCERE OLUSTURULDU (CLASS Window)");

    SetMaxSize(wxSize(width+100,height+100));
    SetMinSize(wxSize(width-50,height-50));

    this->windowSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(this->windowSizer);

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
void Window::componentPosition(wxWindow *object, COMPONENT_POSITION pos,int margin){
    switch(pos){
        case UST:
            windowSizer->Add(object, 0, wxALL | wxALIGN_TOP, margin);
        break;
        case ALT:
            windowSizer->Add(object, 0, wxALL | wxALIGN_BOTTOM, margin);
        break;
        case SOL:
            windowSizer->Add(object, 0, wxALL | wxALIGN_LEFT, margin);
        break;
        case SAG:
            windowSizer->Add(object, 0, wxALL | wxALIGN_RIGHT, margin);
        break;
        case ORTA:
            windowSizer->Add(object, 0, wxALL | wxALIGN_CENTER_VERTICAL, margin);
        break;
        case GENISLEYEN_SATIR:
            windowSizer->Add(object, 0, wxALL | wxEXPAND, margin);
        break;
        case GENISLEYEN_SATIRSUTUN:
            windowSizer->Add(object, 1, wxALL | wxEXPAND, margin);
        break;
        default:
            ELOG("GECERSIZ COMPONENT POZISYONU");
        break;
    }
}