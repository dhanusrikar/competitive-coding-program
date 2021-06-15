#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char arr[3][3];
        int m = 0;
        int n = 0;
        int countX = 0, countO = 0, countU = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 'X')
                {
                    countX++;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 'O')
                {
                    countO++;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == '_')
                {
                    countU++;
                }
            }
        }
        //for X
        if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')
            m = 1;
        if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')
            m = 1;
        if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')
            m = 1;
        if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')
            m = 1;
        if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')
            m = 1;
        if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')
            m = 1;
        if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
            m = 1;
        if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
            m = 1;

        //for O
        if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')
            n = 1;
        if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')
            n = 1;
        if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')
            n = 1;
        if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')
            n = 1;
        if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')
            n = 1;
        if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')
            n = 1;
        if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
            n = 1;
        if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
            n = 1;

        if (((m == 1) && (n == 1)) || (countX - countO < 0) || (countX - countO > 1))
        {
            cout << "3" << endl;
        }
        else if (countX == 0 && countO == 0 && countU == 9)
        {
            cout << "2" << endl;
        }
        else if (m == 1 && n == 0 && countX > countO)
        {
            cout << "1" << endl;
        }
        else if (m == 0 && n == 1 && countX == countO)
        {
            cout << "1" << endl;
        }
        else if (m == 0 && n == 0 && countU == 0)
        {
            cout << "1" << endl;
        }
        else if ((m == 0) && (n == 0) && (countU > 0))
        {
            cout << "2" << endl;
        }
        else
        {
            cout << "3" << endl;
        }
    }
    return 0;
}
