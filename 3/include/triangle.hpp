#pragma once

#include "figure.hpp"

class Triangle : public Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Triangle& p);
    friend std::istream& operator>>(std::istream& is, Triangle& p);
private:
    size_t point_num{3};
    std::vector<std::pair<double,double>> points;
public:
    Triangle() = default;
    Triangle(const Triangle& other);
    Triangle(std::vector<std::pair<double,double>>& input);
    ~Triangle() = default;

    std::vector<std::pair<double,double>> get_points() const;
    
    virtual std::pair<double,double> find_center() const;

    virtual operator double() const;
    bool operator==(Triangle& other) const;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& rvalue) noexcept;
};

inline std::ostream& operator<<(std::ostream& os, const Triangle& p)
{
    os << "Координаты:\n";
    for (auto member : p.get_points())
        os << "[" << member.first << ", " << member.second << "]\n";	
	return os;
}

inline std::istream& operator>>(std::istream& is, Triangle& p)
{
    std::cout << "Введите " << p.point_num << " координат для фигуры" << std::endl;
    std::cout << "в порядке [x,y], с разделением через пробел:" << std::endl;
    std::vector<std::pair<double,double>> input(p.point_num);
	for (size_t i{}; i < p.point_num; ++i) {
        is >> input[i].first >> input[i].second;
    }
	p = Triangle(input);
	return is;
}