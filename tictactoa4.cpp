#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int x, y;
char arr[3][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'}, {'\0', '\0', '\0'}};
int counter = 0;
char first, second;

void maze();
void xy(int x, int y);
bool checkResult();
void checkbox(int boxnum);

void xy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

bool checkResult()
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] != '\0' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return true;
        if (arr[0][i] != '\0' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
            return true;
    }
    if (arr[0][0] != '\0' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return true;
    if (arr[0][2] != '\0' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return true;

    return false;
}

void checkbox(int boxnum)
{
    int row = (boxnum - 1) / 3;
    int col = (boxnum - 1) % 3;
    if (arr[row][col] == '\0')
    {
        x = 5 + col * 11;
        y = 2 + row * 4;
        xy(x, y);

        char symbol = (counter % 2 == 0) ? first : second;
        arr[row][col] = symbol;
        cout << symbol;

        if (checkResult())
        {
            xy(0, 15);
            cout << "Player " << ((counter % 2 == 0) ? "1" : "2") << " (" << symbol << ") wins!\n";
            exit(0);
        }

        counter++;
    }
    else
    {
        xy(0, 15);
        cout << "Box already filled! Choose another.\n";
    }
}

void maze()
{
    cout << "################################## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "################################## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "################################## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "##        #           #         ## " << endl
         << "################################## " << endl;
}

int main()
{
    system("cls");
    cout << "Choose representation characters:\n";
    cout << "Player 1 (First character): ";
    cin >> first;
    cout << "Player 2 (Second character): ";
    cin >> second;

    cout << "Game starting...\n";
    Sleep(1000);
    system("cls");
    maze();

    while (true)
    {
        int boxnum;
        xy(0, 15);
        cout << "Player   (" << ((counter % 2 == 0) ? first : second) << "), enter box number (1-9): ";
        cin >> boxnum;

        if (boxnum >= 1 && boxnum <= 9)
        {
            checkbox(boxnum);
        }
        else
        {
            xy(0, 16);
            cout << "Invalid box number! Please try again.\n";
        }
    }

    return 0;
}
