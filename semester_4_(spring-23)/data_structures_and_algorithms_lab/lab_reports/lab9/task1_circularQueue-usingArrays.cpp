/*
Implement following operations of circular queue using arrays
a) Creation
b) Enqueue
c) Dequeue
d) Front
e) Rear
f) Size
g) empty
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 50;

class CircularQueueUsingArray
{
private:
    int queue[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueueUsingArray(): front(-1), rear(-1){}

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX_SIZE == front);
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
        int i = front;
        while (i != rear)
        {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << queue[rear] << endl;
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve rear element. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        return queue[rear];
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Cannot retrieve front element. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        return queue[front];
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Cannot put further elements. Queue is full. Overflow occurred.\n";
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot remove further elements. Queue is empty. Underflow occurred.\n";
            return -1;
        }
        int value = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }
};

// Driver Program
int main()
{
    CircularQueueUsingArray q;
    cout << "Is Queue Empty? " << boolalpha << q.isEmpty() << endl;
    cout << "Size of Queue: " << q.size() << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "The Rear element is: " << q.getRear() << endl;
    cout << "The Front element is: " << q.getFront() << endl;
    q.print();

    cout << "Is Queue Empty? " << boolalpha << q.isEmpty() << endl;
    cout << "Size of Queue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(5);
    q.enqueue(6);

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