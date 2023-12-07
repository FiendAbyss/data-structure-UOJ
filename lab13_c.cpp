#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<char>> grid(rows, vector<char>(cols));

        // 输入网格数据
        for (int i = 0; i < rows; i++)
        {
            string rowInput;
            cin >> rowInput;
            for (int j = 0; j < cols; j++)
                grid[i][j] = rowInput[j];
        }

        bool pathExists;

        if (grid[0][0] == ')')
        {
            cout << "no" << endl;
            continue;
        }

        int n = grid.size(), m = grid[0].size(); 
        vector<vector<vector<bool>>> dp;

        for (int i = 0; i < n; i++)
        {
            dp.push_back(vector<vector<bool>>());
            for (int j = 0; j < m; j++)
                dp.back().push_back(vector<bool>(n + m));
        }

        dp[0][0][1] = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i || j)
                {
                    int step = (grid[i][j] == '(' ? 1 : -1);
                    for (int k = 0; k < n + m; k++)
                    {
                        int updatedStep = k - step;
                        if (updatedStep < 0 || updatedStep >= n + m)
                            continue;
                        if (i)
                            dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][updatedStep];
                        if (j)
                            dp[i][j][k] = dp[i][j][k] || dp[i][j - 1][updatedStep];
                    }
                }

        pathExists = dp[n - 1][m - 1][0];
        cout << (pathExists ? "yes" : "no") << endl;
    }
    return 0;
}
