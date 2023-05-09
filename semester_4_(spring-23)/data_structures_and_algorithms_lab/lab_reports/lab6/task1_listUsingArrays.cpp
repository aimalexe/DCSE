/*
Task 1:
Implement LIST using arrays. It should perform following operations
• Create (Creates LIST)
• Add (Adds item to the LIST at given index)
• Remove (Removes item from the List at provided index)
• waSize (Determines Size of the LIST)
• IsEmpty (Determines if LIST is empty or not)
• Get (Retrieves an Item from the LIST)
• End (Returns end of the LIST)
• Start (Return start of the LIST)
*/

#include <iostream>
using namespace std;

const int maxSize = 100;

//A Generic List class.
template <class Type>
class List{
    private:
        Type array[maxSize];
        int length;

    public:
    List(){ createList(); }

    void createList(){
        length = 0;
    }

    void displayList(){
        cout<<"List: { ";
        if(length == 0)
            cout<<"";
        else
            for(int i = 0; i < length; i++)
                cout<< array[i] << ", ";
        cout<<"}\n";
    }

    void addItem(Type element, int atIndex){
        if(atIndex < 0 || atIndex >= maxSize){
            cout<<"Err: Index is out of bound\n";
            return;
        }
        if(length >= maxSize){
            cout<<"Err: List is already full.\n";
            return;
        }
        for(int i = length; i >= atIndex; i--){
            array[i + 1] = array[i];
        }
        array[atIndex] = element;
        length++;
    }

    void removeItem(int fromIndex){
        if(fromIndex < 0 || fromIndex >= maxSize){
            cout<<"Err: Index is out of bound\n";
            return;
        }
        if(fromIndex >= length){
            cout<<"Err: Cannot remove from empty index.\n";
            return;
        }
        for(int i = fromIndex; i <= length ; i++){
            array[i] = array[i + 1];
        }
        length--;
    }

    int arraySize(){
        return length;
    }

    bool isEmptyList(){
        return length==0? true : false;
    }

    Type getElement(int fromIndex){
        if(fromIndex < 0 || fromIndex >= maxSize){
            cout<<"Err: Index is out of bound\n";
            return -1;
        }
        if(fromIndex >= length){
            cout<<"Err: Cannot retrieve element from empty index.\n";
            return -1;
        }
        return array[fromIndex];
    }

    Type endOfList(){
        if(length == 0){
            cout<<"List is Empty"
            return -1;
        }
        return array[length - 1];
    }

    Type startOfList(){
        if(length == 0){
            cout<<"List is Empty"
            return -1;
        }
        return array[0];
    }
};

//Driver Program
int main(){
    List<int> l;
    l.displayList();
    l.addItem(1996.9, 0);
    l.addItem(2003, 1);
    l.addItem(2005, 2);
    l.displayList();
    l.addItem(2023, 1);
    l.displayList();
    l.removeItem(0);
    l.displayList();

    cout<<"Size of List is: "<< l.arraySize()<<endl;
    cout<<"Is set empty? "<<l.isEmptyList()<<endl;
    
    int ele = l.getElement(5);
    cout<<ele<<endl;

    int eol = l.endOfList();
    cout<<"End of List is: "<<eol<<endl;

    int sol = l.startOfList();
    cout<<"Start of list is: "<<sol<<endl;

    return 0;
}
// Aimal Khan.