// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int MaxSize;
    int begin;
    int end;
    int count;

 public:
    TPQueue() : MaxSize(size), begin(0), end(0), count(0) {
        arr = new T[MaxSize + 1];
    }
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T& item) {
        if (count >= MaxSize) {
            throw "Queue is full!";
            return;
        }
        arr[end++] = item;
        count++;
        if (end > MaxSize) end -= MaxSize + 1;
        int i = end - 1;
        while (i != begin) {
            if (arr[i].prior > arr[i - 1].prior) {
                T tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
            } else {
                break;
            }
            i--;
            if (i < 0) i = MaxSize;
        }
    }
    T pop() {
        if (count <= 0) {
            throw "Queue is empty!";
            return T();
        }
        count--;
        int res = begin++;
        if (begin > MaxSize) begin -= MaxSize + 1;
        return arr[res];
    }
    T top() const {
        return arr[begin];
    }
    bool is_empty() const {
        return count == 0;
    }
    bool is_full() const {
        return count == MaxSize;
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
