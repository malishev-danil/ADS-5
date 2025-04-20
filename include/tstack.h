// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
#include <stdexcept> // Для std::overflow_error и std::underflow_error

template<typename T, int kMaxSize>
class TStack {
 private:
T data[kMaxSize];
int top_index;

 public:
TStack() : top_index(-1) {}

void push(const T& value) {
if (top_index >= kMaxSize - 1) {  //Удалены лишние пробелы
throw std::overflow_error("Стек переполнен");
}
data[++top_index] = value; //Исправлено: убраны лишние пробелы и исправлено обращение
}

T pop() {
if (isEmpty()) { //Удалены лишние пробелы
throw std::underflow_error("Стек неполный"); // Убраны лишние пробелы
}
return data[top_index--]; //Удалены лишние пробелы
}

T peek() const {
if (isEmpty()) { //Удалены лишние пробелы
throw std::underflow_error("Стек пуст"); //Убраны лишние пробелы
}
return data[top_index]; //Удалены лишние пробелы
}

bool isEmpty() const {
return top_index == -1;
}
};

#endif  // INCLUDE_TSTACK_H_
