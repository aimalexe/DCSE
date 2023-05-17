/*
Task 1: Implement singly linked list with following operations:
    a) Traverse
    b) Delete
    c) Print
    d) Add
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;       // Some Data;
    Node *nextNode; // Pointer to next node.
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void addToLast(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->nextNode = nullptr;

        if (head == nullptr)
        { // Empty list
            head = temp;
            tail = temp;
        }
        else
        { // Not empty List.
            tail->nextNode = temp;
            tail = temp;
        }
    }
    void printList()
    {
        Node *current = head;
        cout << "List: ";
        while (current != nullptr)
        {
            cout << current->data << " ==> ";
            current = current->nextNode;
        }
        cout << endl;
    }
    void deleteFirstNode()
    {
        if (head == nullptr)
            return;
        Node *firstNode = head;
        head = head->nextNode;
        delete firstNode;
    }
    void traverse()
    {
        Node *current = head;
        while (current != nullptr)
        {
            // Perform some operation on the current node
            cout << current->data << " ";

            // Move to the next node in the list
            current = current->nextNode;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.addToLast(3);
    list.addToLast(5);
    list.addToLast(2);
    list.addToLast(98);
    list.printList();
    list.traverse();
    list.deleteFirstNode();
    list.deleteFirstNode();
    list.printList();

    return 0;
}

