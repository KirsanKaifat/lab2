#include <iostream>
#include "Validator.h"
#include "Stack.h"

Validator::Validator(std::ifstream *inputFile) {
    this->inputFile = inputFile;
    this->stack = new Stack;
}

bool Validator::Validate() {
    char bracket;
    while (this->inputFile->get(bracket)) {
        if (bracket == 10 || bracket == 32) continue;
        if (!this->IsBracket(bracket)) return false;

        if (this->IsOpenBracket(bracket)) {
            this->stack->Push(this->GetBracketTypeByChar(bracket));
        }

        if (this->IsCloseBracket(bracket)) {
            if (!this->stack->IsEmpty() && this->GetBracketTypeByChar(bracket) == this->stack->Head()){
                this->stack->Pop();
            } else {
                return false;
            }
        }
    }

    return this->stack->IsEmpty();
}

bool Validator::IsBracket(char inputChar) {
    return inputChar == '(' || inputChar == ')' || inputChar == '[' || inputChar == ']' || inputChar == '{' || inputChar == '}';
}

int Validator::GetBracketTypeByChar(char inputChar) {
    if (inputChar == '(' || inputChar == ')') return CURLY;
    if (inputChar == '[' || inputChar == ']') return SQUARE;
    if (inputChar == '{' || inputChar == '}') return BRACE;
}

bool Validator::IsOpenBracket(char inputChar) {
    return inputChar == '(' || inputChar == '[' || inputChar == '{';
}

bool Validator::IsCloseBracket(char inputChar) {
    return inputChar == ')' || inputChar == ']' || inputChar == '}';
}
