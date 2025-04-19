// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int ksize>
class TStack {
 private:
 T data[ksize];
 int top;

 public:
 TStack() : top(-1) {}
 bool isEmpty() const {
 return top == -1;
 }
 bool isFull() const {
 return top == ksize - 1;
 }

 void push(const T& value) {
 if (isFull()) {
 throw std::string("Full");
 }
 data[++top] = value;
 }

 T pop() {
 if (isEmpty()) {
 throw std::string("Empty");
 }
 return data[top--];
 }

 T peek() const {
 if (isEmpty()) {
 throw std::string("Stack is empty");
 }
 return data[top];
 }
 };

#endif  // INCLUDE_TSTACK_H_
