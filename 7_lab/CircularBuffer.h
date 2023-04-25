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
    int indexFirst;
    T* currentLast;
    int indexLast;
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
        return Iterator(buffer);
    }

    Iterator end() {
        return Iterator(buffer + capacity - 1);
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

    void setCapacity(int capacity) {
        if (this->capacity >= capacity) {
            cout << "Set capacity more than current" << "\n";
            return;
        }
        T* helpBuffer = new T[capacity];
        for (int i = 0; i < this->capacity; i++) {
            helpBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = helpBuffer;
        currentFirst = &buffer[indexFirst];
        currentLast = &buffer[indexLast];
        bufferFirst = &buffer[0];
        bufferLast = &buffer[capacity - 1];
        this->capacity = capacity;
    }

    T operator [] (int index) const {
        return buffer[index % capacity];
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
