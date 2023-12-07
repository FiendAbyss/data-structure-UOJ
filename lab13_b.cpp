#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n行m列, n is row, m is column
    cin >> n >> m;
    int **grid = new int*[n + 1]; 
    for (int i = 0; i <= n; i++)
        grid[i] = new int[m + 1];
    // grid is the map, 0 is water, 1 is land
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    }
    // there is an island (only one)
    // island is a connected component of 1
    // calculate the perimeter of the island
    int perimeter = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if (grid[i][j] == 1)
            {
                if (i - 1 < 1 || grid[i - 1][j] == 0)
                    perimeter++;
                if (i + 1 > n || grid[i + 1][j] == 0)
                    perimeter++;
                if (j - 1 < 1 || grid[i][j - 1] == 0)
                    perimeter++;
                if (j + 1 > m || grid[i][j + 1] == 0)
                    perimeter++;
            }
        }
    }
    cout << perimeter << endl;
    return 0;
}