#include <iostream>
using namespace std;

int main()
{
    int choice;
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
label_exit:
    cout << "Thank You For Playing The Game" << endl
         << "Made by\n23AIML056 - Kavya Prajapati\n23AIML057 - Puja Rachh\n23AIML076 - Dax Virani";
    return 0;
}