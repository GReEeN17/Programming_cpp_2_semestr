#ifndef CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#define CLION_PROGRAMMING_PASS_BY_REFERENCE_C
#include "pass_by_reference.h"

void swap_values_ref(int &fir_var, int &sec_var) {
    int gap = fir_var;
    fir_var = sec_var;
    sec_var = gap;
}

void swap_values_pntr(int *fir_var, int *sec_var) {
    int* gap = fir_var;
    fir_var = sec_var;
    sec_var = gap;
}

#endif //CLION_PROGRAMMING_PASS_BY_REFERENCE_C
