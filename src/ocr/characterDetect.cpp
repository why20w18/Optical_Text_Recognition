#include "../../include/ocr/characterDetect.hpp"


CharacterDetect::CharacterDetect(std::vector<std::vector<int>> &TextLocationRows){
    this->TextLocationRows = TextLocationRows;
    int rowNo = -1;
    int startRow = -1;
    int endRow = -1;
    int lastRowNo = TextLocationRows[TextLocationRows.size()-1][0];

    for(int i = 0 ; i < TextLocationRows.size() ; i++){
        rowNo = TextLocationRows[i][0];
        startRow = TextLocationRows[i][1];
        endRow = TextLocationRows[i][2];

        //metin olan satiri gezme
        for(int j = startRow ; j <= endRow ; j++){
            //her mevcut pikselin altinida kontrol edecegiz
            for(int q = rowNo ; q <= lastRowNo ; q++)

        }
    }

}

void CharacterDetect::printTextLocationRows(){
    for(int i = 0 ; i < TextLocationRows.size() ; i++){
        ILOG("ROW_NO: " << TextLocationRows[i][0] << " START_TEXT : " 
            << TextLocationRows[i][1] << " END_TEXT : " << TextLocationRows[i][2]);
    }
}
