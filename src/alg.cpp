// Copyright 2025 NNTU-CS
#include <stack>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include "tstack.h"
#include "alg.h"

int getOperationPriority(char op) {
switch (op) {
case '+': case '-': return 1;
case '*': case '/': return 2;
default: throw std::invalid_argument("Недопустимая операция");
}
}

std::string infx2pstfx(const std::string& infix) {
TStack<char, 100> operatorsStack; 
std::stringstream output;
std::string numberBuffer;

for (char currentChar : infix) {
if (isdigit(currentChar)) {
numberBuffer += currentChar; 
} else {
if (!numberBuffer.empty()) {
output << numberBuffer << " "; 
numberBuffer.clear();
}
if (currentChar == '(') {
operatorsStack.push(currentChar);
} else if (currentChar == ')') {
while (!operatorsStack.isEmpty() && operatorsStack.peek() != '(') {
output << operatorsStack.pop() << " "; 
}
if (!operatorsStack.isEmpty()) {
operatorsStack.pop(); 
}
} else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
while (!operatorsStack.isEmpty() && getOperationPriority(operatorsStack.peek()) >= getOperationPriority(currentChar)) {
output << operatorsStack.pop() << " ";
}
operatorsStack.push(currentChar);
} else if (!isspace(currentChar)) {
throw std::invalid_argument("Недопустимый символ в выражении");
}
}
}

if (!numberBuffer.empty()) {
output << numberBuffer << " ";
}

while (!operatorsStack.isEmpty()) {
output << operatorsStack.pop() << " ";
}

std::string postfixResult = output.str();
if (!postfixResult.empty() && postfixResult.back() == ' ') {
postfixResult.pop_back();
}
return postfixResult;
}

int eval(const std::string& postfix) {
TStack<int, 100> evaluationStack;
std::stringstream ss(postfix);
std::string token;

while (ss >> token) {
if (isdigit(token[0])) {
evaluationStack.push(std::stoi(token));
} else {
if (evaluationStack.size() < 2) {
throw std::invalid_argument("Недостаточно операндов для операции");
}
int operand2 = evaluationStack.pop();
int operand1 = evaluationStack.pop();
switch (token[0]) {
case '+': evaluationStack.push(operand1 + operand2); break;
case '-': evaluationStack.push(operand1 - operand2); break;
case '*': evaluationStack.push(operand1 * operand2); break;
case '/': 
if (operand2 == 0) {
throw std::invalid_argument("Ошибка: деление на ноль");
}
evaluationStack.push(operand1 / operand2); 
break;
}
}
}
if (evaluationStack.isEmpty()) {
throw std::runtime_error("Ошибка: нет результата");
}
return evaluationStack.pop();
}
