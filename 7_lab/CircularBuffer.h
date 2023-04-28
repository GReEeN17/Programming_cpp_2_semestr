#ifndef CLION_PROGRAMMING_CIRCULARBUFFER_H
#define CLION_PROGRAMMING_CIRCULARBUFFER_H
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T>
class CircularBuffer{
private:
    int capacity;
    int size;
    T* buffer;
    T* currentFirst;
    int indexFirst;
    T* currentLast;
    int indexLast;
    T* bufferFirst;
    T* bufferLast;
public:
    class Iterator : public iterator<random_access_iterator_tag, T>{
    private:
        T *currentValue;
    public:
        Iterator(T *currentValue_) : currentValue(currentValue_){}

        T& operator + (int value) {
            return *(currentValue + value);
        }

        T& operator - (int value) {
            return *(currentValue - value);
        }


        T& operator ++ () {
            return *(++currentValue);
        };

        T& operator -- () {
            return *(--currentValue);
        }

        T& operator * () const {
            return *currentValue;
        };

        T& operator -> () const {
            return *currentValue;
        }

        Iterator& operator = (T& other) const {
            currentValue = *other;
            return *this;
        }

        bool operator == (const Iterator* other) const{
            return this->currentValue == other->currentValue;
        }

        bool operator != (const Iterator* other) const{
            return this->currentValue != other->currentValue;
        }

        bool operator > (const Iterator* other) const{
            return this->currentValue > other->currentValue;
        }

        bool operator < (const Iterator* other) const{
            return this->currentValue < other->currentValue;
        }

        bool operator >= (const Iterator* other) const{
            return this->currentValue >= other->currentValue;
        }

        bool operator <= (const Iterator* other) const{
            return this->currentValue <= other->currentValue;
        }
    };

    explicit CircularBuffer(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->buffer = new T[capacity];
        this->bufferFirst = &buffer[0];
        this->bufferLast = &buffer[capacity - 1];
        this->currentFirst = &buffer[0];
        this->currentLast = &buffer[0];
        this->indexFirst = 0;
        this->indexLast = 0;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    Iterator start() {
        return buffer;
    }

    Iterator end() {
        return buffer + capacity;
    }

    void pushFront(const T &value) {
        *currentFirst = value;
        size++;
        if (currentFirst == bufferFirst) {
            indexFirst = capacity - 1;
            currentFirst = bufferLast;
        } else {
            indexFirst--;
            currentFirst--;
        }
    }

    void pushBack(const T &value) {
        *currentLast = value;
        size++;
        if (currentLast == bufferLast) {
            indexLast = 0;
            currentLast = bufferFirst;
        } else {
            indexLast++;
            currentLast++;
        }
    }

    void popFront() {
        *currentFirst = 0;
        size--;
        if (currentFirst == bufferLast) {
            indexFirst = 0;
            currentFirst = bufferFirst;
        } else {
            indexFirst++;
            currentFirst++;
        }
    }

    void popBack() {
        *currentLast = 0;
        size--;
        if (currentLast == bufferFirst) {
            indexLast = capacity - 1;
            currentLast = bufferLast;
        } else {
            indexLast--;
            currentLast--;
        }
    }

    void setCapacity(int capacity_) {
        if (this->capacity >= capacity_) {
            cout << "Set capacity more than current" << "\n";
            return;
        }
        T* helpBuffer = new T[capacity_];
        for (int i = 0; i < this->capacity; i++) {
            helpBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = helpBuffer;
        currentFirst = &buffer[indexFirst];
        currentLast = &buffer[indexLast];
        bufferFirst = &buffer[0];
        bufferLast = &buffer[capacity_ - 1];
        this->capacity = capacity_;
    }

    T& operator [] (const int index) const {
        if (index > 0 && index < capacity) return buffer[index];
        return buffer[0];
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            cout << buffer[i] << " ";
        }
        cout << "\n";
    }

    ~CircularBuffer() {
        delete[] buffer;
    }
};

#endif //CLION_PROGRAMMING_CIRCULARBUFFER_H
