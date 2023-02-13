#ifndef CLION_PROGRAMMING_MENU_2_LAB_H
#define CLION_PROGRAMMING_MENU_2_LAB_H
#include <iostream>

class Menu {
private:
    std::string parsing_str = "";
public:
    Menu(std::string parsing_str);

    void menu_split_str();

    void menu_add_separator();

    void menu_delete_all_separators();

    void menu_get_next_str();

    void menu_main();
};

#endif //CLION_PROGRAMMING_MENU_2_LAB_H
