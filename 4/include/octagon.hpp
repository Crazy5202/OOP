#pragma once

#include "figure.hpp"
#include "shared_methods.hpp"

template <typename T>
class Octagon : public Figure
{
public:
    const size_t point_num{8};
    std::vector<std::pair<T,T>> points;
    
    Octagon() = default;
    Octagon(std::vector<std::pair<T,T>>& input) : points(input) {}
    Octagon(const Octagon<T>& other) : points(other.points) {}
    ~Octagon() = default;

    virtual operator double() const;
    bool operator==(Octagon<T>& other) const;
    Octagon<T>& operator=(const Octagon<T>& other);
    Octagon<T>& operator=(Octagon<T>&& rvalue) noexcept;
};

template <typename T>
bool Octagon<T>::operator==(Octagon<T>& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

template <typename T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& other) {
    points = other.points;
    return *this;
}

template <typename T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& other) noexcept {
    points = std::move(other.points);
    return *this;
}

template <typename T>
Octagon<T>::operator double() const {
    return square<Octagon<T>>(*this);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& figure)
{
    output(os,figure);	
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Octagon<T>& figure)
{
    input(is, figure);
	return is;
}