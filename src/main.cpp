#include "../include/mainWindow.hpp"
#include "../include/manuelFileOperation.hpp"

class MyApp : public wxApp {
public:
    virtual bool OnInit() override {
        system("pwd");
        Window* mainWin = new MainWindow(640, 480,"Pencere","../images/1.bmp",BMP_FILE_FORMAT);
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