#ifndef CLION_PROGRAMMING_PASS_BY_REFERENCE_H
#define CLION_PROGRAMMING_PASS_BY_REFERENCE_H

void swap_values_ref(int &fir_var, int &sec_var);

void swap_values_pntr(int *fir_var, int *sec_var);

void test_swap_values(int &exp_fir_var, int &exp_sec_var, int &fact_fir_var, int &fact_sec_var);

void disc_func_part_ref(float &var);

void disc_func_part_pntr(float *var);

void test_disc_func_part(float &exp_var, float &fact_var);

void lab_1();

#endif //CLION_PROGRAMMING_PASS_BY_REFERENCE_H
