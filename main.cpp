//Program to emulate transactions in and out of a bank account
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Chequebook
{
public:
    Chequebook();
    //Default Constructor to initialize balance to 0
    Chequebook(float AccountBalance);
    //Constructor to initialize balance to specified amount
    void Deposit(float Amount);
    //Function to add specified amount to balance
    void WithDraw(float Amount);
    //Function to remove specified amount from balance
    float CurrentBalance() const;
    //Function to return current balance
    void Adjust();
    //Function to increment balance by R100

    //void operator ++();

    friend ostream& operator << (ostream& outStream, Chequebook& accountP);
    //Overloads << operator to output balance to specified stream
    friend void operator ++(Chequebook& accountP);
    //Friend function to overload ++ to operate as adjust.

private:
    float Balance;
};

//friend function definitions

ostream& operator << (ostream& outStream, Chequebook& accountP)
{
    cout << accountP.Balance;
}

void operator ++(Chequebook& accountP)
{
    accountP.Balance = accountP.Balance + 100;
}

//void operator ++(Chequebook& accountP)
//{
    //accountP.Adjust();
//}

int main()
{
    cout << "Enter The Account Balance: R ";
    float amount;
    cin >> amount;

    Chequebook Chequebook1(amount);

    cout << "Account balance: R " << Chequebook1 << endl;

    cout << "Enter amount to deposit: ";
    cin >> amount;
    Chequebook1.Deposit(amount);
    cout << "Balance after deposit: R " << Chequebook1 << endl;

    cout << "Enter amount to withdraw: ";
    cin >> amount;
    Chequebook1.WithDraw(amount);
    cout << "Balance after withdrawal is R " << Chequebook1 << endl;

    ++Chequebook1;
    cout << "Balance after adjusting: R " << Chequebook1;

    return 0;

}

//Class Definitions

Chequebook::Chequebook():Balance(0)
{

}
Chequebook::Chequebook(float AccountBalance)
{
    Balance = AccountBalance;
}

void Chequebook::Deposit(float Amount)
{
    Balance = Balance + Amount;
}

void Chequebook::WithDraw(float Amount)
{
    Balance = Balance - Amount;
}

float Chequebook::CurrentBalance() const
{
    return Balance;
}

void Chequebook::Adjust()
{
    Balance = Balance + 100;
}

//void Chequebook::operator ++()
//{
    //Balance = Balance + 100;
//}
