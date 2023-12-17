#include <iostream>
#include "observer.hpp"
#include "fighters.hpp"

int main() {
    std::shared_mutex data_mtx, io_mtx;
    ConsoleObserver cobs(&io_mtx);
    std::ofstream output("log.txt");
    FileObserver fobs(output);
    Fighters fighters = Fighters(&data_mtx, &io_mtx);
    fighters.attach(&cobs);
    fighters.attach(&fobs);
    int dist, input = 0;
    std::string filename;
    while(input != 6) {
        std::cout << "Вы находитесь в меню арены 30х30! Ваши опции:" << std::endl;
        std::cout << "1 - ввести бойцов из файла; 2 - записать бойцов в файл; 3 - ввести бойца вручную;" << std::endl;
        std::cout << "4 - напечатать бойцов; 5 - провести бой; 6 - выйти из программы." << std::endl;
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
                fighters.fight();
                std::cout << "Бой проведён!" << std::endl;
                break;
            case 6:
                std::cout << "Совершён выход!" <<std::endl;
                break;
        }
    }
}