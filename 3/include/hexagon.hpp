#pragma once

#include "figure.hpp"

class Hexagon : public Figure
{
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& p);
    friend std::istream& operator>>(std::istream& is, Hexagon& p);
private:
    size_t point_num{6};
    std::vector<std::pair<double,double>> points;
public:
    Hexagon() = default;
    Hexagon(const Hexagon& other);
    Hexagon(std::vector<std::pair<double,double>>& input);
    ~Hexagon() = default;

    std::vector<std::pair<double,double>> get_points() const;
    
    virtual std::pair<double,double> find_center() const;

    virtual operator double() const;
    bool operator==(Hexagon& other) const;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& rvalue) noexcept;
};

inline std::ostream& operator<<(std::ostream& os, const Hexagon& p)
{
    os << "Координаты:\n";
    for (auto member : p.get_points())
        os << "[" << member.first << ", " << member.second << "]\n";	
	return os;
}

inline std::istream& operator>>(std::istream& is, Hexagon& p)
{
    std::cout << "Введите " << p.point_num << " координат для фигуры" << std::endl;
    std::cout << "в порядке [x,y], с разделением через пробел:" << std::endl;
    std::vector<std::pair<double,double>> input(p.point_num);
	for (size_t i{}; i < p.point_num; ++i) {
        is >> input[i].first >> input[i].second;
    }
	p = Hexagon(input);
	return is;
}
