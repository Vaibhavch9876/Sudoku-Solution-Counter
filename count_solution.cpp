#include<bits/stdc++.h>
using namespace std;
#define N 9

int grid[N][N];

void getinput();
void printSolution();
bool isSafe_RC(int row, int col, int num);
bool isSafe_Box(int row, int col, int num);
bool isSafe(int i, int j, int num);
bool get_RC(int &row, int &col);
int count_Solution(int & ans);
void solve();


int main()
{
    cout << "\n\t\t\t\t\tENTER VALID SUDOKU : \n";
    getinput();
    solve();
    system("pause");
    return 0;
}

void getinput()
{
    for (int i = 0; i < N; i++)
    {
        cout << "\t\t\t\t\t";
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }
}

void printSolution()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

bool isSafe_RC(int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num)
                return false;
        if (grid[i][col] == num)
                return false;
    }
    return true;
}

bool isSafe_Box(int row, int col, int num)
{
    int boxx = row / 3;
    int boxy = col / 3;

    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
        if (grid[boxx * 3 + i][boxy * 3 + j] == num)
            return false;
    }
    return true;
}

bool isSafe(int i, int j, int num)
{
    return isSafe_RC(i, j, num) && isSafe_Box(i, j, num);
}

bool get_RC(int &row, int &col)
{
    for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
        if (grid[row][col] == 0)
            return true;
    return false;
}

int count_Solution(int & ans)
{
    int i, j;

    if (get_RC(i, j))
    {
        for (int num = 1; num <= N; num++)
        {
            if (isSafe(i, j, num))
            {
                grid[i][j] = num;
                int prev = ans;
                ans = count_Solution(ans);
                    grid[i][j] = 0;
            }
        }
    }
    else
        ans++;
    return ans;
}

void solve()
{
    int a = 0;
    int ans = count_Solution(a);
    cout << "\n\n\t\tYOUR SUDOKU HAS " << ans << "SOLUTIONS";
}
