class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false; // 剪枝
        bool vis[m][n][(m + n + 1) / 2];
        memset(vis, 0, sizeof(vis));
        function<bool(int, int, int)> dfs = [&](int x, int y, int c) -> bool
        {
            if (c > m - x + n - y - 1)
                return false; // 剪枝：即使后面都是 ')' 也不能将 c 减为 0
            if (x == m - 1 && y == n - 1)
                return c == 1; // 终点一定是 ')'
            if (vis[x][y][c])
                return false; // 重复访问
            vis[x][y][c] = true;
            c += grid[x][y] == '(' ? 1 : -1;
            return c >= 0 && (x < m - 1 && dfs(x + 1, y, c) || y < n - 1 && dfs(x, y + 1, c)); // 往下或者往右
        };
        return dfs(0, 0, 0);
    }
};