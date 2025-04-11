#include "../include/mainWindow.hpp"
#include "../include/image_manuel_header/manuelFileOperation.hpp"

class MyApp : public wxApp {
public:
    virtual bool OnInit() override {
        system("pwd");
        Window* mainWin = new MainWindow(720, 540,"Pencere",METIN_GOOGLE_PNG);
        mainWin->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

/*
int main(){
    FileOperation fo("../images/1.bmp");
    fo.printFileBytes();

    return 0x0;
}
*/