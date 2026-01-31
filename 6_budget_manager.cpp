/*The "Budget Manager":
You are building a small tool to manage Club Funds. 
Write a function called processTransaction that takes three parameters:
1. current_balance (must act as a Reference—changes inside function must update the original variable).
2. amount (integer). 
3. is_fee (boolean, default value = false).
Logic:
● If is_fee is true, deduct amount from balance. 
● If is_fee is false, add amount to balance.
● Twist: If the current_balance becomes negative, do NOT update the balance. Instead, print "Insufficient Funds".
Task: In main(), start with balance = 500. 
Call the function 3 times with different values to demonstrate all scenarios
 (Add money, Pay fee, Fail to pay fee). 
 Print the balance inside main() after every call to prove the reference is working.*/

#include <bits/stdc++.h>
using namespace std;


void processTransaction(int &current_balance, int amount, bool is_fee = false){ 
    //is_fee = false;     can't be declared inside as it will be treated as an extra parameter  
    //is_free will only be true when withdrawing money   
    if (is_fee){
        if (current_balance - amount < 0){//Checking if there's enough balance;deducting results in negative balance 
            cout << "Insufficient Funds" << endl;
        } 
        else{
            current_balance = current_balance - amount;
        }
    } 
    else{
        current_balance= current_balance + amount;
    }
}

int main(){
    int balance = 500; //start with balance = 500.

    processTransaction(balance,400); // deposit 200
    cout << "Balance after adding money: " << balance << endl;

    processTransaction(balance,300,true); // deduct 100
    cout << "Balance after paying fee: " << balance << endl;

    processTransaction(balance,1700,true); // attempt to withdraw too much
    cout << "Balance after failed fee: " << balance << endl;

    return 0;
}
