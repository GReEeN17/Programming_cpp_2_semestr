#include <iostream>
#include <vector>

namespace CustAlgo {
    template<typename T, typename P>
    bool any_of(const T &container, P &p) {
        auto i = container.begin();
        while (i != container.end()){
            if (p(*i)) {
                return true;
            }
            ++i;
        }
        return false;
    }

    template <typename T, typename P>
    bool one_of(const T &container, P &p) {
        int count = 0;
        auto i = container.begin();
        while (i != container.end()) {
            if (p(*i)) {
                count++;
            }
            ++i;
        }
        return (count == 1);
    }

    template <typename T, typename P>
    bool is_palindrome(const T &container, P &p) {
        auto st = container.begin();
        auto ed = container.end() - 1;
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

inline bool is_both_even(Numbers<int> numb) {
    bool fir = isEven(numb.get_fir());
    bool sec = isEven(numb.get_sec());
    return fir && sec;
}

inline bool is_both_odd(Numbers<int> numb) {
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

    std::vector<int> Num_4 = {1, 3, 5, 3, 1};

    std::vector<int> Num_5 = {1, 2, 3, 4, 5};

    std::vector<int> Num_6 = {2, 4, 5, 6, 8};

    std::vector<float> Num_7 = {0.0, 2.0, 3.0, 2.3, 0.0};

    std::cout << "any_of: " << CustAlgo::any_of(Num_4, isEven<int>) << "\n";
    std::cout << "any_of: " << CustAlgo::any_of(Num_5, isEven<int>) << "\n";
    std::cout << "any_of: " << CustAlgo::any_of(Num_1, is_both_even) << '\n';
    std::cout << "any_of: " << CustAlgo::any_of(Num_3, is_both_even) << "\n";
    std::cout << "one_of: " << CustAlgo::one_of(Num_6, isOdd<int>) << "\n";
    std::cout << "one_of: " << CustAlgo::one_of(Num_7, isNull<float>) << "\n";
    std::cout << "is_palindrome: " << CustAlgo::is_palindrome(Num_4, is_symmetric<int>);
}

