/*
Implement stacks with following operations using linked Lists
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

template <typename T>
struct Node
{
    T data;
    Node *nextNode;
};

template <typename any>
class StackUsingLinkedList
{
private:
    Node<any> *top;
    int currentSize;

public:
    StackUsingLinkedList() : top(nullptr), currentSize(0) {}

    bool isEmpty()
    {
        return top == nullptr;
    }

    bool isFull()
    {
        return currentSize == MAX_SIZE;
    }

    void push(any value)
    {
        if (isFull())
        {
            cout << "Error: Stack is full.\n";
            return;
        }

        Node<any> *newNode = new Node<any>;
        newNode->data = value;
        newNode->nextNode = top;
        top = newNode;
        currentSize++;
    }

    any pop()
    {
        if (isEmpty())
            throw runtime_error("Error: Stack is empty.");

        any value = top->data;
        Node<any> *current = top;
        top = top->nextNode;
        delete current;
        currentSize--;
        return value;
    }

    any peek()
    {
        if (isEmpty())
            throw runtime_error("Error: Stack is empty.");
        return top->data;
    }
    int size()
    {
        return currentSize;
    }

    void print()
    {
        Node<any> *current = top;
        cout << "Stack: ";
        while (current != nullptr)
        {
            cout << current->data << " ==> ";
            current = current->nextNode;
        }
        cout << endl;
    }

    void Empty()
    {
        if (isEmpty())
            return;

        Node<any> *current = top;
        Node<any> *temp;
        while (current != nullptr)
        {
            temp = current;
            current = current->nextNode;
            delete temp;
        }
        top = nullptr;
    }
};

// driver program.
int main()
{
    StackUsingLinkedList<char> s;
    s.print();
    cout << "Is Stack full? " << boolalpha << s.isFull() << endl;
    cout << "Is Stack empty? " << boolalpha << s.isEmpty() << endl;

    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

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