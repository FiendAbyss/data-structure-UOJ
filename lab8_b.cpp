#include<bits/stdc++.h>
using namespace std;

inline void readint(int &a) {
    a=0; char c; int sgn=1;
    while((c=getchar())<48) if (c == '-') sgn =-1;
    do a=a*10+(c^48);
    while((c=getchar())>47);
    a *= sgn;
}

int main()
{
    priority_queue<int, vector<int>, greater<int>> heap;
    int n, k;
    readint(n), readint(k);
    for (int i = 1; i <= k; i++)
    {
        int x;
        readint(x);
        heap.push(x);
    }
    for (int i = k + 1; i <= n; i++)
    {
        int x;
        readint(x);
        if (x > heap.top())
        {
            heap.pop();
            heap.push(x);
        }
    }
    cout << heap.top() << endl;
    return 0;
}