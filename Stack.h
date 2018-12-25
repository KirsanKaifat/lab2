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
