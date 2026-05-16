#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    int random_number = rand() % 100 + 1;
    cout << "----- NUMBER GUESSING GAME -----\n";
    cout << "I've picked a random number between 1 and 100.\n";
    cout << "Try to find it in minimum guesses.!\n";
    int user_guess;
    int guess_count = 0;
    do{
        cout<<"\nEnter your number : ";
        cin>>user_guess;
        guess_count++;
        if(user_guess < 1 || user_guess > 100) {
            cout << "Please enter a number between 1 and 100.\n";
        }
        else if(user_guess > random_number){
            cout << "Too high! Aim a little lower.\n";
        }
        else if(user_guess < random_number){
            cout << "Too low! Shoot a little higher.\n";
        }
        else{
            cout << "\nCONGRATULATIONS! You nailed it! The number was " << random_number << "!\n";
            cout << "Total number of attempts : "<<guess_count<<"\n";
        }
        
    }while(user_guess != random_number);
}
