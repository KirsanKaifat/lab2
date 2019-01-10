#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H


struct StackItem{
    int data;
    StackItem *next;
} ;

class Stack {
private:
    StackItem *head;
public:
    void Push(int data);
    int Pop();
    int Head();
    bool IsEmpty();
};

#endif
