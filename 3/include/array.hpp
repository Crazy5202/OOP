#pragma once

#include "figure.hpp"

class Array 
{
    private:
        Figure** figures;
        size_t size;
    public:
        Array();
        Array(size_t input);
        virtual ~Array();
        size_t get_size();
        Figure* operator[](size_t pos);
        void place_figure(size_t pos, Figure* added);
        void remove_figure(size_t input);
        void resize(size_t input);
        double find_total_square() const;
};