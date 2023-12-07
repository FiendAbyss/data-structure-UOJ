#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m > n)
    {
        return 0;
    }
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    deque<int> q;

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && q.front() <= i - m)
        {
            q.pop_front();
        }

        while (!q.empty() && arr[q.back()] < arr[i])
        {
            q.pop_back();
        }

        q.push_back(i);

        if (i >= m - 1)
            cout << arr[q.front()] << " ";
    }
    cout << endl;
    return 0;
}