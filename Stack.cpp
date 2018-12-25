#include "Stack.h"

bool Stack::IsEmpty() {
    return this->head == 0;
}

int Stack::Head() {
    return this->head->data;
}

int Stack::Pop() {
    int returnValue = this->head->data;
    this->head = this->head->next;
    return returnValue;
}

void Stack::Push(int data) {
    StackItem *newElement = new StackItem;
    newElement->data = data;
    
    if (this->head == 0) {
        this->head = newElement;
        return;
    }
    
    newElement->next = this->head;
    this->head = newElement;
}
