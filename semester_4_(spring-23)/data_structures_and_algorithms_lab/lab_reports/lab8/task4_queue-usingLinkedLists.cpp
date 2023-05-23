/*
Task 04
Implement queueswith following operations using linked list
a) Creation
b) Enqueue
c) Dequeue
d) Front
e) Rear
f) Size
g) Empty
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

template <typename generic>
class QueueUsingLinkedList
{
private:
    int currentSize;
    Node<generic> *front;
    Node<generic> *rear;

public:
    QueueUsingLinkedList() : currentSize(0), front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return currentSize == 0;
        // OR
        // return front == nullptr;
    }

    bool isFull()
    {
        return currentSize == MAX_SIZE;
        /*OR
        Node* newNode = new Node;
        if (newNode == nullptr) {
            delete newNode;
            return true;
        }
        delete newNode;
        return false;
        */
    }

    void clear()
    {
        if (isEmpty())
            return;
        Node<generic> *current;
        while (front != nullptr)
        {
            current = front;
            front = front->nextNode;
            delete current;
        }
        rear = nullptr;
        currentSize = 0;
    }

    int size()
    {
        return currentSize;
        /* OR
        int count = 0;
        Node* temp = front;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
        */
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Cannot print further elements. Queue is empty. Underflow occur.\n";
            return;
        }

        Node<generic> *current = front;
        cout << "Queue: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->nextNode;
        }
        cout << endl;
    }

    generic getRear()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve rear element. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        return rear->data;
    }

    generic getFront()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve front element. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        return front->data;
    }

    void enqueue(generic value)
    {
        if (isFull())
        {
            cout << "Cannot put further elements. Queue is full. Overflow occurred.\n";
            return;
        }
        Node<generic> *newNode = new Node<generic>;
        newNode->data = value;
        newNode->nextNode = nullptr;

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->nextNode = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    generic dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot remove further elements. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        Node<generic> *temp = front;
        generic value = front->data;
        front = front->nextNode;
        delete temp;
        if (front == nullptr)
            rear = nullptr;
        currentSize--;
        return value;
    }
};

int main()
{
    QueueUsingLinkedList<char> q;
    cout << "Is Queue Empty? " << boolalpha << q.isEmpty() << endl;
    cout << "Size of Queue: " << q.size() << endl;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');

    cout << "The Rear element is: " << q.getRear() << endl;
    cout << "The Front element is: " << q.getFront() << endl;
    q.print();

    cout << "Is Queue Empty? " << boolalpha << q.isEmpty() << endl;
    cout << "Size of Queue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue('e');
    q.enqueue('f');

    cout << "The Rear element is: " << q.getRear() << endl;
    cout << "The Front element is: " << q.getFront() << endl;

    q.print();

    q.clear();
    cout << "\nAfter clearing queue.\n";
    cout << "Is Queue Empty? " << boolalpha << q.isEmpty() << endl;
    cout << "Size of Queue: " << q.size() << endl;
    cout << "The Rear element is: " << q.getRear() << endl;
    cout << "The Front element is: " << q.getFront() << endl;
    q.print();

    return 0;
}

// Coded with ❤ by Aimal Khan.