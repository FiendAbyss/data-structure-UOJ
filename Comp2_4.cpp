#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, S, K;
    cin >> N >> S >> K;
    vector<int> id(N);
    vector<int> ps(N + 1);
    for (int i = 0; i < N; i++)
    {
        int p, a;
        cin >> p >> a;
        ps[i + 1] = ps[i] + a;
        id[i] = p;
    }
    int left = S - K / 2;
    int right = left + K / 2 + K % 2;
    int reright = S + K / 2;
    int releft = reright - K / 2 - K % 2;
    int m = 0;
    int sumleft;
    int sumright;
    while (left <= S)
    {
        if (left > 0 || releft > 0)
        {
            sumleft = ps[upper_bound(id.begin(), id.end(), right) - id.begin()] - ps[lower_bound(id.begin(), id.end(), left) - id.begin()];
            sumright = ps[upper_bound(id.begin(), id.end(), reright) - id.begin()] - ps[lower_bound(id.begin(), id.end(), releft) - id.begin()];
            if (sumleft > sumright)
            {
                if (sumleft > m)
                {
                    m = sumleft;
                }
            }
            else
            {
                if (sumright > m)
                {
                    m = sumright;
                }
            }
        }
        left++;
        right += 2;
        reright--;
        releft -= 2;
    }
    cout << m << endl;
}