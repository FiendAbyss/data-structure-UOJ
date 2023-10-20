#include <iostream>
using namespace std;
const int M = 1001;
const int N = 1001;
int main()
{
    int m, n;
    cin >> m >> n;
    int arr[M][N];
    int i = 1, j = n, cnt = 1;
    int bound_line_right = n, bound_line_left = 1, bound_row_up = 1, bound_row_down = m;
    int flag; // 1左 2下 3右 4上
    if (n == 1)
        flag = 2;
    else
        flag = 1;
    while (cnt <= m * n)
    {
        arr[i][j] = cnt;
        switch (flag)
        {
        case 1:
            j--;
            break;
        case 2:
            i++;
            break;
        case 3:
            j++;
            break;
        case 4:
            i--;
            break;
        }

        cnt++;

        if (j == bound_line_right && flag == 3)
        {
            flag = 4;
            bound_row_down--;
            continue;
        }
        if (j == bound_line_left && flag == 1)
        {
            flag = 2;
            bound_row_up++;
            continue;
        }
        if (i == bound_row_up && flag == 4)
        {
            flag = 1;
            bound_line_right--;
            continue;
        }
        if (i == bound_row_down && flag == 2)
        {
            flag = 3;
            bound_line_left++;
            continue;
        }
    }
    for (int x = 1; x <= m; x++)
        {
            for (int y = 1; y <= n; y++)
            {
                cout << arr[x][y] << ' ';
            }
            cout << endl;
        }
    return 0;
}