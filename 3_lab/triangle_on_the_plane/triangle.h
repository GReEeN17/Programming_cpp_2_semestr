#ifndef CLION_PROGRAMMING_TRIANGLE_H
#define CLION_PROGRAMMING_TRIANGLE_H

class Triangle{
private:
    struct dot{
        int x;
        int y;

        dot(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    dot *fir_vert;
    dot *sec_vert;
    dot *thi_vert;
    double fir_side = 0;
    double sec_side = 0;
    double thi_side = 0;
    double square = 0;

    void set_sides();

    void set_square();
public:
    Triangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3);

    friend bool operator==(Triangle& first_tr, Triangle& second_tr);

    friend bool operator!=(Triangle& first_tr, Triangle& second_tr);

    friend bool operator<(Triangle& first_tr, Triangle& second_tr);

    friend bool operator>(Triangle& first_tr, Triangle& second_tr);

    void add_vector(int x, int y);
};

#endif //CLION_PROGRAMMING_TRIANGLE_H
