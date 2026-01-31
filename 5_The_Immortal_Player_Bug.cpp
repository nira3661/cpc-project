/*The Problem: There is a bug! When the enemy hits the player, the function subtractshealth, but back in the main game loop, the player's health goes right back to 100. The player is accidentally "immortal."
Your Job: Fix the code by using a Reference Variable (&). Requirements:
1. Create a variable in main() called playerHP and set it to 100. 
2. Write a function called takeDamage. It should accept two inputs: ○ health (This must be a Reference to the real variable). ○ damage (An integer).
3. Inside the function, subtract damage from health. 
4. In main(), call the function to deal 30 damage, then call it again to deal 20 damage.
5. Print the final HP. ○ Fail: If it prints 100 or 80. ○ Pass: If it prints 50 (because 100 - 30 - 20 = 50).
*/

#include <bits/stdc++.h>
using namespace std;

void takeDamage(int &health, int damage){
    health = health - damage; 
}

int main(){
    int player_HP = 100;
    takeDamage(player_HP,30); 
    takeDamage(player_HP,20); 

    cout<< "Current HP: " << player_HP <<endl;
    return 0;
}