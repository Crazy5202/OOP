#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

class Figure 
{
    public:
        Figure() = default;
        virtual ~Figure() = default;
        virtual operator double() const = 0;
};