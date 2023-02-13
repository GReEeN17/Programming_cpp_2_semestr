#ifndef CLION_PROGRAMMING_PASS_BY_REFERENCE_H
#define CLION_PROGRAMMING_PASS_BY_REFERENCE_H

void swap_values_ref(int &fir_var, int &sec_var);

void swap_values_pntr(int *fir_var, int *sec_var);

void test_swap_values(int &exp_fir_var, int &exp_sec_var, int &fact_fir_var, int &fact_sec_var);

void disc_func_part_ref(float &var);

void disc_func_part_pntr(float *var);

void test_disc_func_part(float &exp_var, float &fact_var);

#pragma pack(1)

struct complex_digit {
    float real_part;
    float im_part;
};

#pragma pack()

void mltp_comp_numb_ref(complex_digit &cd, float &number);

void mltp_comp_numb_pntr(complex_digit *cd, const float *number);

void test_mltp_comp_numb(complex_digit &exp_cd, complex_digit &fact_cd);

#pragma pack(1)

struct dot{
    float x;
    float y;
};

struct circle {
    dot center;
    float radius;
};

#pragma pack()

void move_circle_ref(circle &crc, float &vector_x, float &vector_y);

void move_circle_pntr(circle *crc, const float *vector_x, const float *vector_y);

void test_move_circle(circle &exp_crc, circle &fact_crc);

void lab_1();

#endif //CLION_PROGRAMMING_PASS_BY_REFERENCE_H
