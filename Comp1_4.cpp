#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *v = new int[n];
    
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int *dp1 = new int[n];
    int *dp2 = new int[n];
    int sum = v[0];
    dp1[0] = v[0];
    stack<int> d1;
    d1.push(0);
    for (int i = 1; i < n; ++i)
    {
        if (v[d1.top()] > v[i])
        {
            d1.push(i);
            sum = dp1[i - 1] + v[i];
        }
        else
        {
            while (!d1.empty() && v[d1.top()] < v[i] + i - d1.top())
            {
                d1.pop();
            }
            if (d1.empty())
            {
                sum = (2 * v[i] + i) * (i + 1) / 2;
            }
            else
                sum = dp1[d1.top()] + (2 * v[i] + i - d1.top() - 1) * (i - d1.top()) / 2;
            d1.push(i);
        }
        dp1[i] = sum;
    }
    sum = v[n - 1];
    dp2[n - 1] = v[n - 1];
    stack<int> d2;
    d2.push(n - 1);
    for (int i = n - 2; i >= 0; --i)
    {
        if (v[d2.top()] > v[i])
        {
            d2.push(i);
            sum = dp1[i - 1] + v[i];
        }
        else
        {
            while (!d2.empty() && v[d2.top()] < v[i] + i - d2.top())
            {
                d2.pop();
            }
            if (d2.empty())
            {
                sum = (2 * v[i] + n - i + 1) * (n - i) / 2;
            }
            else
                sum = dp2[d2.top()] + (2 * v[i] + d1.top() - i - 1) * (d1.top() - i) / 2;
            d2.push(i);
        }
        dp2[i] = sum;
    }
    int min_num = dp1[0] + dp2[0] - v[0];
    for (int i = 0; i < n; ++i)
    {
        min_num = min(min_num, dp1[i] + dp2[i] - v[i]);
        cout << dp1[i] << ' ' << dp2[i] << ' ' << v[i] << ' ' << min_num << endl;
    }
    cout << min_num << endl;
}