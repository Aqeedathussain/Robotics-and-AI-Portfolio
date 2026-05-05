#include<iostream>
using namespace std;

class Bank_M;      // Forward declaration (needed because Acc_holder uses Bank_M)
class transaction; // Forward declaration

class Acc_holder
{
private:
    int acc_no;
    string name;
    double balance;
public:
    friend void process_trans(Acc_holder& a, Bank_M& m, transaction& t);  // Correct declaration
    Acc_holder()
    {
        cout << "Enter the Account Number: ";
        cin >> acc_no;
        cout << "Enter the Account holder name: ";
        cin >> name;
        cout << "Enter the Account Balance: ";
        cin >> balance;
    }
    void output()
    {
        cout << "The Account Number is: " << acc_no << endl;
        cout << "The Account Holder Name is: " << name << endl;
        cout << "The Account Balance is: " << balance << endl;
    }
};

class Bank_M
{
private:
    string M_name;
    int BranchCode;
public:
    friend void process_trans(Acc_holder& a, Bank_M& m, transaction& t);
    void input()
    {
        cout << "Enter the Manager Name: ";
        cin >> M_name;
        cout << "Enter the Branch Code: ";
        cin >> BranchCode;
    }
    void display()
    {
        cout << "The Manager Name is: " << M_name << endl;
        cout << "The Branch Code is: " << BranchCode << endl;
    }
};

class transaction
{
private:
    int T_ID;
    double T_amount;
    string T_type;
public:
    friend void process_trans(Acc_holder& a, Bank_M& m, transaction& t);
    transaction()
    {
        cout << "Enter the Transaction ID: ";
        cin >> T_ID;
        cout << "Enter the Transaction amount: ";
        cin >> T_amount;
        cout << "Enter the Transaction Type: ";
        cin >> T_type;
    }
    void out()
    {
        cout << "The transaction ID is: " << T_ID << endl;
        cout << "The transaction amount is: " << T_amount << endl;
        cout << "The transaction type is: " << T_type << endl;
    }
};

void process_trans(Acc_holder& a, Bank_M& m, transaction& t)
{
    string dep;
    int am;
    int total;

    cout << "Please enter what you want to do (Deposit/Withdraw): ";
    cin >> dep;

    if (dep == "Deposit")
    {
        cout << "Enter the amount you want to deposit: ";
        cin >> am;
        total = a.balance + am;
        cout << "Your total amount after deposit is: " << total << endl;
    }
    else if (dep == "Withdraw")
    {
        cout << "Enter the amount you want to withdraw: ";
        cin >> am;
        if (a.balance >= am)
        {
            total = a.balance - am;
            cout << "Your total amount after withdrawal is: " << total << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    else
    {
        cout << "Invalid operation entered!" << endl;
    }
}

int main()
{
    Acc_holder h;
    Bank_M m;
    m.input();
    transaction s;
    process_trans(h, m, s);
}
