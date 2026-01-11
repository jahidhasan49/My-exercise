#include<iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    float balance;
public:
    BankAccount() {
        accountNumber = " ";
        balance = 0.0;
    }

    BankAccount(string accnum, float bal) {
        accountNumber = accnum;
        balance = bal;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    float getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance = balance + amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance = balance - amount;

            return true;
        }

        else {
            return false;
        }
    }

    void display() {
        cout << "Accountnumber: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

void transfer(BankAccount &A, BankAccount &B, double amount) {
    if (A.withdraw(amount)) {
        B.deposit(amount);

        cout << "transfer of " << amount;
        cout << " from " << A.getAccountNumber() << " to " << B.getAccountNumber() << " is successful" << endl;
    }
    else {
        cout << "Insufficient balance" << endl;
    }
}

int main() {
    BankAccount A("4848", 5000);
    BankAccount B("8484", 2000);

    cout << "Before transfer: " << endl;
    A.display();
    B.display();

    transfer(A, B, 1500);

    cout << "After transfer: " << endl;
    A.display();
    B.display();

    return 0;

}
