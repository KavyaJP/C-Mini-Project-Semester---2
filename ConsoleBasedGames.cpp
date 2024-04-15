#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
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
#define max_length 1000

// Directions
const char dir_up = 'U';
const char dir_down = 'D';
const char dir_left = 'L';
const char dir_right = 'R';

int consoleWidth, consoleHeight;

void initScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

struct Point
{
    int xCoord;
    int yCoord;
    Point()
    {
    }
    Point(int x, int y)
    {
        xCoord = x;
        yCoord = y;
    }
};
class Snake
{
    int length;
    char direction;

public:
    Point body[max_length];
    Snake(int x, int y)
    {
        length = 1;
        body[0] = Point(x, y);
        direction = dir_right;
    }

    int getLength()
    {
        return length;
    }

    void changeDirection(char newDirection)
    {
        if (newDirection == dir_up && direction != dir_down)
        {
            direction = newDirection;
        }
        else if (newDirection == dir_down && direction != dir_up)
        {
            direction = newDirection;
        }
        else if (newDirection == dir_left && direction != dir_right)
        {
            direction = newDirection;
        }
        else if (newDirection == dir_right && direction != dir_left)
        {
            direction = newDirection;
        }
    }
    bool move(Point food)
    {
        for (int i = length - 1; i > 0; i--) // lenght = 4
        {
            body[i] = body[i - 1];
        }
        switch (direction)
        {
            int val;
        case dir_up:
            val = body[0].yCoord;
            body[0].yCoord = val - 1;
            break;
        case dir_down:
            val = body[0].yCoord;
            body[0].yCoord = val + 1;
            break;
        case dir_right:
            val = body[0].xCoord;
            body[0].xCoord = val + 1;
            break;
        case dir_left:
            val = body[0].xCoord;
            body[0].xCoord = val - 1;
            break;
        }
        // snake bites itself
        for (int i = 1; i < length; i++)
        {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord)
            {
                return false;
            }
        }
        // snake eats food
        if (food.xCoord == body[0].xCoord && food.yCoord == body[0].yCoord)
        {
            body[length] = Point(body[length - 1].xCoord, body[length - 1].yCoord);
            length++;
        }
        return true;
    }
};
class Board
{
    Snake *snake;
    const char snake_body = 'O';
    Point food;
    const char FOOD = 'o';
    int score;

public:
    Board()
    {
        spawnFood();
        snake = new Snake(10, 10);
        score = 0;
    }
    ~Board()
    {
        delete snake;
    }
    int getScore()
    {
        return score;
    }
    void spawnFood()
    {
        int x = rand() % consoleWidth;
        int y = rand() % consoleHeight;
        food = Point(x, y);
    }
    void displayCurrentScore()
    {
        gotoxy(consoleWidth / 2, 0);
        cout << "Current Score : " << score;
    }
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    void draw()
    {
        system("cls");
        for (int i = 0; i < snake->getLength(); i++)
        {
            gotoxy(snake->body[i].xCoord, snake->body[i].yCoord);
            cout << snake_body;
        }
        gotoxy(food.xCoord, food.yCoord);
        cout << FOOD;
        displayCurrentScore();
    }
    bool update()
    {
        bool isAlive = snake->move(food);
        if (isAlive == false)
        {
            return false;
        }
        if (food.xCoord == snake->body[0].xCoord && food.yCoord == snake->body[0].yCoord)
        {
            score++;
            spawnFood();
        }
        return true;
    }
    void getInput()
    {
        if (kbhit())
        {
            int key = getch();
            if (key == 'w' || key == 'W')
            {
                snake->changeDirection(dir_up);
            }
            else if (key == 'a' || key == 'A')
            {
                snake->changeDirection(dir_left);
            }
            else if (key == 's' || key == 'S')
            {
                snake->changeDirection(dir_down);
            }
            else if (key == 'd' || key == 'D')
            {
                snake->changeDirection(dir_right);
            }
        }
    }
};

class Game
{
public:
    int num1;
    int n;

    Game()
    {
        // Generates different number every time we run the program
        srand(time(0));
        // Generates a random number between 0 and 100
        num1 = 1 + (rand() % 100);
    }
    void takeUserInput()
    {
        cout << "Guess the number between 1 to 100" << endl;
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
    int choice;
    char again;
    cout << "Welcome to Console Based Game" << endl
         << endl;
label_choice:
    cout << "Press 1 to Play Tic Tac Toe" << endl
         << "Press 2 to Play Snake Game" << endl
         << "Press 3 to Play Guess The Number" << endl
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
        srand(time(0));
        initScreen();
        Board *board = new Board();
        char learn_controls;
        cout << "Enter Y to learn Controls, Any other character to start playing : ";
        cin >> learn_controls;
        if (learn_controls == 'Y' || learn_controls == 'y')
        {
            cout << "W for up\nS for down\nA for Left\nD for Right\n"
                 << endl;
            while (1)
            {
                int exit;
                cout << "Press 1 to Play : ";
                cin >> exit;
                if (exit == 1)
                    break;
            }
        }
        while (board->update())
        {
            board->getInput();
            board->draw();
            Sleep(100);
        }
        cout << "Game over" << endl;
        cout << "Final score is :" << board->getScore();
        break;
    }
    case 3:
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
            // counts number of guesses
            count++;
        }
        cout << "\n\n Congrats You won!!\n No. of guesses are:" << count << endl;
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
    if (again == 'y' || again == 'Y')
        goto label_choice;
label_exit:
    cout << "Thank You For Playing The Game" << endl
         << "Made by\n23AIML056 - Kavya Prajapati\n23AIML057 - Puja Rachchh\n23AIML076 - Dax Virani";
    return 0;
}
