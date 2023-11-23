#pragma once

#include "figure.hpp"

class Octagon : public Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Octagon& p);
    friend std::istream& operator>>(std::istream& is, Octagon& p);
private:
    size_t point_num{8};
    std::vector<std::pair<double,double>> points;
public:
    Octagon() = default;
    Octagon(const Octagon& other);
    Octagon(std::vector<std::pair<double,double>>& input);
    ~Octagon() = default;

    std::vector<std::pair<double,double>> get_points() const;
    
    virtual std::pair<double,double> find_center() const;

    virtual operator double() const;
    bool operator==(Octagon& other) const;
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& rvalue) noexcept;
};

inline std::ostream& operator<<(std::ostream& os, const Octagon& p)
{
    os << "Координаты:\n";
    for (auto member : p.get_points())
        os << "[" << member.first << ", " << member.second << "]\n";	
	return os;
}

inline std::istream& operator>>(std::istream& is, Octagon& p)
{
    std::cout << "Введите " << p.point_num << " координат для фигуры" << std::endl;
    std::cout << "в порядке [x,y], с разделением через пробел:" << std::endl;
    std::vector<std::pair<double,double>> input(p.point_num);
	for (size_t i{}; i < p.point_num; ++i) {
        is >> input[i].first >> input[i].second;
    }
	p = Octagon(input);
	return is;
}
