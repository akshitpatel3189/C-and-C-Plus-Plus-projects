#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount() : balance(0) {}

    void openAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);
        cout << "Account Created Successfully!" << endl;
    }

    void showAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: $";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed." << endl;
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: $";
        cin >> amount;
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount or insufficient balance. Withdrawal failed." << endl;
        }
    }

    bool searchAccount(string accNumber) {
        return accNumber == accountNumber;
    }
};

int main() {
    BankAccount accounts[10];  // Assuming a maximum of 10 accounts

    int choice;
    string searchAccNumber;

    do {
        cout << "\nBank Management System Menu\n";
        cout << "1. Open Account\n";
        cout << "2. Show Account Details\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Search Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                accounts[0].openAccount();  // Open account for now, can be extended to handle multiple accounts
                break;
            case 2:
                accounts[0].showAccountDetails();
                break;
            case 3:
                accounts[0].deposit();
                break;
            case 4:
                accounts[0].withdraw();
                break;
            case 5:
                cout << "Enter Account Number to search: ";
                cin >> searchAccNumber;
                for (int i = 0; i < 10; i++) {
                    if (accounts[i].searchAccount(searchAccNumber)) {
                        cout << "Account found!" << endl;
                        accounts[i].showAccountDetails();
                        break;
                    }
                }
                cout << "Account not found!" << endl;
                break;
            case 6:
                cout << "Exiting Bank Management System. Have a nice day!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
