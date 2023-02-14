#ifndef CLION_PROGRAMMING_MENU_2_LAB_C
#define CLION_PROGRAMMING_MENU_2_LAB_C
#include <iostream>
#include "menu_2_lab.h"
#include "string_parser.h"

Menu::Menu(std::string &parsing_str, StrParser &strParser) {
    this->parsing_str = parsing_str;
    this->str_parser = &strParser;
}

void Menu::menu_split_str() {
    this->str_parser->split_str();
    this->str_parser->indicate_if_parsed();
    std::cout << "Анализ строки произведён" << "\n";
}

void Menu::menu_add_separator() {
    std::string symb("");
    while (symb.empty()) {
        std::cout << "Введите сепаратор, который вы хотели бв добавить" << "\n";
        std::cin >> symb;
    }
    this->str_parser->add_separator(symb);
    std::cout << "Сепаратор успешно добавлен" << "\n";
}

void Menu::menu_delete_all_separators() {
    this->str_parser->delete_all_separators();
    std::cout << "Все сепараторы удалены" << "\n";
}

void Menu::menu_get_next_str() {
    std::string next_str("");
    while (next_str.empty()) {
        std::cout << "Введите строку, котоорую вы хотели бы проанализировать" << "\n";
        std::cin >> next_str;
    }
    this->str_parser->get_next_str(next_str);
    std::cout << "Строка для анализа добавлена" << "\n";
}

void Menu::menu_main() {
    std::string s;
    while(getline(std::cin, s)) {
        std::cout << "Введите команду" << "\n";
        if (s == "/split") {
            menu_split_str();
        } else if (s == "/add") {
            menu_add_separator();
        } else if (s == "/delete") {
            menu_delete_all_separators();
        } else if (s == "/next") {
            menu_get_next_str();
        }
    }
}


#endif //CLION_PROGRAMMING_MENU_2_LAB_C