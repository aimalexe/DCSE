/*
Task 03
Implement queues with following operations using arrays
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

template<typename generic>
class QueueUsingArray
{
private:
    generic queue[MAX_SIZE];
    int front;
    int rear;

public:
    QueueUsingArray() : front(-1), rear(-1) {}

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void clear()
    {
        front = rear = -1;
    }

    int size()
    {
        return isEmpty() ? 0 : (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Cannot print further elements. Queue is empty. Underflow occur.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }

    generic getRear()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve rear element. Queue is empty. Underflow occurred.\n";
            return -1;
        }

        return queue[rear];
    }

    generic getFront()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve front element. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        return queue[front];
    }

    void enqueue(generic value)
    {
        if (isFull())
        {
            cout << "Cannot put further elements. Queue is full. Overflow occurred.\n";
            return;
        }
        if (isEmpty())
            front = 0;

        queue[++rear] = value;
    }

    generic dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot remove further elements. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        generic value = queue[front];
        if (rear == front)
            rear = front = -1;
        else
        {
            for (int i = front + 1; i <= rear; i++)
                queue[i - 1] = queue[i];
            rear--;
        }
        return value;
    }
};

// Driver Program
int main()
{
    QueueUsingArray<char> q;
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