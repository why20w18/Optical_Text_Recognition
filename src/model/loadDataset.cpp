#include "../../include/model/loadDataset.hpp"


LoadDataset::LoadDataset(const std::string &folderPath,std::vector<std::vector<double>> &inputDataRaw,
                         std::vector<std::vector<double>> &oneHotLabels ,int outputClassCount) 
:folderPath(folderPath), outputClassCount(outputClassCount)
{
    
    for(const auto &file : std::filesystem::directory_iterator(folderPath)){
        //dosyanin yolu cikartildi
        std::string filePath = file.path().string();
        
        //dosyanin uzantisini kontrol etme
        //test.bmp
        if(filePath.substr(filePath.length()-1-3) == ".bmp"){
            //ham bmp dosyası okundu ve 2D arraye eklendi
            bmpReader reader(filePath);
            auto rawPixels = reader.readConvert();
            inputDataRaw.push_back(rawPixels);

            //etiket cikartma islemi
            std::vector<double> labels(outputClassCount,0.0f);

            if(filePath.find("a_") != std::string::npos){
                labels[0] = 1.0f;                               ////{1,0} A
            }
            else if(filePath.find("b_") != std::string::npos){/////{0,1} B
                labels[1] = 1.0f;
            }

            oneHotLabels.push_back(labels);

        }
    }    
}