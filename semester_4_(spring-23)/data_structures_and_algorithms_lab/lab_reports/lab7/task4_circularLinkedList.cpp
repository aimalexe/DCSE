/*
Task 4: Implement a single circular list with following operations
            a) Insert at start of the list (pre-append data)
            b) Insertion at end (append data)
            c) Insertion at nth location
            d) Deletion from start of the list
            e) Deletion the end of the list
            f) Insertion from nth location
            g) Search for a key
            h) Update list
            i) Empty list
            j) Calculate size of the list
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nextNode;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}

    void addToStart(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->nextNode = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            head->nextNode = head; // connecting in circle.
        }
        else
        {
            newNode->nextNode = head;
            head = newNode;
        }
    }

    void addAt(int index, int value)
    {
        if (index <= 0)
        {
            cout << "Index out of bound.\n";
            return;
        }
        Node *newNode = new Node;
        newNode->data = value;

        if (index == 1)
        {
            newNode->nextNode = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 1; i < index - 1 && current != nullptr; i++)
            current = current->nextNode;

        if (current == nullptr)
        { // n is greater than the size of the list
            cout << "Position " << index << " is out of range." << endl;
            delete newNode; // Free the memory allocated for the new node
            return;
        }

        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }

    void addToLast(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->nextNode = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            head->nextNode = head; // Circular connection
        }
        else
        {
            Node *temp = head;
            while (temp->nextNode != head)
            {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            newNode->nextNode = head;
        }
    }

    void printList()
    {
        Node *current = head;
        cout << "List: ";
        if (current != nullptr)
        {
            do
            {
                cout << current->data << " ==> ";
                current = current->nextNode;
            } while (current != head);
        }
        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;

    list.addToLast(5);
    list.addToLast(10);
    list.addToStart(15);
    list.addAt(2, 20);
    //list.printList();

    return 0;
}

// Coded with ❤ by Aimal Khan.