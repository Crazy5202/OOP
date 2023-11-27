#pragma once

#include "figure.hpp"
#include "shared_methods.hpp"

template <typename T>
class Hexagon : public Figure
{
public:
    const size_t point_num{6};
    std::vector<std::pair<T,T>> points;
    
    Hexagon() = default;
    Hexagon(std::vector<std::pair<T,T>>& input) : points(input) {}
    Hexagon(const Hexagon<T>& other) : points(other.points) {}
    ~Hexagon() = default;

    virtual operator double() const;
    bool operator==(Hexagon<T>& other) const;
    Hexagon<T>& operator=(const Hexagon<T>& other);
    Hexagon<T>& operator=(Hexagon<T>&& rvalue) noexcept;
};

template <typename T>
bool Hexagon<T>::operator==(Hexagon<T>& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other) {
    points = other.points;
    return *this;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other) noexcept {
    points = std::move(other.points);
    return *this;
}

template <typename T>
Hexagon<T>::operator double() const {
    return square<Hexagon<T>>(*this);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& figure)
{
    output(os,figure);	
	return os;
}

template <typename T>
inline std::istream& operator>>(std::istream& is, Hexagon<T>& figure)
{
    input(is, figure);
	return is;
}