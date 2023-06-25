#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cord;

class Ant
{
public:
    int x, y;
};

void FieldCreation(vector<string>& field, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        string line = "";

        for (int j = 0; j < y; j++)
        {
            if (!i || !j || i == x - 1 || j == y - 1) line += '#';
            else line += ' ';
        }

        field.push_back(line);
    }

    return;
}

void FieldOutput(vector<string> field, int x, int y, Ant ant)
{
    cord.X = 0;
    cord.Y = 0;
    SetConsoleCursorPosition(hand, cord);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            field[i][j] == '#' ? SetConsoleTextAttribute(hand, 11) : field[i][j] == '*' ? SetConsoleTextAttribute(hand, 12) : SetConsoleTextAttribute(hand, 15);

            cout << field[i][j];
        }
            
        cout << endl;
    }

    cord.X = ant.x;
    cord.Y = ant.y;
    SetConsoleCursorPosition(hand, cord);

    cout << char(2);

    /*cord.X = 0;
    cord.Y = x + 2;
    SetConsoleCursorPosition(hand, cord);*/

    return;
}

int main()
{
    vector<string> field;
    Ant ant;
    int x, y;

    cin >> x;
    cin >> y;

    ant.x = (y - 2) / 2;
    ant.y = (x - 2) / 2;

    FieldCreation(field, x, y);

    FieldOutput(field, x, y, ant);
}