// Copyright 2021 NNTU-CS

int main() {
    std::string infixExpression;
    std::string postfixExpression = infx2pstfx(infixExpression);
    int result = eval(postfixExpression);
    return 0;
}
