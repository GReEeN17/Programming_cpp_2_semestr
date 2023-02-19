#include <iostream>
#include "Own_que.h"
#include "patterns_exceptions.h"


inline void main_5_lab() {
    try {
        int N;
        std::cin >> N;
        queue<int> q(N);
        q.enqueue(3);
        q.enqueue(4);
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.enqueue(5);
    } catch (QueException &ex) {
        std::cout << ex.get_error() << "\n";
    }
}