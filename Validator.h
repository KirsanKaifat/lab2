#ifndef BRACKET_VALIDATOR_H
#define BRACKET_VALIDATOR_H

#include <fstream>
#include "Stack.h"

#define CURLY 0
#define SQUARE 1
#define BRACE 2

class Validator {
public:
    Validator(std::ifstream *inputFile);
    bool Validate();

private:
    std::ifstream *inputFile;
    Stack *stack;
    bool IsBracket(char inputChar);
    int GetBracketTypeByChar(char inputChar);
    bool IsOpenBracket(char inputChar);
    bool IsCloseBracket(char inputChar);
};

#endif
