//Aimal Khan

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private:
        Node* first;

    public:
        LinkedList(): first(nullptr) {}
        void addItemToList (int da){
            Node* newNode = new Node;
            newNode->data = da;
            newNode->next = first;
            first = newNode;
        }
        void displayList()const{
            Node* current = first;
            cout<<".|";
            while(current != nullptr ){
                cout<< " --> "<< current->data;
                current = current->next;
            }
            cout<<" |.\n";
        }
};

int main (){
    LinkedList li1;
    li1.addItemToList(1);
    li1.addItemToList(2);
    li1.addItemToList(4);
    li1.addItemToList(12);

    li1.displayList();


    return 0;
}
