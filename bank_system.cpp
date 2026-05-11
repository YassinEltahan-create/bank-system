#include <iostream>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;
    int pin;

public:
    void createAccount() {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Set PIN: ";
        cin >> pin;

        balance = 0;

        cout << "Account created successfully!\n";
    }

    bool login() {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            return true;
        } else {
            cout << "Wrong PIN!\n";
            return false;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance += amount;
        cout << "Money added. New balance: " << balance << endl;
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Not enough balance!\n";
        } else {
            balance -= amount;
            cout << "Withdraw successful. Remaining balance: " << balance << endl;
        }
    }

    void showBalance() {
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    BankAccount user;
    int choice;

    user.createAccount();

    if (!user.login()) {
        return 0;
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Balance\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user.deposit();
                break;
            case 2:
                user.withdraw();
                break;
            case 3:
                user.showBalance();
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}