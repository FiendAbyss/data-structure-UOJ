#include<bits/stdc++.h>
using namespace std;

const int N=2e6+6;
char s[N], p1[N], p2[N];
int ne1[N], ne2[N], n1, n2;
bool st1[N], st2[N];

void init(char p[],int ne[],int n)
{
    for (int i = 2, j = 0; i <= n; i++)
    {
        while(j&&p[i]!=p[j+1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
}

void solve(int ne[],string s,char p[],bool st[],int m,int n)
{
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s[i]!=p[j+1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            st[i - n] = true;
            j = ne[j];
        }
    }
}

int main()
{
    int T;
    cin >> T;
    string p;
    cin >> p;
    bool flag = false;
    for (unsigned i = 0; i < p.length(); i++)
    {
        if (p[i] == '*')
        {
            flag = true;
        }
        else
        {
            if(flag)
                p2[++n2] = p[i];
            else
                p1[++n1] = p[i];
        }
    }
    init(p1, ne1, n1);
    init(p2, ne2, n2);
    while(T--)
    {
        string s;
        cin >> s;
        int m = s.length();
        s = " " + s;
        memset(st1, false, (m + 2) * sizeof(bool));
        memset(st2, false, (m + 2) * sizeof(bool));
        solve(ne1, s, p1, st1, m, n1);
        solve(ne2, s, p2, st2, m, n2);
        bool ans = false;
        if (!n1 && !n2)
        {
            ans = true;
        }
        if(!n1)
        {
            for (int i = 1; i <= m - 1; i++)
            {
                if(st2[i])
                {
                    ans = true;
                    break;
                }
            }
        }
        if(!n2)
        {
            for (int i = 0; i < m - 1; i++)
            {
                if (st1[i - n1 + 1])
                {
                    ans = true;
                    break;
                }
            }
        }
        for (int i = 0; i <= m - 1; i++)
        {
            if(st1[i])
            {
                int j = i + n1 + 1;
                if (j <= m - 1 && st2[j])
                {
                    ans = true;
                    break;
                }
            }
        }
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}