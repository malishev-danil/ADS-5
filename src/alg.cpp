// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include <sstream>
#include <cctype> 

template <typename T, int MAX_SIZE>
class TStack {
private:
T data[MAX_SIZE];
int top;

public:
TStack() : top(-1) {}
bool isEmpty() const {
return top == -1;
}
bool isFull() const {
return top == MAX_SIZE - 1;
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

std::string infx2pstfx(const std::string& inf) {
std::string postfix = "";
TStack<char, 100> opStack;

for (char c : inf) {
if (isspace(c)) continue;

if (isdigit(c)) {
postfix += c;
postfix += ' ';
}
else if (c == '(') {
opStack.push(c);
}
else if (c == ')') {
while (!opStack.isEmpty() && opStack.peek() != '(') {
postfix += opStack.pop();
postfix += ' ';
}
if (!opStack.isEmpty() && opStack.peek() == '(') {
opStack.pop();
}
else {
throw std::string("Error with parentheses");
}
}
else { // Оператор
int precedence = 0;
if (c == '+' || c == '-') precedence = 1;
else if (c == '*' || c == '/') precedence = 2;

while (!opStack.isEmpty()) {
char topOp = opStack.peek();
int topPrecedence = 0;
if (topOp == '+' || topOp == '-') topPrecedence = 1;
else if (topOp == '*' || topOp == '/') topPrecedence = 2;
else break;

if (precedence <= topPrecedence) {
postfix += opStack.pop();
postfix += ' ';
}
else {
break;
}
}
opStack.push(c);
}
}

while (!opStack.isEmpty()) {
if (opStack.peek() == '(') {
throw std::string("Error");
}
postfix += opStack.pop();
postfix += ' ';
}

if (!postfix.empty() && postfix.back() == ' ') {
postfix.pop_back();
}
return postfix;
}
}

int eval(const std::string& pref) {
TStack<int, 100> numStack;
std::stringstream ss(post);
std::string token;

while (ss >> token) {
if (isdigit(token[0])) {
numStack.push(std::stoi(token));
}
else {
if (numStack.isEmpty()) {
throw std::string("Error in the postfix form");
}
int operand2 = numStack.pop();
if (numStack.isEmpty()) {
throw std::string("Error in the postfix form");
}
int operand1 = numStack.pop();

int result;
if (token == "+") result = operand1 + operand2;
else if (token == "-") result = operand1 - operand2;
else if (token == "*") result = operand1 * operand2;
else if (token == "/") {
if (operand2 == 0) {
throw std::string("Division by zero");
}
result = operand1 / operand2;
}
else {
throw std::string("Invalid operator");
}
numStack.push(result);
}
}

if (numStack.isEmpty()) {
throw std::string("Empty");
}
int finalResult = numStack.pop();
if (!numStack.isEmpty()) {
throw std::string("Error in the postfix form");
}

return finalResult;
}
