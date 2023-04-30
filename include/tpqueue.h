// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T>
class TPQueue {
  private:
    struct Queue{
      T value;
      Queue* next;
      Queue* prev;
    };
    Queue* head;
    Queue* create(const T& value) {
        Queue* temp = new Queue;
        Queue->value = value;
        Queue->next = nullptr;
        return temp;
    } 
  
  public:
    TPQueue() : head(nullptr) {}
    void push(const T& item);
    T pop();
    ~TPQueue() {
        while (head) {
        Item* tmp = head->next;
        delete head;
        head = tmp;
       }
    }
    TPQueue() {
      head = nullptr;
    }
    bool Empty() {
      return head == nullptr;
    }
    T pop() {
      if (Empty()) {
        throw std::string("Empty!");
      } else {
        Queue* Queue = head->next;
        T i = head->val;
        delete head;
        head = Queue;
        return i;
      }
    }  
};
template<typename T>
void TPQueue<T>::push(const T& i) {
    if (head == nullptr) {
        head = create(i);
    } else {
        Item* cur = head;
        int l = 0;
        while (cur) {
            if (cur->value.prior < i.prior) {
                break;
            }
            cur = cur->next;
            l++;
        }
        if (l == 0) {
            Item* tmp = new Item;
            tmp->next = head;
            tmp->value = i;
            head = tmp;
        } else {
            cur = head;
            for (int k = 1; k < l; k++) {
                cur = cur->next;
            }
            Item* tmp = new Item;
            tmp->next = cur->next;
            tmp->value = i;
            cur->next = tmp;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
