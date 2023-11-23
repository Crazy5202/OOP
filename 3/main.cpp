#include "triangle.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "array.hpp"

void print_figure(Figure* smt) {
    if (typeid(smt) == typeid(Triangle*)) {
        std::cout << *(Triangle*)(smt);
    } else if (typeid(smt) == typeid(Hexagon*)) {
        std::cout << *(Hexagon*)(smt);
    } else {
        std::cout << *(Octagon*)(smt);
    }
}

int main() {
    std::cout << "Введите начальный размер массива фигур:" << std::endl;
    size_t init_size, var, var1, input = 0;
    std::cin >> init_size;
    Array* arr = new Array(init_size);
    Figure* fig;
    Triangle* figt;
    Hexagon* figh;
    Octagon* figo;
    while(input != 8) {
        std::cout << "Вы находитесь в меню работы с массивом фигур! Ваши опции:" << std::endl;
        std::cout << "1 - ввести фигуру; 2 - удалить фигуру; 3 - просмотреть координаты и центр фигуры" << std::endl;
        std::cout << "4 - площадь фигуры; 5 - общая площадь фигур" << std::endl;
        std::cout << "6 - текущий размер массива; 7 - изменить размер массива; 8 - выйти из программы" << std::endl;
        std::cin >> input;
        switch(input) {
            case 1:
                std::cout << "Введите позицию для вставки:" << std::endl;
                std::cin >> var;
                if (var >= arr->get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                std::cout << "Введите число вершин фигуры (3, 6 или 8):" << std::endl;
                std::cin >> var1;
                if (var1 != 3 and var1 != 6 and var1 != 8) {
                    std::cout << "Неверное число вершин! Попробуйте ещё!" << std::endl;
                    break;
                }
                switch(var1) {
                    case 3:
                        figt = new Triangle();
                        std::cin >> *figt;
                        arr->place_figure(var, figt);
                        break;
                    case 6:
                        figh = new Hexagon();
                        std::cin >> *figh;
                        arr->place_figure(var, figh);
                        break;
                    case 8:
                        figo = new Octagon();
                        std::cin >> *figo;
                        arr->place_figure(var, figo);
                        break;
                }
                std::cout << "Фигура добавлена!" << std::endl;
                break;
            case 2:
                std::cout << "Введите позицию для удаления:" << std::endl;
                std::cin >> var;
                arr->remove_figure(var);
                std::cout << "Фигура удалена!" << std::endl;
                break;
            case 3:
                std::cout << "Введите позицию для просмотра:" << std::endl;
                std::cin >> var;
                if (var >= arr->get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                fig = (*arr)[var];
                if (fig == nullptr) {
                    std::cout << "Позиция пуста!" << std:: endl;
                    break;
                } else {
                    print_figure(fig);
                    std::pair<double, double> center = fig->find_center();
                    std::cout << "Координаты центра: " << center.first << ' ' << center.second << std::endl;
                }
                break;
            case 4:
                std::cout << "Введите позицию для просмотра:" << std::endl;
                std::cin >> var;
                if (var >= arr->get_size()) {
                    std::cout << "Выход за границы массива!" << std::endl;
                    break;
                }
                fig = (*arr)[var];
                if (fig == nullptr) {
                    std::cout << "Позиция пуста!" << std:: endl;
                    break;
                } else {
                    std::cout << "Площадь: " << double(*fig) << std::endl;
                }
                break;
            case 5:
                std::cout << "Общая площадь: " << arr->find_total_square() << std::endl;
                break;
            case 6:
                std::cout << "Размер массива: " << arr->get_size() << std::endl;
                break;
            case 7:
                std::cout << "Введите новый размер массива:" << std::endl;
                std::cin >> var;
                arr->resize(var);
                std::cout << "Изменение размера завершено!" << std::endl;
                break;
            case 8:
                std::cout << "Работа завершена!" << std::endl;
                break;
        }
    }

}