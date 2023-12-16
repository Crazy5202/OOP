#include <iostream>
#include "observer.hpp"
#include "fighters.hpp"

int main() {
    ConsoleObserver cobs;
    std::ofstream output("log.txt");
    FileObserver fobs(output);
    Fighters fighters = Fighters();
    fighters.attach(&cobs);
    fighters.attach(&fobs);
    int dist, input = 0;
    std::string filename;
    while(input != 7) {
        std::cout << "Вы находитесь в меню арены! Дистанция боя - " << fighters.get_distance() << ". Ваши опции:" << std::endl;
        std::cout << "1 - ввести бойцов из файла; 2 - записать бойцов в файл; 3 - ввести бойца вручную;" << std::endl;
        std::cout << "4 - напечатать бойцов; 5 - изменить дистанцию боя; 6 - провести бой; 7 - выйти из программы." << std::endl;
        std::cin >> input;
        switch(input) {
            case 1:
                std::cout << "Введите название файла:" << std::endl;
                std::cin >> filename;
                fighters.load(filename);
                break;
            case 2:
                std::cout << "Введите название файла:" << std::endl;
                std::cin >> filename;
                fighters.save(filename);
                break;
            case 3:
                std::cout << "Введите бойца в формате: <Тип> <Имя> <X> <Y>. ";
                std::cout << "Типы: Orc, Slaver, Druid" << std:: endl;
                fighters.add();
                break;
            case 4:
                fighters.show();
                break;
            case 5:
                std::cout << "Введите новую дистанцию боя:" << std::endl;
                std::cin >> dist;
                fighters.set_distance(dist);
                break;
            case 6:
                fighters.fight();
                std::cout << "Бой проведён!" << std::endl;
                break;
            case 7:
                std::cout << "Совершён выход!" <<std::endl;
                break;
        }
    }
}