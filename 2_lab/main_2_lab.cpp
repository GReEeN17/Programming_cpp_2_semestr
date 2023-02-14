#ifndef CLION_PROGRAMMING_MAIN_2_LAB_C
#define CLION_PROGRAMMING_MAIN_2_LAB_C
#include <iostream>
#include "menu_2_lab.h"
#include "string_parser.h"

inline void main_2_lab() {
    std::string parsing_str;
    while (parsing_str.empty()) {
        std::cout << "Введите строку, котоорую вы хотели бы проанализировать" << "\n";
        std::cin >> parsing_str;
    }
    StrParser str_parser(parsing_str);
    Menu menu(parsing_str, str_parser);
    menu.menu_main();
}

#endif //CLION_PROGRAMMING_MAIN_2_LAB_C