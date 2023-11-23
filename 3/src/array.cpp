#include "array.hpp"

Array::Array() {
    size = 5;
    figures = new Figure*[size];
    for (size_t i{}; i<size; ++i) {
        figures[i] = nullptr;
    }
}

Array::Array(size_t input) {
    size = input;
    figures = new Figure*[size];
    for (size_t i{}; i<size; ++i) {
        figures[i] = nullptr;
    }
}

Array::~Array() {
    for (size_t i{}; i<size; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

size_t Array::get_size() {
    return size;
}

Figure* Array::operator[](size_t pos) {
    if (pos >= size) throw std::out_of_range("Индекс выходит за границы");
    return figures[pos]; 
}

void Array::place_figure(size_t pos, Figure* added) {
    if (pos >= size) throw std::out_of_range("Индекс выходит за границы");
    delete figures[pos];
    figures[pos] = added;
}

void Array::remove_figure(size_t pos) {
    if (pos >= size) throw std::out_of_range("Индекс выходит за границы");
    delete figures[pos];
    figures[pos] = nullptr;
}

void Array::resize(size_t new_size) {
    Figure** new_figures = new Figure*[new_size];
    size_t min_size;
    size_t max_size;
    bool fact = false;
    if (new_size > size) fact = true;
    for (size_t i{}; i < std::min(size, new_size); ++i) {
        new_figures[i] = figures[i];
        figures[i] = nullptr;
    }
    if (fact) {
        for (size_t i{size}; i < new_size; ++i) {
            new_figures[i] = nullptr;
        }
    } else {
        for (size_t i{new_size}; i<size; ++i) {
            delete figures[i];
        }
    }
    delete[] figures;
    figures = new_figures;
    size = new_size;
}

double Array::find_total_square() const {
    double sum = 0;
    for (size_t i{}; i<size; ++i) {
        if (figures[i] != nullptr) {
            sum += double(*figures[i]);
        }
    }
    return sum;
}