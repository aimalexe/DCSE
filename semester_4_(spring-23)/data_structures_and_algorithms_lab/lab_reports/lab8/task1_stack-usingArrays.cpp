/*
Task 01
Implement stacks with following operations using arrays using Arrays
a) Creation
b) Pop
c) Push
d) Top
e) Size
f) Empty
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

template <typename any>
class StackUsingArray
{
private:
    any stack[MAX_SIZE];
    int top;

public:
    StackUsingArray() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(any value)
    {   
        if(isFull()){
            cout<<"Error: Stack is full.\n";
            return;
        }
        stack[++top] = value;
    }

    any pop()
    {
        if (isEmpty())
            throw runtime_error("Error: Stack is empty.");
        return stack[top--];
    }

    any peek()
    {
        if (isEmpty())
            throw runtime_error("Error: Stack is empty.");
        return stack[top];
    }

    int size()
    {
        return top + 1;
    }

    void print()
    {
        if(isEmpty()){
            cout<<"Stack is empty. Underflow occur.\n";
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }

    void empty()
    {
        top = -1;
    }
};

// driver program.
int main()
{
    StackUsingArray<int> s;
    s.print();
    cout << "Is Stack full? " << boolalpha << s.isFull() << endl;
    cout << "Is Stack empty? " << boolalpha << s.isEmpty() << endl;

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);

    cout << "Size of Stack is: " << s.size() << endl;
    s.print();

    cout << "Popped: " << s.pop() << endl;
    cout << "Peak Element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Peak Element: " << s.peek() << endl;
    cout << "Is Stack full? " << boolalpha << s.isFull() << endl;
    cout << "Is Stack empty? " << boolalpha << s.isEmpty() << endl;
    cout << "Size of Stack is: " << s.size() << endl;

    s.print();

    return 0;
}

// Coded with ❤ by Aimal Khan.