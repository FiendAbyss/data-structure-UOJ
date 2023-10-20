#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        stack<int> heights;
        int n;
        cin >> n;
        int *maxH = new int[n];
        int *h = new int[n];
        for (int j = 0; j < n; ++j)
            cin >> maxH[j];

        for (int j = 0; j < n; ++j)
        {
            while (!heights.empty() && maxH[j] <= maxH[heights.top()])
            {
                heights.pop();
            }
            if (heights.empty())
            {
                h[j] = maxH[j] * (j + 1);
                heights.push(j);
            }
            else if (maxH[j] > maxH[heights.top()])
            {
                h[j] = h[heights.top()] + maxH[j] * (j - heights.top());
                heights.push(j);
            }
        }
        int max = 0;
        for (int j = 0; j < n; ++j)
        {
            if (h[j] > max)
                max = h[j];
        }
        cout << max << endl;
    }
}