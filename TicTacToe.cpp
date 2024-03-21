#include <iostream>
using namespace std;
void printgrid(char[3][3]);
int main()
{
    char a[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    printgrid(a);
    int choice;
    cout << "(1) Human Vs Human" << endl
         << "(2) Human Vs Computer" << endl;
label_choice:
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    default:
        cout << "Invalid choice, Enter Your Choice Again : " << endl;
        goto label_choice;
        break;
    }
}
void printgrid(char a[3][3])
{
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