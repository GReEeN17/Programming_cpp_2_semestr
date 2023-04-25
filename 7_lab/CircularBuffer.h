#ifndef CLION_PROGRAMMING_CIRCULARBUFFER_H
#define CLION_PROGRAMMING_CIRCULARBUFFER_H
#include <iostream>
#include <algorithm>

using namespace std;

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

    explicit CircularBuffer(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->buffer = new T[capacity];
        this->bufferFirst = buffer[0];
        this->bufferLast = buffer[capacity - 1];
        this->currentFirst = buffer[0];
        this->currentLast = buffer[0];
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    Iterator start() {
        return Iterator(buffer);
    }

    Iterator end() {
        return Iterator(buffer + capacity - 1);
    }

    void pushFront(T &value) {
        *currentFirst = value;
        if (currentFirst == bufferFirst) {
            currentFirst = bufferLast;
        } else {
            currentFirst--;
        }
    }

    void pushBack(T &value) {
        *currentLast = value;
        if (currentLast == bufferLast) {
            currentLast = bufferFirst;
        } else {
            currentLast++;
        }
    }

    void popFront() {
        *currentFirst = 0;
        if (currentFirst == bufferLast) {
            currentFirst = bufferFirst;
        } else {
            currentFirst++;
        }
    }

    void popBack() {
        *currentLast = 0;
        if (currentLast == bufferFirst) {
            currentLast = bufferLast;
        } else {
            currentLast--;
        }
    }

    void setCapacity(int capacity) {
        if (this->capacity >= capacity) {
            cout << "Set capacity more than current" << "\n";
            return;
        }
        T* gapBuffer = new T[capacity];
        for (int i = 0; i < this->capacity; i++) {
            gapBuffer[i] = *buffer[i];
        }
        buffer = gapBuffer;
        this->capacity = capacity;
    }

    T operator [] (int index) const {
        return buffer[index % capacity];
    }

    void print() {
        for (T i = &buffer[0]; i != &buffer[capacity - 1]; i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
};

#endif //CLION_PROGRAMMING_CIRCULARBUFFER_H
