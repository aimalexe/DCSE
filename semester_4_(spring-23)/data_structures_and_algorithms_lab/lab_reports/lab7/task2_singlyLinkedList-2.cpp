/*
Task 2: Implement a single linked list with following operations
            a) Insert at start of the list (preappend data)
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

template <typename generic>
struct Node
{
    generic data;   //Some Data;
    Node* nextNode; // Pointer to next node.
};

template <typename generic>
class LinkedList{
    private:
        Node<generic>* head;
        Node<generic>* tail;

    public:
        LinkedList(): head(nullptr), tail(nullptr){}

        void addToStart(generic value){
            Node<generic>* newNode = new Node<generic>;
            newNode -> data = value;
            newNode -> nextNode = nullptr;

            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                newNode -> nextNode = head;
                head = newNode; 
            }
        }

        void addAt(int index, generic value){
            if(index <= 0 ){
                cout<<"Index out of bound.\n";
                return;
            }
            Node<generic>* newNode = new Node<generic>;
            newNode -> data = value;

            if(index == 1){
                newNode -> nextNode = head;
                head = newNode;
                return;
            }

            Node<generic>* current = head;
            for(int i = 1; i < index - 1 && current != nullptr; i++)
                current = current -> nextNode;
            
            if (current == nullptr) {  // n is greater than the size of the list
                cout << "Position " << index << " is out of range." << endl;
                delete newNode;  // Free the memory allocated for the new node
                return;
            }

            newNode -> nextNode = current -> nextNode;
            current -> nextNode = newNode;
        }

        void addToLast(generic value){
            Node<generic>* newNode = new Node<generic>;
            newNode -> data = value;
            newNode -> nextNode = nullptr;

            if(head == nullptr){    //Empty list
                head = newNode;
                tail = newNode;
            }
            else{   //Not empty List.
                tail -> nextNode = newNode;
                tail = newNode;
            }
        }

        void printList(){
            Node<generic>* current = head;
            cout<<"List: ";
            while(current != nullptr){
                cout<<current -> data << " ==> ";
                current = current -> nextNode;
            }
            cout<<endl;
        }
        
        void deleteFirstNode(){
            if(head == nullptr)
                return;
            Node<generic>* firstNode = head;
            head = head -> nextNode;
            delete firstNode;
        }

        void deleteLastNode(){
            if(head == nullptr) // Empty List
                return;
            else if(head -> nextNode == nullptr){   // One Node only.
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            else{
                Node<generic>* current = head;
                while(current -> nextNode -> nextNode != nullptr)
                    current = current -> nextNode;
                Node<generic>* lastNode = current -> nextNode;
                
                current -> nextNode = nullptr;
                delete lastNode;
                tail = current;
            }

        }

        void searchFor(generic key){
            if(head == nullptr){
                cout<<"List is Empty. Cannot search key in empty list.\n";
                return;
            }
            Node<generic>* current = head;
            while(current != nullptr){
                if(current -> data == key){
                    cout<<key <<" is present in list.\n";
                    return;
                }
                current = current -> nextNode;
            }
            cout<<key <<" is not found in list.\n";

        }

        void updateNode(generic key, generic newValue) {
            Node<generic>* current = head;
            while (current != nullptr) {
                if (current->data == key) {  // Key found
                    current->data = newValue;  // Update the value of the node
                    return;
                }
                current = current->nextNode;
            }
            cout << "Key " << key << " not found." << endl;  // Key not found
        }

        bool isEmptyList(){
            return head == nullptr;
        }

        void clearList(){
            if(isEmptyList()) return;

            Node<generic>* current = head;
            Node<generic>* temp = new Node<generic>;
            while(current != nullptr){
                temp = current;
                current = current -> nextNode;
                delete temp;
            }
            head = tail = nullptr;
        }
        
        int sizeOfList() {
            int count = 0;
            Node<generic>* current = head;
            while (current != nullptr) {
                count++;
                current = current->nextNode;
            }
            return count;
        }

};

//Driver Program.
int main(){
    LinkedList<int> list;

    list.addToStart(1);
    list.addToStart(2);

    list.addToLast(10);
    list.addToLast(11);
    list.addToLast(12);

    list.addAt(3, 3);

    list.printList();
    cout<<"List size is:"<<list.sizeOfList()<<endl;

    list.deleteFirstNode();
    list.deleteFirstNode();

    list.addToStart(0);
    list.addAt(6, 13);
    list.printList();

    list.deleteLastNode();

    list.printList();
    list.searchFor(10);
    list.searchFor(76);

    cout<<"Is List is empty? "<<boolalpha<< list.isEmptyList()<<endl;
    list.clearList();
    cout<<"Is List is empty? "<<boolalpha<<list.isEmptyList()<<endl;
    list.printList();
    cout<<"List size is:"<<list.sizeOfList()<<endl;

    return 0;
}

// Coded with ❤ by Aimal Khan.