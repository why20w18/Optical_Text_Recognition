#ifndef __FILTER_OPERATION_HPP__
#define __FILTER_OPERATION_HPP__

#include <vector>
#include <algorithm>
#include "../crossPlatform.hpp"
#include "../enums.hpp"

class FilterOperation{
protected:
    int imageWidth , imageHeight;
    KERNEL_APPLY_COUNT applyCount;
    FILTER_KERNEL kernel357;
    std::vector<uuchar> filteredImage;

public:
    virtual ~FilterOperation() = default;
    virtual void applyFilter() = 0;
    virtual std::vector<uuchar> getFilteredImage() = 0;
};

#endif