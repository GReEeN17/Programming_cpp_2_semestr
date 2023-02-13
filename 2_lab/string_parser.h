#ifndef CLION_PROGRAMMING_STRING_PARSER_H
#define CLION_PROGRAMMING_STRING_PARSER_H
#include <iostream>
#include <vector>

class StrParser {
private:
    std::string parsing_str;
    std::vector<std::string> separators;
    std::vector<std::string> parsed_str;
    bool is_parsed;
    int len_separators;
public:
    StrParser (std::string parsing_str);

    void set_var(std::string parsing_str);

    void split_str();

    void add_separator (std::string separator);

    void delete_all_separators();

    void get_next_str(std::string next_string);

    void indicate_if_parsed();

    void lab_2();
};

#endif //CLION_PROGRAMMING_STRING_PARSER_H
