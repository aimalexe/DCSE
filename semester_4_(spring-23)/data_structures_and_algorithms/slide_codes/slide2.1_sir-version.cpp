//Aimal Khan.
#include <iostream>
using namespace std;

template <typename Type>
class Node{
    private:
        Type element;   //Data of any type
        Node *next;     // Pointer to next node.
    public:
        Node( const Type& = Type(), Node* = nullptr ); //constructor.
        Type retrieve() const;
        Node *next() const;
};

template <typename Type>
class List{
    private:
        Node<Type> *head; //Pointer to head
        Node<Type> *tail;   //Pointer to tail

        static int count;   //Count of nodes in list.

    public:
        //constructors
        //Accessors
        //Mutators

};

int main(){

    return 0;
}