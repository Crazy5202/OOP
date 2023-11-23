#include "octagon.hpp"

std::vector<std::pair<double,double>> Octagon::get_points() const {
    return points;
}

Octagon::Octagon(std::vector<std::pair<double,double>>& input) {
    if (input.size() != point_num) {
        throw std::invalid_argument("Число точек не соответствует требованиям класса");
    }
    points = input;
}

Octagon::Octagon(const Octagon& other) {
    points = other.get_points();
}

std::pair<double,double> Octagon::find_center() const {
    std::pair<double,double> center;
    for (auto member : points) {
        center.first += member.first/point_num;
        center.second += member.second/point_num;
    }
    return center;
}

Octagon::operator double() const {
    std::pair<double, double> center = find_center();
    double side = sqrt(pow(center.first - points[0].first, 2) + pow(center.second - points[0].second, 2));
    return (2*sqrt(2)*std::pow(side, 2));
}

bool Octagon::operator==(Octagon& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

Octagon& Octagon::operator=(const Octagon& other) {
    points = other.points;
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    points = std::move(other.points);
    return *this;
}