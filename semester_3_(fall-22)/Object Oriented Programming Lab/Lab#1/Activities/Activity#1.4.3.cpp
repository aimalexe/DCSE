/*
Create a class called BankAccount that models a checking account at a bank. The program creates an
account with an opening balance, displays the balance, makes a deposit and a withdrawal, and then
displays the new balance. Note in withdrawal function, if balance is below Rs. 500 then display message
showing insufficient balance otherwise allow withdrawal.
*/
#include <iostream>
using namespace std;

class BankAccount{
    private:
        int balance;
    public:
        //Constructing initially to 1000:
        BankAccount():balance(1000) {}
        void deposit(int d){
            balance += d;
        }
        void withdrawl(int w){
            if (balance <= 500)
                cout << "\n\t**Insufficient Balance**" ;
            else
                balance -= w;
        }
        void show(){
            cout << "\nCurrent Balance:\t" << balance ;
        }
};

int main(){
    BankAccount b1;
    b1.show();
    b1.deposit(500);
    b1.show();
    b1.withdrawl(500);
    b1.show();
    b1.withdrawl(500);
    b1.show();
    b1.withdrawl(500);
    b1.show();

    return 0;
}
