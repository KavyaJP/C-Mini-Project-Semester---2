#include <iostream>
#include <cstdlib>
using namespace std;

class Game
{
public:
    int num1;
    int n;
    Game()
    {
        num1 = 1 + (rand() % 100);
    }
    void takeUserInput()
    {
        cout << "Guess the number" << endl;
        cin >> n;
    }
    bool isCorrect()
    {
        if (n == num1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    bool b = false;
    Game g;
    int count = 0;
    while (b != true)
    {
        g.takeUserInput();
        if (g.n < g.num1)
        {
            cout << "Too small try again" << endl;
        }
        if (g.n > g.num1)
        {
            cout << "Too large try again" << endl;
        }
        b = g.isCorrect();
        count++;
    }
    cout << "\n\n Congrats You won!!\n No. of guesses are:" << count << endl;
    return 0;
}
