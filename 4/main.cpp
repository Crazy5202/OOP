#include "triangle.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "array.hpp"
#include "shared_methods.hpp"

int main() {
    Array<Hexagon<double>> arr(3);
    std::cout << "Вы используете массив размера " << arr.get_size() << " с " << arr[0].point_num << "-угольниками" << std::endl;
    size_t init_size, var, var1, input = 0;
    while(input != 6) {
        std::cout << "Вы находитесь в меню работы с массивом фигур! Ваши опции:" << std::endl;
        std::cout << "1 - ввести фигуру; 2 - удалить фигуру; 3 - просмотреть координаты и центр фигуры;" << std::endl;
        std::cout << "4 - площадь фигуры; 5 - общая площадь фигур; 6 - выйти из программы." << std::endl;
        std::cin >> input;
        switch(input) {
            case 1:
                std::cout << "Введите позицию для вставки:" << std::endl;
                std::cin >> var;
                if (var >= arr.get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                std::cin >> arr[var];
                std::cout << "Фигура добавлена!" << std::endl;
                break;
            case 2:
                std::cout << "Введите позицию для удаления:" << std::endl;
                std::cin >> var;
                if (var >= arr.get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                arr[var].points.clear();
                std::cout << "Фигура удалена!" << std::endl;
                break;
            case 3:
                std::cout << "Введите позицию для просмотра:" << std::endl;
                std::cin >> var;
                if (var >= arr.get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                if (arr[var].points.size() == 0) {
                    std::cout << "Позиция пуста!" << std:: endl;
                    break;
                } else {
                    std::cout << arr[var];
                    std::pair<double, double> center = find_center(arr[var]);
                    std::cout << "Координаты центра: " << center.first << ' ' << center.second << std::endl;
                }
                break;
            case 4:
                std::cout << "Введите позицию для просмотра:" << std::endl;
                std::cin >> var;
                if (var >= arr.get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                if (arr[var].points.size() == 0) {
                    std::cout << "Позиция пуста!" << std:: endl;
                    break;
                } else {
                    std::cout << "Площадь: " << double(arr[var]) << std::endl;
                }
                break;
            case 5:
                std::cout << "Общая площадь: " << arr.find_total_square() << std::endl;
                break;
            case 6:
                std::cout << "Работа завершена!" << std::endl;
                break;
        }
    }
}