#include <bits/stdc++.h>
using namespace std;
#define SIZE 2000
int UFSets[SIZE];

void Initial(int S[])
{
    for (int i = 0; i < SIZE; i++)
        S[i] = i;
}

int Find(int S[], int x)
{
    if (S[x] == x)
        return S[x];
    else
        return S[x] = Find(S, S[x]);
}

void Union(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    S[Root2] = Root1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    Initial(UFSets);
    bool flag = true;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        int fa = Find(UFSets, a), fb = Find(UFSets, b);
        int fa2 = Find(UFSets, a + n), fb2 = Find(UFSets, b + n);
        if (fa == fb)
        {
            flag = false;
            break;
        }
        else
        {
            Union(UFSets, fb, fa2);
            Union(UFSets, fa, fb2);
        }
    }
    if (flag)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}