#pragma once

#include "figure.hpp"
#include "shared_methods.hpp"

template <class C>
class Array 
{
    private:
        std::shared_ptr<C[]> figures;
        size_t size;
    public:
        Array() : size(0), figures(nullptr) {}
        Array(size_t input);
        size_t get_size() {return size;}
        virtual ~Array() = default;
        C& operator[](size_t pos);
        double find_total_square() const;
};

template <class C>
Array<C>::Array(size_t input) : size(input) {
    figures.reset(new C[input]);
    for (size_t i{}; i<input; ++i) {
        figures[i] = C();
    }
}

template <class C>
C& Array<C>::operator[](size_t pos) {
    if (pos >= size) throw std::out_of_range("Индекс выходит за границы");
    return figures[pos];
}

template <class C>
double Array<C>::find_total_square() const {
    double sum = 0;
    for (size_t i{}; i<size; ++i) {
        if (figures[i].points.size()!=0) {
            sum += double(figures[i]);
        }
    }
    return sum;
}