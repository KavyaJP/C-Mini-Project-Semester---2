#include <iostream>
using namespace std;
class TicTacToe
{
private:
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char current_turn = 'X';
    bool playing = true;
    int state = 0;
    int input;

public:
    void print_board()
    {
        cout << "Press the Number of the box you want to place the Symbol in" << endl
             << endl;
        cout << "0 | 1 | 2" << endl
             << "---------" << endl
             << "3 | 4 | 5" << endl
             << "---------" << endl
             << "6 | 7 | 8" << endl
             << endl;
        for (int i = 0; i < 9; i++)
        {
            if (i == 1 || i == 2 || i == 4 || i == 5 || i == 7 || i == 8)
            {
                cout << " | ";
            }
            cout << board[i];
            if (i == 2 || i == 5)
            {
                cout << endl;
                cout << "---------" << endl;
            }
        }
        cout << endl;
    };
    int play_move(int index, char move)
    {
        if (index >= 0 && index < 9)
        {
            if (board[index] == ' ')
            {
                board[index] = move;
                return 1;
            }
        }
        return 0;
    };
    int check_win(char move)
    {
        if (
            // Horizontal checks
            (board[0] == move && board[1] == move && board[2] == move) ||
            (board[3] == move && board[4] == move && board[5] == move) ||
            (board[6] == move && board[7] == move && board[8] == move) ||
            // Vertical Checks
            (board[0] == move && board[3] == move && board[6] == move) ||
            (board[1] == move && board[4] == move && board[7] == move) ||
            (board[2] == move && board[5] == move && board[8] == move) ||
            // Diagonal Checks
            (board[0] == move && board[4] == move && board[8] == move) ||
            (board[2] == move && board[4] == move && board[6] == move))
        {
            return 1;
        }
        else
        {
            bool draw = true;
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == ' ')
                {
                    draw = false;
                    break;
                }
            }
            if (draw == true)
            {
                return 2;
            }
        }
        return 0;
    };
    void start()
    {
        while (playing == true)
        {
            print_board();
            cout << "Play your move : " << current_turn << endl;
            cin >> input;
            if (play_move(input, current_turn) == 0)
            {
                cout << "Box already occupied" << endl;
                continue;
            };
            state = check_win(current_turn);
            if (state == 1)
            {
                print_board();
                cout << current_turn << " wins the game!" << endl;
                break;
            }
            else if (state == 2)
            {
                cout << "Draw!" << endl;
                break;
            };
            current_turn = (current_turn == 'X') ? 'O' : 'X';
        };
    };
};
int main()
{
    int choice;
    char again;
    cout << "Welcome to Console Based Game" << endl
         << endl;
label_choice:
    cout << "Press 1 to Play Tic Tac Toe" << endl
         << "Press 2 to Play Guess The Number" << endl
         << "Press 3 to Play Snake Game" << endl
         << "Press 4 to Exit" << endl;
    cout << "Enter Your choice : " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        TicTacToe game;
        game.start();
        return 0;
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    case 4:
    {
        goto label_exit;
        break;
    }
    default:
    {
        cout << "Invalid Choice. Enter Your Choice" << endl;
        goto label_choice;
        break;
    }
    }
    cout << "Enter Y to Play Again : ";
    cin >> again;
    if( again == 'y' || again == 'Y' )
        goto label_choice;
label_exit:
    cout << "Thank You For Playing The Game" << endl
         << "Made by\n23AIML056 - Kavya Prajapati\n23AIML057 - Puja Rachh\n23AIML076 - Dax Virani";
    return 0;
}
