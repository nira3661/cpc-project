/*1. You are FORBIDDEN from writing using namespace std; anywhere in the code. 
2. You are FORBIDDEN from writing std:: inside the main() function. 
3. The Twist: You must use the using keyword only for the specific tools you need (like cout and endl),
    placed before main().*/

#include <iostream>

/*namespace ronen{
    void print(const char* line){
        std::cout<<line<< std::endl;
    }
}


int main(){
    ronen::print("We are the best club!");
    

}*/


namespace ronen{
    using std::cout;
    using std::endl;
}
using namespace ronen;

int main(){
    cout << "We are the best club!" <<endl;
    return 0;
}
