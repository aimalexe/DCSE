'''
Create a class called BankAccount that models a checking account at a bank. The program creates an
account with an opening balance, displays the balance, makes a deposit and a withdrawal, and then
displays the new balance. Note in withdrawal function, if balance is below Rs. 500 then display message
showing insufficient balance otherwise allow withdrawal.
'''
class BankAccount:
    def __init__(self, a = 1000):
        self.balance = a

    def deposit(self, d):
        self.balance += d

    def withdrawal(self, w):
        if (self.balance <= 500):
            print("\t**Insufficient Balance**") ;
        else:
            self.balance -= w

    def show(self):
        print("Current Balance:\t", self.balance)

b1 = BankAccount()
b1.show()
b1.deposit(500)
b1.show()
b1.withdrawal(500)
b1.show()
b1.withdrawal(500)
b1.show()
b1.withdrawal(500)
b1.show()