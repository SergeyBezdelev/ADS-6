// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>
struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin;
    int end;
    int count;

 public:
    TPQueue();
    ~TPQueue();
    void push(const T& item);
    T& pop();
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T, int size>
TPQueue<T, size>::TPQueue() : arr(new T[size]), count(0), begin(0), end(0) {}

template<typename T, int size>
TPQueue<T, size>::~TPQueue() {
    delete[] arr;
}

template<typename T, int size>
void TPQueue<T, size>::push(const T& item) {
    if (isFull()) throw std::string("Queue is full");
    count++;
    int index = end, j = begin, i = end;
    while (j < end) {
        j++;
        if (arr[j].prior < item.prior) {
            index = j;
            break;
        }
    }
    while (i > index) {
        i--;
        arr[i % size] = arr[(i - 1) % size];
    }
    arr[index % size] = item;
    end++;
}

template<typename T, int size>
T& TPQueue<T, size>::pop() {
    if (isEmpty()) throw std::string("Queue is empty");
    count--;
    return arr[begin++ % size];
}

template<typename T, int size>
bool TPQueue<T, size>::isEmpty() const {
    return count == 0;
}

template<typename T, int size>
bool TPQueue<T, size>:: isFull() const {
    return count == size;
}
#endif  // INCLUDE_TPQUEUE_H_
