#pragma once

#include "figure.hpp"
#include "shared_methods.hpp"

template <typename T>
class Triangle : public Figure
{
public:
    const size_t point_num{3};
    std::vector<std::pair<T,T>> points;
    
    Triangle() = default;
    Triangle(std::vector<std::pair<T,T>>& input) : points(input) {}
    Triangle(const Triangle<T>& other) : points(other.points) {}
    ~Triangle() = default;

    virtual operator double() const;
    bool operator==(Triangle<T>& other) const;
    Triangle<T>& operator=(const Triangle<T>& other);
    Triangle<T>& operator=(Triangle<T>&& rvalue) noexcept;
};

template <typename T>
bool Triangle<T>::operator==(Triangle<T>& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

template <typename T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& other) {
    points = other.points;
    return *this;
}

template <typename T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& other) noexcept {
    points = std::move(other.points);
    return *this;
}

template <typename T>
Triangle<T>::operator double() const {
    return square<Triangle<T>>(*this);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& figure)
{
    output(os,figure);	
	return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Triangle<T>& figure)
{
    input(is, figure);
	return is;
}