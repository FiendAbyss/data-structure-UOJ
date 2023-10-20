#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], stk[N], top;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
	{
        int x = a[i];
        if (top == 0)
        {
			stk[++top] = x;
		}else
		{
			while(top > 0 && x < stk[top] && k > 0)
			{
				top--;
                k--;
            }
            stk[++top] = x;
        }
    }
	while (top > 0 && k > 0)
	{
		top--;
		k--;
	}
    bool flag = false;
    for (int i = 1; i <= top; i++)
    {
		if(stk[i]!=0)
		{
            flag = true;
            cout << stk[i];
        }
        else if (flag)
        {
            cout << stk[i];
        }
    }
	if(!flag)
        cout << 0;
    cout << endl;
    return 0;
}