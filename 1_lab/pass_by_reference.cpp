#ifndef CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#define CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#include "pass_by_reference.h"
#include <iostream>

void swap_values_ref(int &fir_var, int &sec_var) {
    int gap = fir_var;
    fir_var = sec_var;
    sec_var = gap;
}

void swap_values_pntr(int *fir_var, int *sec_var) {
    int temp = *fir_var;
    *fir_var = *sec_var;
    *sec_var = temp;
}

void test_swap_values(int exp_fir_var, int exp_sec_var, int fact_fir_var, int fact_sec_var) {
    if (exp_fir_var == fact_fir_var && exp_sec_var == fact_sec_var) {
        std::cout << "Переменные поменялись местами!!!" << "\n";
        std::cout << exp_fir_var << " = " << fact_fir_var << ", " << exp_sec_var << " = " << fact_sec_var << "\n";
    } else {
        std::cout << "Переменные не поменялись местами;(" << "\n";
        std::cout << exp_fir_var << " != " << fact_fir_var << ", " << exp_sec_var << " != " << fact_sec_var << "\n";
    }
}

void lab_1() {
    int a, b;
    std::cin >> a >> b;
    int cp_a = a, cp_b = b;
    swap_values_ref(a, b);
    test_swap_values(cp_b, cp_a, a, b);
    int *pntr_a = &a, *pntr_b = &b;
    swap_values_pntr(pntr_a, pntr_b);
    test_swap_values(cp_a, cp_b, a, b);
};

#endif //CLION_PROGRAMMING_PASS_BY_REFERENCE_C
