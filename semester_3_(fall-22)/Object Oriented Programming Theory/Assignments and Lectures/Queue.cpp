//Aimal Khan.

#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 100;

template <class QueueType>
class Queue {
private:
    QueueType data[MAX_QUEUE_SIZE];
    int _front;
    int _rear;

public:
    Queue() {
        _front = _rear = 0;
    }

    void putInQueue(QueueType item);
    QueueType getFromQueue();
};

template <class QueueType>
void Queue<QueueType>::putInQueue(QueueType item) {
    if (_rear == MAX_QUEUE_SIZE) {
        cout << "Queue is full.\n";
        return;
    }

    _rear++;
    data[_rear] = item;
}

template <class QueueType>
QueueType Queue<QueueType>::getFromQueue() {
    if (_front == _rear) {
        cout << "Queue Underflow.\n";
        return 0;
    }

    _front++;
    return data[_front];
}

int main(){
    Queue<int> a, b; // create two integer queues
    a.putInQueue(10);
    b.putInQueue(19);
    a.putInQueue(20);
    b.putInQueue(1);
    cout << a.getFromQueue() << " ";
    cout << a.getFromQueue() << " ";
    cout << b.getFromQueue() << " ";
    cout << b.getFromQueue() << "\n";

    Queue<double> c, d; // create two double queues
    c.putInQueue(10.12);
    d.putInQueue(19.99);
    c.putInQueue(-20.0);
    d.putInQueue(0.986);
    cout << c.getFromQueue() << " ";
    cout << c.getFromQueue() << " ";
    cout << d.getFromQueue() << " ";
    cout << d.getFromQueue() << "\n";
    return 0;
    //Refactor and Debugged by: Aimal Khan
}
