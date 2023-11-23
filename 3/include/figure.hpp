#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Figure 
{
    public:
        Figure() = default;
        virtual ~Figure() = default;
        virtual std::pair<double,double> find_center() const = 0;
        virtual operator double() const = 0;
};