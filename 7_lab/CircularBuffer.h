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
    int indexFirst;
    int indexLast;
public:
    class Iterator : public iterator<random_access_iterator_tag, T>{
    private:
        T *currentValue;
    public:
        using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
        difference_type operator-(const Iterator& obj) const
        {
            return currentValue - obj.currentValue;
        }

        explicit Iterator(T *currentValue_) {
            currentValue = currentValue_;
        }

        Iterator (const Iterator& other) {
            currentValue = other.currentValue;
        }

        Iterator operator + (int value) {
            currentValue += value;
            return *this;
        }

        Iterator operator - (int value) {
            currentValue -= value;
            return *this;
        }


        Iterator operator ++ () {
            ++currentValue;
            return *this;
        };

        Iterator operator -- () {
            --currentValue;
            return *this;
        }

        T& operator * () const {
            return *currentValue;
        };

        T* operator -> () const {
            return currentValue;
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
        this->indexFirst = 0;
        this->indexLast = 0;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    Iterator begin() {
        return Iterator(buffer);
    }

    Iterator end() {
        return Iterator(buffer + capacity);
    }

    void pushFront(const T &value) {
        if (indexFirst == indexLast && size == 0) {
            buffer[indexFirst] = value;
            size++;
            return;
        }
        indexFirst = indexFirst == 0 ? capacity - 1 : indexFirst - 1;
        if (size == capacity) {
            indexLast = indexLast == 0 ? capacity - 1 : indexLast - 1;
        } else {
            size++;
        }
        buffer[indexFirst] = value;
    }

    void pushBack(const T &value) {
        if (indexFirst == indexLast && size == 0) {
            buffer[indexLast] = value;
            size++;
            return;
        }
        indexLast = indexLast == capacity - 1 ? 0 : indexLast + 1;
        if (size == capacity) {
            indexFirst = indexFirst == capacity - 1 ? 0 : indexFirst + 1;
        } else {
            size++;
        }
        buffer[indexLast] = value;
    }

    void popFront() {
        if (size == 0) {
            cout << "there is no elements to delete, size is 0" << "\n";
            return;
        }
        buffer[indexFirst] = 0;
        indexFirst = indexFirst == capacity - 1 ? 0 : indexFirst + 1;
        size--;
    }

    void popBack() {
        if (size == 0) {
            cout << "there is no elements to delete, size is 0" << "\n";
            return;
        }
        buffer[indexLast] = 0;
        indexLast = indexLast == 0 ? capacity - 1 : indexLast - 1;
        size--;
    }

    void insert(Iterator iterator, T value) {
        int index = (iterator - begin()) % capacity;
        if (!inRange(index)) {
            cout << "Iterator is out of range, increment or decrement it" << "\n";
            return;
        }
        T bufferLastItem = buffer[indexLast];
        int i = indexLast;
        while (i != index) {
            buffer[i % capacity] = buffer[(i - 1) % capacity];
            i = i > 0 ? i - 1 : capacity - 1;
        }
        buffer[index] = value;
        if (size != capacity) {
            size++;
            indexLast = indexLast == capacity - 1 ? 0 : indexLast + 1;
            buffer[indexLast] = bufferLastItem;
        }
    }

    void remove(Iterator iterator) {
        if (size == 0) {
            cout << "there is no elements to delete, size is 0" << "\n";
            return;
        }
        int index = (iterator - begin()) % capacity;
        if (!inRange(index)) {
            cout << "Iterator is out of range, increment or decrement it" << "\n";
            return;
        }
        int bufferIndexLast = indexLast;
        while (index != indexLast) {
            buffer[index % capacity] = buffer[(index + 1) % capacity];
            index = index == capacity - 1 ? 0 : index + 1;
        }
        indexLast = indexLast == 0 ? capacity - 1 : indexLast - 1;
        buffer[bufferIndexLast] = 0;
        size--;
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
        this->capacity = capacity_;
    }

    T& operator [] (const int index) const {
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

private:
    bool inRange(int index) {
        bool firstCondition = indexFirst <= indexLast && (index < indexFirst || index > indexLast);
        bool secondCondition = indexFirst > indexLast && index > indexLast && index < indexFirst;
        return !(firstCondition || secondCondition);
    }
};

#endif //CLION_PROGRAMMING_CIRCULARBUFFER_H
