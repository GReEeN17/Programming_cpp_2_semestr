#ifndef CLION_PROGRAMMING_STRING_PARSER_C
#define CLION_PROGRAMMING_STRING_PARSER_C
#include <iostream>
#include <vector>
#include "string_parser.h"

StrParser::StrParser(std::string &parsing_str) {
    this->parsing_str = parsing_str;
}

void StrParser::split_str() {
    if (this->is_parsed) return;
    if (this->parsing_str.empty()) {
        std::cout << "Прежде чем начать анализировать строку, её надо ввести" << "\n";
        return;
    }
    int i = 0;
    std::string gap_str;
    std::string symb;
    while (this->parsing_str[i] != '\0') {
        symb = this->parsing_str[i];
        bool is_in_sep = false;
        for (int j = 0; j < this->len_separators; j++) {
            if (symb == this->separators[j]) {
                is_in_sep = true;
                if (!gap_str.empty()) {
                    this->parsed_str.push_back(gap_str);
                    this->len_parsed_str++;
                    gap_str = "";
                }
                break;
            }
        }
        if (!is_in_sep)
            gap_str += this->parsing_str[i];
        i++;
    }
    if (!gap_str.empty()) {
        this->parsed_str.push_back(gap_str);
        this->len_parsed_str++;
    }
    if (this->parsing_str.length() == i) is_parsed = true;
}

void StrParser::add_separator(std::string &separator) {
    this->separators.push_back(separator);
    this->len_separators++;
    this->is_parsed = false;
    this->len_parsed_str = 0;
    this->parsed_str.clear();
}

void StrParser::delete_all_separators() {
    this->separators.clear();
    this->len_separators = 0;
}

void StrParser::get_next_str(std::string &next_string) {
    this->parsing_str = next_string;
    this->len_parsed_str = 0;
    this->parsed_str.clear();
}

void StrParser::indicate_if_parsed() {
    if (this->is_parsed) {
        std::cout << "Строка проанализирована" << "\n";
        for (int i = 0; i < this->len_parsed_str; i++) {
            std::cout << this->parsed_str[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Строка не была проанализирована или была обнаружена ошибка" << "\n";
    }
}

#endif //CLION_PROGRAMMING_STRING_PARSER_C
