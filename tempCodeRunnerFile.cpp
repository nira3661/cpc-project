#include <bits/stdc++.h>

using namespace std;

int main(){
    cout << "which number do you want multiplication table for: ";
    int n;
    cin >> n;
    for(int i = 1; i<=10; ++i){
        cout << n << "*"<< i << " = "<< n*i << "\n";
    }
    return 0;
}