// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int kMaxSize>
class TStack {
private:
T data[kMaxSizel;
int top_index;

public: 
TStack(): top_index(-1) {}
void push(const T& value) {
if (top index >= kMaxSize - 1) {
throw std::overflow_error ("Стек переполнен");
}
data [++top.index] = value;
}
T pop() {
if (isEmpty()) {
throw std:: underflow_error ("Стек неполный");
}
return data[top_index--];
}
T peek() const {
if (isEmpty()) {
throw std:: underflow_error ("Стек пуст");
}
return data[top_index];
}
bool isEmpty() const {
return top_index == -1;
}
};

#endif  // INCLUDE_TSTACK_H_
