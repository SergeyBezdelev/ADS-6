// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int count;
    int begin;
    int end;

 public:
    TPQueue() : arr(new T[size]), count(0), begin(0), end(0) {}
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T& item) {
        if (count == size) throw "Queue is full";
        int i = end - 1;
        while (i >= begin && item.prior < arr[i].prior) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = item;
        end++;
        count++;
        if (end == size) end = 0;
    }
    T pop() {
        if (count == 0) throw "Queue is empty";
        T item = arr[begin];
        begin++;
        count--;
        if (begin == size) begin = 0;
        return item;
    }
    bool isEmpty() const {
        return count == 0;
    }
    bool isFull() const {
        return count == size;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
