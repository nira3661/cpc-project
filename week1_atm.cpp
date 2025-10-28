#include <iostream>
using namespace std;

int deposit(int balance, int deposit){
    return balance + deposit;
}

int withdraw(int balance, int withdraw){
    if(withdraw > balance){
        cout << "insufficient balance"<<endl;
        return balance;         // return balance if withdrawal exceeds it  // watch out for this
    }
    else{ 
        return balance - withdraw;
    }
}

int main(){
    int choice;
    cout<< "Options:"<<endl;
    cout<< "1. Deposit"<<endl;
    cout<< "2. Withdraw"<<endl;     
    cout<< "3. Check Balance"<<endl;
    cout<< "4. Exit"<<endl;
    cout<< "Enter your choice: ";
    cin>> choice;

    int balance = 1000; // already had some balance or initial balance

    switch (choice){
        case 1:{
            int depositAmount;
            cout<< "enter the amount you want to deposit:"<<endl;
            cin>> depositAmount;
            cout<< "Your total balance now is: " << deposit(balance, depositAmount) << endl;
            break;
        }
        case 2:{
            int withdrawAmount;
            cout<< "enter the amount you want to withdraw:"<<endl;
            cin>> withdrawAmount;
            cout<< "Your total balance now is: " << withdraw(balance, withdrawAmount) << endl;
            break;
        }
        case 3:{
            cout<< "Your current balance is: " << balance << endl;
            break;
        }
        case 4:{
            cout<< "Exiting the ATM system." << endl;
            break; 
        }
        default:{
            cout<< "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}