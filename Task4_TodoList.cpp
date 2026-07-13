#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void displayBoard()
{
    cout << "\n";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
}

void makeMove()
{
    int choice;
    cout << "Player " << player << ", Enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = player;
    else
    {
        cout << "Position already taken!\n";
        makeMove();
    }
}

bool checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;

        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

int main()
{
    int moves=0;

    while(true)
    {
        displayBoard();
        makeMove();
        moves++;

        if(checkWin())
        {
            displayBoard();
            cout<<"Player "<<player<<" Wins!"<<endl;
            break;
        }

        if(moves==9)
        {
            displayBoard();
            cout<<"Match Draw!"<<endl;
            break;
        }

        player=(player=='X')?'O':'X';
    }

    return 0;
}