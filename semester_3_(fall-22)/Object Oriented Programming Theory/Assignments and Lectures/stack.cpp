//  Aimal Khan.

#include <iostream>
using namespace std;

const int MAX = 50;

template <class anyType = int>
class Stack{
    private:
        anyType st[MAX];
        int top;

    public:
        Stack(){
            top = -1;
        }
        void push(anyType var){
            st[++top] = var;
        }
        anyType pop(){
            return st[--top];
        }
};

int main(){
    Stack<> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "1: "<< s.pop() << endl;
    cout << "2: "<< s.pop() << endl;
    cout << "3: "<< s.pop() << endl;

    Stack<float> f;
    f.push(1.234);
    f.push(2.33);
    f.push(3.3465);

    cout << "1: "<< f.pop() << endl;
    cout << "2: "<< f.pop() << endl;
    cout << "3: "<< f.pop() << endl;

    return 0;
    //Refactor and Debugged by: Aimal Khan
}
