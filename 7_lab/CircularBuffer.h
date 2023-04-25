#ifndef CLION_PROGRAMMING_CIRCULARBUFFER_H
#define CLION_PROGRAMMING_CIRCULARBUFFER_H
#include <iostream>
#include <algorithm>

template<class T>
class CircularBuffer{
private:
    int capacity;
    int size;
    T* buffer;
    T* currentFirst;
    T* currentLast;
    T* bufferFirst;
    T* bufferLast;
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T *currentValue;
    public:
        explicit Iterator(T currentValue) {
            this->currentValue = currentValue;
        }

        T *getCurrentValue() const {
            return currentValue;
        }

        Iterator& operator + (int value) {
            currentValue += value;
            return *this;
        }

        Iterator& operator - (int value) {
            currentValue -= value;
            return *this;
        }

        Iterator& operator ++ () {
            currentValue++;
            return *this;
        };

        Iterator& operator -- () {
            currentValue--;
            return *this;
        }

        T& operator * () const {
            return *this;
        };

        T* operator -> () const {
            return this;
        }

        Iterator& operator = (T& other) const {
            currentValue = *other;
            return *this;
        }

        bool operator == (const Iterator* other) {
            return this->currentValue == other->currentValue;
        }

        bool operator != (const Iterator* other) {
            return this->currentValue != other->currentValue;
        }

        bool operator > (const Iterator* other) {
            return this->currentValue > other->currentValue;
        }

        bool operator < (const Iterator* other) {
            return this->currentValue < other->currentValue;
        }

        bool operator >= (const Iterator* other) {
            return this->currentValue >= other->currentValue;
        }

        bool operator <= (const Iterator* other) {
            return this->currentValue <= other->currentValue;
        }
    };


};

#endif //CLION_PROGRAMMING_CIRCULARBUFFER_H
