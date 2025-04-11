#ifndef __CHARACHTER_DETECT_HPP__
#define __CHARACHTER_DETECT_HPP__

#include "../enums.hpp"
#include "../debug.hpp"

#include <vector>

class CharacterDetect{
private:
    std::vector<std::vector<int>> TextLocationRows;

public:
    CharacterDetect(std::vector<std::vector<int>> &TextLocationRows);
    void printTextLocationRows();

    
};

#endif //__CHARACHTER_DETECT_HPP__