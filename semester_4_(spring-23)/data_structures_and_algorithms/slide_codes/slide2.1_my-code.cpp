// Aimal Khan.
#include <iostream>
using namespace std;

//Generic class for making nodes.
template <typename Type>
class Node {
    private:
        Type element;   // Data of any type
        Node* next;     // Pointer to next node

    public:
        Node(const Type& elem = Type(), Node* n = nullptr) : element(elem), next(n) {} // Constructor
        
        // Accessor to retrieve element
        Type retrieve() const {
            return element;
        }

        // Accessor to retrieve next node
        Node* getNext() const {
            return next;
        }

        // Mutator to set next node
        void setNext(Node* n) {
            next = n;
        }
};

//Generic Class for making linked lists.
template <typename Type>
class List {
    private:
        Node<Type>* head;   // Pointer to head
        Node<Type>* tail;   // Pointer to tail
        int count;   // Count of nodes in list

    public:
        // Default constructor
        List() : head(nullptr), tail(nullptr), count(0) {}
        
        // Check if the list is empty
        bool isEmpty() const{
            return head == nullptr;
        }

        // Destructor
        ~List(){
            while (!isEmpty()) {
                Node<Type>* temp = head;
                head = head->getNext();
                delete temp;
                --count;
            }
        }
        
        // Return the count of nodes in list
        int size() const {
            return count;
        }
        
        // Insert an element at the end of the list
        void insert(const Type& elem){
            Node<Type>* newNode = new Node<Type>(elem, nullptr);
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->setNext(newNode);
                tail = newNode;
            }
            ++count;
        }

         // Remove an element from the list
        void remove(const Type& elem){
            if (isEmpty()) {
                cout << "List is empty. Cannot remove element." << endl;
                return;
            }
            Node<Type>* temp = head;
            if (head->retrieve() == elem) {
                head = head->getNext();
                delete temp;
                --count;
                return;
            }
            Node<Type>* prev = nullptr;
            while (temp != nullptr && temp->retrieve() != elem) {
                prev = temp;
                temp = temp->getNext();
            }
            if (temp == nullptr) {
                cout << "Element not found in the list." << endl;
                return;
            }
            prev->setNext(temp->getNext());
            if (temp == tail) {
                tail = prev;
            }
            delete temp;
            --count;
        }

         // Display the elements in the list
        void display() const{
            if (isEmpty()) {
                cout << "List is empty." << endl;
                return;
            }
            Node<Type>* temp = head;
            while (temp != nullptr) {
                cout << temp->retrieve() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
};

//Driver program
int main() {
    List<int> myList;
    cout << "List is empty: " << boolalpha << myList.isEmpty() << endl;
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);
    myList.insert(50);
    myList.display();
    int nodes = myList.size();
    cout<<"count: "<<nodes<<endl;

    myList.remove(30);
    myList.display();
    nodes = myList.size();
    cout<<"count: "<<nodes<<endl;
    
    return 0;
}