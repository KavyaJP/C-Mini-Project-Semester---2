#include <iostream>
using namespace std;
void printgrid(char[3][3]);
int main()
{
    int choice1, choice2;
    char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    cout << "(1) Start The Game" << endl
         << "(2) Basic Rules" << endl
         << "(3) Exit The Game" << endl;
label_choice1:
    cin >> choice1;
    switch (choice1)
    {
    case 1:
        cout << "Welcome to Tic Tac Toe" << endl;
        cout << "(1) Human Vs Human" << endl
             << "(2) Human Vs Computer" << endl;
    label_choice2:
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            cout << endl
                 << endl
                 << "----------------" << endl
                 << "|              |" << endl
                 << "|Human Vs Human|" << endl
                 << "|              |" << endl
                 << "----------------" << endl
                 << endl;
            printgrid(a);
            break;
        case 2:
            cout << endl
                 << endl
                 << "----------------" << endl
                 << "|              |" << endl
                 << "|Human Vs Human|" << endl
                 << "|              |" << endl
                 << "----------------" << endl
                 << endl;

            break;
        default:
            cout << "Invalid choice, Enter Your Choice Again : " << endl;
            goto label_choice2;
            break;
        }
        break;
    case 2:
        cout << endl
             << endl
             << "Tic Tac Toe Rules" << endl;
        break;
    case 3:
        break;
    default:
        cout << "Invalid choice, Enter Your Choice Again : " << endl;
        goto label_choice1;
        break;
    }
}
void printgrid(char a[3][3])
{
    cout << "------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "  ";
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << "  |  ";
        }
        cout << endl;
        cout << "------------------" << endl;
    }
}