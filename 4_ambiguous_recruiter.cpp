/*void registerMember(int id) {
cout << "Member ID: " << id << endl;
} 
void registerMember(int &id) { 
cout << "Reference ID: " << id << endl;
} 
int main() { 
int x = 10; 
registerMember(x); // Line A 
registerMember(20); // Line B 
return 0;
}

here in line A, x is an lvalue so it can call both functions(id and &id). That's where the ambiguity lies.
*/
#include <bits/stdc++.h>
using namespace std;

void registerMember(int &id) {          // lvalue reference
    cout << "Member ID: " << id << endl;
}

void registerMember(int &&id) {         // rvalue reference
    cout << "Reference ID: " << id << endl;
}

int main() {
    int x = 10;
    registerMember(x);   /*line A calls &id cause x is an lvalue which deals with existing variables directly
                        lvalue (locator value) An object that has a name and a memory location you can take the address of.*/

    registerMember(20);  /*line B...&&id...rvalue....temporaries efficiently
                        rvalue(read value) A temporary value that doesn’t have a persistent memory location.*/


    return 0;
}