#include <iostream>
#include <string>
using namespace std;
class Account {
public:
    Account(string name, long long accountNumber, double balance) : name(name), accountNumber(accountNumber), balance(balance) {}
    string getName() const { return name; }
    long long getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful! New balance:  ₹" << balance << endl;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! New balance:  ₹" << balance << endl;
        }
    }
    void showBalance() const {
        cout << "Current balance for account " << accountNumber << ":  ₹" << balance << endl;
    }
private:
    string name;
    long accountNumber;
    double balance;
};
int main() {
    string name;
    long accountNumber;
    double balance;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> accountNumber;
    cout << "Enter your account balance: ";
    cin >> balance;
    Account account(name, accountNumber, balance);
    int choice;
    do {
        // Display menu
        cout << "\n--- Bank Account Menu ---" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 3:
                account.showBalance();
                break;
            case 4:
                cout << "Thank you for using the bank account system!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
