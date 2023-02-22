#include <iostream>
using namespace std;

const int MAX = 20;

class IntegerSet {
    private:
        int st[MAX];

    public:
        // No-argument constructor that initializes the set to empty
        IntegerSet() {
            for (int i = 0; i < MAX; i++)
                st[i] = 0;
        }
        // Function to add a value in the set
        void insertElement(int value) {
            st[value] = 1;
        }
        // Function to remove a member from the set
        void deleteValue(int value) {
            st[value] = 0;
        }
        // Overloaded operator + function to find the union of two sets
        IntegerSet operator+(const IntegerSet& other) {
            IntegerSet result;
            for (int i = 0; i < MAX; i++)
                if (st[i] == 1 || other.st[i] == 1)
                    result.insertElement(i);
            return result;
        }
        // Overloaded operator * function to find the intersection of two sets
        IntegerSet operator*(const IntegerSet& other) {
            IntegerSet result;
            for (int i = 0; i < MAX; i++)
                if (st[i] == 1 && other.st[i] == 1)
                    result.insertElement(i);
            return result;
        }
        // Overloaded operator ~ function to find the complement of a set
        IntegerSet operator~() {
            IntegerSet result;
            for (int i = 0; i < MAX; i++)
                if (st[i] == 0)
                    result.insertElement(i);
            return result;
        }
        // Function to display the contents of a set
        void display() {
            cout <<"{ ";
            for (int i = 0; i < MAX; i++)
                if (st[i] == 1)
                    cout << i << ", ";
            cout << "\b\b }\n";
        }
};


int main(){
    IntegerSet s, t;


    s.insertElement(2);
    s.insertElement(5);
    s.insertElement(7);
    s.insertElement(3);
    s.insertElement(18);
    s.insertElement(16);
    cout<< "Set s: ";s.display();

    s.deleteValue(2);
    s.deleteValue(8);
    cout<< "After Deleting 2 and 8, s: ";s.display();

    t.insertElement(3);
    t.insertElement(5);
    t.insertElement(7);
    t.insertElement(13);
    cout<< "\nSet t: ";t.display();

    t.deleteValue(3);
    cout<< "After Deleting 3, t: ";t.display();


    IntegerSet u = s + t;
    cout<< "\nUnion of s and t: ";u.display();

    IntegerSet i = s * t;
    cout<< "\nIntersection of s and t: ";i.display();

    IntegerSet inv = ~u;
    cout<< "\nComplement of Union of s and t: ";inv.display();

    return 0;
}
