#include <iostream>
#include <vector>

namespace CustAlgo {
    template<typename T, typename P>
    bool any_of(const T &start, const T &end, P &p) {
        for (T i = start; i < end; i++) {
            if (p(*i)) {
                return true;
            }
        }
        return false;
    }

    template <typename T, typename P>
    bool one_of(const T &start, const T &end, P &p) {
        int count = 0;
        for (T i = start; i < end; i++) {
            if (p(*i)) {
                count++;
            }
        }
        return (count == 1);
    }

    template <typename T, typename P>
    bool is_palindrome(const T &start, const T &end, P &p) {
        T st = start, ed = end - 1;
        while (st < ed) {
            if (!p(*st++, *ed--)) {return false;}
        }
        return true;
    }
}

template <class T>
class Numbers{
private:
    T fir;
    T sec;
public:
    Numbers() = default;

    Numbers(T fir, T sec) {
        this->fir = fir;
        this->sec = sec;
    }

    T get_fir() {
        return this->fir;
    }

    T get_sec() {
        return this->sec;
    }
};

template <class T>
bool isEven(T var) {
    return var % 2 == 0;
}

template <class T>
bool isNull(T var) {
    return var == 0;
}

template <class T>
bool isOdd(T var) {
    return var % 2 != 0;
}

template <class T>
bool is_symmetric(T fir, T sec) {
    return fir == sec;
}

bool is_both_even(Numbers<int> numb) {
    bool fir = isEven(numb.get_fir());
    bool sec = isEven(numb.get_sec());
    return fir && sec;
}

bool is_both_odd(Numbers<int> numb) {
    bool fir = isOdd(numb.get_fir());
    bool sec = isOdd(numb.get_sec());
    return fir && sec;
}

inline void main_6_lab() {
    std::vector<Numbers<int>> Num_1 = {
            Numbers(1, 2),
            Numbers(3, 4),
            Numbers(5, 6),
            Numbers(7, 8)
    };

    std::vector<Numbers<int>> Num_2 = {
            Numbers(1, 3),
            Numbers(5, 7),
            Numbers(9, 11),
            Numbers(13, 15)
    };

    std::vector<Numbers<int>> Num_3 = {
            Numbers(2, 4),
            Numbers(6, 8),
            Numbers(10, 12),
            Numbers(14, 16)
    };

    std::vector<int> Num_4 = {1, 3, 5, 7, 9};

    std::vector<int> Num_5 = {1, 2, 3, 4, 5};

    std::vector<int> Num_6 = {2, 4, 5, 6, 8};

    std::vector<int> Num_7 = {0, 2, 3, 0, 9};

    std::string str_1 = "abcba";

    std::string str_2 = "abcde";

    std::cout << "any_of: " << CustAlgo::any_of(Num_4.begin(), Num_4.end(), isEven<int>) << "\n";
    std::cout << "any_of: " << CustAlgo::any_of(Num_5.begin(), Num_5.end(), isEven<int>) << "\n";
    std::cout << "any_of: " << CustAlgo::any_of(Num_1.begin(), Num_1.end(), is_both_even) << '\n';
    std::cout << "any_of: " << CustAlgo::any_of(Num_3.begin(), Num_3.end(), is_both_even) << "\n";
    std::cout << "one_of: " << CustAlgo::one_of(Num_6.begin(), Num_6.end(), isOdd<int>) << "\n";
    std::cout << "one_of: " << CustAlgo::one_of(Num_7.begin(), Num_7.end(), isNull<int>) << "\n";
    std::cout << "is_palindrome: " << CustAlgo::is_palindrome()
}

