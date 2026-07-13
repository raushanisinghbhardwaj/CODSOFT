#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int secret = rand() % 100 + 1;
    int guess;

    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    while(guess != secret)
    {
        if(guess > secret)
        {
            cout << "Too High!" << endl;
        }
        else 
        {
            cout << "Too Low!" << endl;
        }

        cout << "Guess again: ";
        cin >> guess;
    }

    cout << "Congratulations! You guessed the correct number.";

    return 0;
}
