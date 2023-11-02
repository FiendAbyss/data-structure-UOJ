#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int i = 0;
    while (n > i)
    {
        cin >> arr[i];
        i++;
    }
    int cer = 0;
    while (n > pow(2, cer) - 1)
    {
        cer++;
    }
    //cout << cer << endl;
    if (n){
        cout << arr[0] << ' ';
    }
    bool flag = true;
    for (int i = 1; i < cer; i++)
    {
        int head = pow(2, i) - 1;
        int tail = pow(2, i + 1) - 2;
        //cout << head << ' ' << tail << endl;
        while (tail >= head)
        {
            if (flag)
            {
                if (arr[tail] != -1)
                    cout << arr[tail] << ' ';
                tail--;
            }
            else
            {
                if (arr[head] != -1)
                    cout << arr[head] << ' ';
                head++;
            }
        }
        flag = !flag;
    }
    cout << endl;
}