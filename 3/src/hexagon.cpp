#include "hexagon.hpp"

std::vector<std::pair<double,double>> Hexagon::get_points() const {
    return points;
}

Hexagon::Hexagon(std::vector<std::pair<double,double>>& input) {
    if (input.size() != point_num) {
        throw std::invalid_argument("Число точек не соответствует требованиям класса");
    }
    points = input;
}

Hexagon::Hexagon(const Hexagon& other) {
    points = other.get_points();
}

std::pair<double,double> Hexagon::find_center() const {
    std::pair<double,double> center;
    for (auto member : points) {
        center.first += member.first/point_num;
        center.second += member.second/point_num;
    }
    return center;
}

bool compare(std::pair<double, double> p1, std::pair<double, double> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

Hexagon::operator double() const {
    const auto cord_min = min_element(points.begin(), points.end(), compare);
    const auto cord_max = max_element(points.begin(), points.end(), compare);
    double side = sqrt(pow(cord_max->first - cord_min->first, 2) + pow(cord_max->second - cord_min->second, 2))/2;
    return (3*sqrt(3)/2*std::pow(side, 2));
}

bool Hexagon::operator==(Hexagon& other) const {
    for (size_t i{}; i < point_num; ++i) {
        if (points[i] != other.points[i]) return false;
    }
    return true;
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    points = other.points;
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    points = std::move(other.points);
    return *this;
}