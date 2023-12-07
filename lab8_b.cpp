#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
int h[N], ph[N], hp[N], cnt, m;

inline void readint(int &a)
{
    a = 0;
    char c;
    int sgn = 1;
    while ((c = getchar()) < 48)
        if (c == '-')
            sgn = -1;
    do
        a = a * 10 + (c ^ 48);
    while ((c = getchar()) > 47);
    a *= sgn;
}

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

void push(int x)
{
    cnt++;
    m++;
    ph[m] = cnt, hp[cnt] = m;
    h[cnt] = x;
    up(cnt);
}

int main()
{
    int n, k;
    readint(n), readint(k);
    for (int i = 1; i <= k; i++)
    {
        int x;
        readint(x);
        push(x);
    }
    for (int i = k + 1; i <= n; i++)
    {
        int x;
        readint(x);
        if (x > h[1])
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
            push(x);
        }
    }
    cout << h[1] << endl;
    return 0;
}