#include <iostream>
using namespace std;

class BankAccount {
private:
    double bal;

public:
    BankAccount() {
        bal = 0.0;
    }

    BankAccount(double initialBal) {
        bal = initialBal;
    }

    BankAccount(const BankAccount& obj) {
        bal = obj.bal;
    }

    void withdraw(double amount) {
        if (amount <= bal) {
            bal -= amount; } 
        else {
            cout << "Insufficient balance" << endl; }
    }

    void displayBalance() {
        cout << "Balance: Rs. " << bal << endl;
    }
};

int main() {
    BankAccount account1;
    cout << "Account1 "; 
    account1.displayBalance();
    BankAccount account2(1000.0);
    cout << "Account2 ";
    account2.displayBalance();
    BankAccount account3(account2);
    account3.withdraw(200);
    cout << "Account3 ";
    account3.displayBalance();
    cout << "Account2 ";
    account2.displayBalance();
    return 0;
}
