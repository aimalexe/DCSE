/*
Task 3: Implement a double linked list with following operations
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

template <typename T>
struct Node
{
    T data;
    Node<T> *nextNode;
    Node<T> *previousNode;
};

template <typename generic>
class DoublyLinkedList
{
private:
    Node<generic> *head;
    Node<generic> *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addToStart(generic value)
    {
        Node<generic> *newNode = new Node<generic>;
        newNode->data = value;

        if (head == nullptr)
        { // List is EMpty.
            newNode->nextNode = nullptr;
            newNode->previousNode = head;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->nextNode = head;
            head->previousNode = newNode;
            head = newNode;
        }
    }

    void addAt(int index, generic value)
    {
        if (index <= 0)
        {
            cout << "Index out of bound.\n";
            return;
        }
        Node<generic> *newNode = new Node<generic>;
        newNode->data = value;

        if (index == 1)
        {
            if (head != NULL)
            {
                newNode->nextNode = head;
                head->previousNode = newNode;
            }
            head = newNode;
            if (tail == NULL)
                tail = newNode;
            return;
        }

        Node<generic> *current = head;
        for (int i = 1; i < index - 1 && current != nullptr; i++)
            current = current->nextNode;

        if (current == nullptr)
        { // n is greater than the size of the list
            cout << "Position " << index << " is out of range." << endl;
            delete newNode; // Free the memory allocated for the new Node<generic>
            return;
        }

        newNode->nextNode = current->nextNode;
        newNode->previousNode = current;
        if (current->nextNode != NULL)
            current->nextNode->previousNode = newNode;
        current->nextNode = newNode;
        if (newNode->nextNode == NULL)
            tail = newNode;
    }

    void addToLast(generic value)
    {
        Node<generic> *newNode = new Node<generic>;
        newNode->data = value;
        newNode->nextNode = nullptr;
        newNode->previousNode = nullptr;

        if (head == nullptr)
        { // Empty list
            head = newNode;
            tail = newNode;
        }
        else
        { // Not empty List.
            newNode->previousNode = tail;
            tail->nextNode = newNode;
            tail = newNode;
        }
    }

    void printList()
    {
        Node<generic> *current = head;
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

        Node<generic> *firstNode = head;

        if (head->nextNode != nullptr) // List is not empty
            head->nextNode->previousNode = nullptr;
        else // only one node in the list.
            tail = nullptr;

        head = head->nextNode;
        delete firstNode;
    }

    void deleteLastNode()
    {
        if (head == nullptr) // Empty List
            return;
        else if (head->nextNode == nullptr)
        { // One Node only.
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        else
        {
            Node<generic> *lastNode = tail;
            tail = tail->previousNode;
            tail->nextNode = nullptr;

            delete lastNode;
        }
    }

    void searchFor(generic key)
    {
        if (head == nullptr)
        {
            cout << "List is Empty. Cannot search key in empty list.\n";
            return;
        }
        Node<generic> *current = head;
        while (current != nullptr)
        {
            if (current->data == key)
            {
                cout << key << " is present in list.\n";
                return;
            }
            current = current->nextNode;
        }
        cout << key << " is not found in list.\n";
    }

    void updateNode(generic key, generic newValue)
    {
        Node<generic> *current = head;
        while (current != nullptr)
        {
            if (current->data == key)
            {                             // Key found
                current->data = newValue; // Update the value of the node
                return;
            }
            current = current->nextNode;
        }
        cout << "Key " << key << " not found." << endl; // Key not found
    }

    bool isEmptyList()
    {
        return head == nullptr;
    }

    void clearList()
    {
        if (isEmptyList())
            return;

        Node<generic> *current = head;
        Node<generic> *temp;
        while (current != nullptr)
        {
            temp = current;
            current = current->nextNode;
            delete temp;
        }
        head = tail = nullptr;
    }

    int sizeOfList()
    {
        int count = 0;
        Node<generic> *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->nextNode;
        }
        return count;
    }
};

// Driver Program.
int main()
{
    DoublyLinkedList<float> list;

    list.addToStart(1.1);
    list.addToStart(2.2);

    list.addToLast(10.10);
    list.addToLast(11.11);
    list.addToLast(12.12);

    list.addAt(3, 3.3);

    list.printList();
    cout << "List size is:" << list.sizeOfList() << endl;

    list.deleteFirstNode();
    list.deleteFirstNode();

    list.addToStart(0.00);
    list.addAt(6, 13.13);
    list.printList();

    list.deleteLastNode();

    list.printList();
    list.searchFor(10.10);

    cout << "10.10 is updated to 22.22";
    list.updateNode(10.10, 22.22);
    cout << endl;

    list.searchFor(76.76);

    cout << "Is List is empty? " << boolalpha << list.isEmptyList() << endl;
    list.clearList();
    cout << "Is List is empty? " << boolalpha << list.isEmptyList() << endl;
    list.printList();
    cout << "List size is:" << list.sizeOfList() << endl;

    return 0;
}

// Coded with ❤ by Aimal Khan.