#ifndef CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#define CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#include "pass_by_reference.h"
#include <iostream>
#include <cmath>

void swap_values_ref(int &fir_var, int &sec_var) {
    int gap = fir_var;
    fir_var = sec_var;
    sec_var = gap;
}

void swap_values_pntr(int *fir_var, int *sec_var) {
    /*int temp = *fir_var;
    *fir_var = *sec_var;
    *sec_var = temp;*/
    int *gap = fir_var;
    fir_var = sec_var;
    sec_var = gap;
}

void test_swap_values(int &exp_fir_var, int &exp_sec_var, int &fact_fir_var, int &fact_sec_var) {
    if (exp_fir_var == fact_fir_var && exp_sec_var == fact_sec_var) {
        std::cout << "Переменные поменялись местами!!!" << "\n";
        std::cout << exp_fir_var << " = " << fact_fir_var << ", " << exp_sec_var << " = " << fact_sec_var << "\n";
    } else {
        std::cout << "Переменные не поменялись местами;(" << "\n";
        std::cout << exp_fir_var << " != " << fact_fir_var << ", " << exp_sec_var << " != " << fact_sec_var << "\n";
    }
}

void disc_func_part_ref(float &var) {
    var = floor(var);
}

void disc_func_part_pntr(float *var) {
    *var = floor(*var);
}

void test_disc_func_part(float &exp_var, float &fact_var) {
    if (exp_var == fact_var) {
        std::cout << "Переменные совпадают!!!" << "\n";
        std::cout << exp_var << " = " << fact_var << "\n";
    } else {
        std::cout << "Переменные не совпадают;(" << "\n";
        std::cout << exp_var << " != " << fact_var << "\n";
    }
}

void mltp_comp_numb_ref(complex_digit &cd, float &number) {
    cd.real_part *= number;
    cd.im_part *= number;
}

void mltp_comp_numb_pntr(complex_digit *cd, const float *number) {
    cd->real_part *= *number;
    cd->im_part *= *number;
}

void test_mltp_comp_numb(complex_digit &exp_cd, complex_digit &fact_cd) {
    if (exp_cd.real_part == fact_cd.real_part && exp_cd.im_part == fact_cd.im_part) {
        std::cout << "Структуры совпадают!!!" << "\n";
        std::cout << exp_cd.real_part << " = " << fact_cd.real_part << ", " << exp_cd.im_part << " = " << fact_cd.im_part << "\n";
    } else {
        std::cout << "Структуры не совпадают;(" << "\n";
        std::cout << exp_cd.real_part << " != " << fact_cd.real_part << ", " << exp_cd.im_part << " != " << fact_cd.im_part << "\n";
    }
}

void move_circle_ref(circle &crc, float &vector_x, float &vector_y) {
    crc.center.x += vector_x;
    crc.center.y += vector_y;
}

void move_circle_pntr(circle *crc, const float *vector_x, const float *vector_y) {
    crc->center.x += *vector_x;
    crc->center.y += *vector_y;
}

void test_move_circle(circle &exp_crc, circle &fact_crc) {
    if (exp_crc.center.x == fact_crc.center.x && exp_crc.center.y == fact_crc.center.y) {
        std::cout << "Структуры совпадают!!!" << "\n";
        std::cout << exp_crc.center.x << " = " << fact_crc.center.x << ", " << exp_crc.center.y << " = " << fact_crc.center.y << "\n";
    } else {
        std::cout << "Структуры не совпадают;(" << "\n";
        std::cout << exp_crc.center.x << " != " << fact_crc.center.x << ", " << exp_crc.center.y << " != " << fact_crc.center.y << "\n";
    }
}

void lab_1() {
    //-------------Задание 1.1--------------
    int a, b;
    std::cin >> a >> b;
    int cp_a = a, cp_b = b;
    swap_values_ref(a, b);
    test_swap_values(cp_b, cp_a, a, b);
    int *pntr_a = &a, *pntr_b = &b;
    swap_values_pntr(pntr_a, pntr_b);
    test_swap_values(cp_a, cp_b, a, b);
    //-------------Задание 1.2--------------
    float dfp;
    std::cin >> dfp;
    float dfp_cp_fir = floor(dfp);
    disc_func_part_ref(dfp);
    test_disc_func_part(dfp_cp_fir, dfp);
    std::cin >> dfp;
    float *pntr_dfp = &dfp;
    float dfp_cp_sec = floor(dfp);
    disc_func_part_pntr(pntr_dfp);
    test_disc_func_part(dfp_cp_sec, dfp);
    //-------------Задание 1.3--------------
    complex_digit cd{};
    std::cin >> cd.real_part >> cd.im_part;
    complex_digit cpy_cd = cd;
    float number;
    std::cin >> number;
    mltp_comp_numb_ref(cd, number);
    cpy_cd.real_part *= number; cpy_cd.im_part *= number;
    test_mltp_comp_numb(cpy_cd, cd);
    complex_digit *pntr_cd = &cd; float *pntr_number = &number;
    mltp_comp_numb_pntr(pntr_cd, pntr_number);
    cpy_cd.real_part *= number; cpy_cd.im_part *= number;
    test_mltp_comp_numb(cpy_cd, cd);
    //-------------Задание 1.4--------------
    dot dt{};
    circle crc{};
    std::cin >> dt.x >> dt.y;
    crc.center = dt;
    std::cin >> crc.radius;
    circle cpy_crc = crc;
    float vector_x, vector_y;
    std::cin >> vector_x >> vector_y;
    move_circle_ref(crc, vector_x, vector_y);
    cpy_crc.center.x += vector_x; cpy_crc.center.y += vector_y;
    test_move_circle(cpy_crc, crc);
    circle *pntr_crc = &crc; float *pntr_vec_x = &vector_x; float *pntr_vec_y = &vector_y;
    move_circle_pntr(pntr_crc, pntr_vec_x, pntr_vec_y);
    cpy_crc.center.x += vector_x; cpy_crc.center.y += vector_y;
    test_move_circle(cpy_crc, crc);
};

#endif //CLION_PROGRAMMING_PASS_BY_REFERENCE_C
