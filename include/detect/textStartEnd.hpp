#ifndef __CHAR_START_END_HPP__
#define __CHAR_START_END_HPP__

#include "convert.hpp"
#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>

/*
    -goruntu uzerindeki yazinin baslangic ve bitislerini her satir icin tutmali
*/

class TextOp{
private:
    int imageWidth;
    int imageHeight;
    std::vector<std::vector<uuchar>> image2D;

    std::vector<std::vector<int>> textRowStartEnd;  //{         //colNoStart          colNoEnd
                                                    //{satir_no,text_start_whpx_index,text_end_whpx_index},
                                                    //{0,24,66},
                                                    //{1,75,99}, ...
                                                    //}

public:
    TextOp(int imageWidth,int imageHeight,const std::vector<std::vector<uuchar>> &image2D);

    std::vector<std::vector<int>> getTextRowStartEnd();
    void printTextRowStartEnd();

};


#endif //__CHAR_START_END_HPP__