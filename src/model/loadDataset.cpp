#include "../../include/model/loadDataset.hpp"


LoadDataset::LoadDataset(const std::string &folderPath,std::vector<std::vector<double>> &inputDataRaw,
                         std::vector<std::vector<double>> &oneHotLabels,bool normalized ,int outputClassCount) 
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
            auto rawPixels = reader.readConvert(normalized);
            inputDataRaw.push_back(rawPixels);

            //etiket cikartma islemi
            std::vector<double> labels(outputClassCount,0.0f);

            // Dosya adından harfi çek (örneğin: "c_045.bmp" => 'c')
            std::size_t pos = filePath.find_last_of("/\\"); // klasör yolunu ayır
            std::string fileName = (pos == std::string::npos) ? filePath : filePath.substr(pos + 1);
            
            // İlk karakter harf olmalı: "c_045.bmp" -> fileName[0] = 'c'
            if (fileName.size() > 0 && std::isalpha(fileName[0])) {
                char ch = std::tolower(fileName[0]); // büyük harf olursa küçük yap
                int index = ch - 'a'; // 'a' => 0, 'b' => 1, ..., 'z' => 25
            
                if (index >= 0 && index < 26) {
                    labels[index] = 1.0f;
                } else {
                    std::cerr << "[HATA] Geçersiz karakter etiketi: " << ch << "\n";
                }
            } else {
                std::cerr << "[HATA] Dosya ismi etiketi tespit edilemedi: " << fileName << "\n";
            }

            oneHotLabels.push_back(labels);

        }
    }    
}