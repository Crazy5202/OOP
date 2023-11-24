#pragma once

#include "figure.hpp"

template <class C>
std::istream& input(std::istream& is, C& figure)
{
  std::cout << "Введите " << figure.point_num << " координат для фигуры в порядке [x,y], с разделением через пробел." << std::endl;
  std::cout << "Первые две координаты должны быть для соседних вершин:" << std::endl;
  while (figure.points.size()!=figure.point_num) {
    figure.points.push_back({0,0});
  }
  for (size_t i{}; i < figure.point_num; ++i) {
      is >> figure.points[i].first >> figure.points[i].second;
  }
  return is;
}

template <class C>
std::ostream& output(std::ostream& os, C& figure) {
    std::cout << "Координаты:\n";
    for (auto member : figure.points)
        os << "[" << member.first << ", " << member.second << "]\n";	
	return os;
}

template <class C>
std::pair<double,double> find_center(C& figure) {
    std::pair<double,double> center{0,0};
    size_t point_num = figure.point_num;
    for (auto point : figure.points) {
        center.first += point.first;
        center.second += point.second;
    }
    center.first /= point_num;
    center.second /= point_num;
    return center;
}

template <class C>
double square(const C& figure) {
    double side = std::sqrt(std::pow(figure.points[0].first - figure.points[1].first, 2) + std::pow(figure.points[0].second - figure.points[1].second, 2));
    const double pi = std::acos(-1);
    double angle;
    if (figure.point_num == 3) {
        angle = pi/3;
    } else {
        angle = 2*pi/figure.point_num;
    }
    double h = side*0.5*std::tan(angle);
    double result = h*side*0.5;
    if (figure.point_num == 3) {
        return result;
    } else {
        return result*figure.point_num;
    }
}