#include "triangle.hpp"

std::vector<std::pair<double,double>> Triangle::get_points() const {
    return points;
}

Triangle::Triangle(std::vector<std::pair<double,double>>& input) {
    if (input.size() != point_num) {
        throw std::invalid_argument("Число точек не соответствует требованиям класса");
    }
    points = input;
}

Triangle::Triangle(const Triangle& other) {
    points = other.get_points();
}

std::pair<double,double> Triangle::find_center() const {
    std::pair<double,double> center;
    for (auto member : points) {
        center.first += member.first/point_num;
        center.second += member.second/point_num;
    }
    return center;
}

Triangle::operator double() const {
    double var1 = (points[1].first-points[0].first)*(points[2].second-points[0].second);
    double var2 = (points[2].first-points[0].first)*(points[1].second-points[0].second);
    return 0.5*abs(var1-var2);
}

bool Triangle::operator==(Triangle& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

Triangle& Triangle::operator=(const Triangle& other) {
    points = other.get_points();
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    points = std::move(other.points);
    return *this;
}