/*
Implement hash table with following operations
a) Hashing
b) Insertion
c) Deletion
d) Searching
e) Rehashing
Note: Generally we do re-hashing when hashtable is filled beyond certain number-Load Factor.
*/

#include <iostream>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable
{
private:
    Node **table;
    int size;
    int capacity;

    int hashFunction(int key)
    {
        return key % capacity;
    }

    void rehash()
    {
        capacity *= 2;
        Node **newTable = new Node *[capacity] {};

        for (int i = 0; i < capacity / 2; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *newNode = new Node(current->key, current->value);
                int index = hashFunction(newNode->key);
                if (newTable[index] == nullptr)
                    newTable[index] = newNode;
                else
                {
                    Node *temp = newTable[index];
                    while (temp->next != nullptr)
                        temp = temp->next;
                    temp->next = newNode;
                }
                current = current->next;
            }
        }
        delete[] table;
        table = newTable;
    }

public:
    HashTable(int capacity) : size(0), capacity(capacity)
    {
        table = new Node *[capacity] {};
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);
        if (table[index] == nullptr)
            table[index] = newNode;
        else
        {
            Node *current = table[index];
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
        size++;

        if (size >= capacity)
            rehash();
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                    table[index] = current->next;
                else
                    prev->next = current->next;
                delete current;
                size--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int search(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        return -1; // Key not found
    }
};

int main()
{
    HashTable hashTable(10);
    hashTable.insert(5, 42);
    hashTable.insert(15, 24);
    hashTable.insert(25, 99);

    cout << "Value at key 5: " << hashTable.search(5) << endl;
    cout << "Value at key 15: " << hashTable.search(15) << endl;
    cout << "Value at key 25: " << hashTable.search(25) << endl;

    hashTable.remove(15);
    cout << "Value at key 15 after deletion: " << hashTable.search(15) << endl;

    return 0;
}
