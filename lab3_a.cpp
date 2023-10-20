#include <iostream>
using namespace std;

int main()
{
    int n,m,x;
    cin >> n >> m;
    int *A_number = new int[n];
    int *B_number = new int[m];
    int *res = new int[max(m, n) + 1]{};
    for (int i = 0; i < n; ++i)
    {
        cin >> A_number[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> B_number[i];
    }
    for (int i = 0; i < max(m, n); ++i)
    {
        if (i < n && i < m)
            x = A_number[i] + B_number[i] + res[i];
        else if (i >= m)
            x = A_number[i] + res[i];
        else
            x = B_number[i] + res[i];

        if (x < 10) res[i] = x;
        else
        {
            res[i] = x % 10;
            res[i + 1] = 1;
        }
    }
    bool flag_zero = true;
    for (int i = max(m, n); i >= 0 ;i--)
    {
        if (flag_zero && res[i] == 0) continue;
        else {cout << res[i]; flag_zero = false;}
    }
    cout << endl;
}
