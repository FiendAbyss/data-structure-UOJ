#include <iostream>
using namespace std;
const int Max = 1e6 + 1;

int *KMP(string a, string b)
{
    if (b == "")
    {
        int *ans = new int[Max]{};
        for (unsigned i = 0; i < a.length();++i)
        {
            ans[i] = i + 1;
        }
        ans[a.length()] = -1;
        return ans;
    }
    int *Next = new int[Max];
    int *ans = new int[Max]{};
    int pos = 0;
    int la = a.length(), lb = b.length();
    for (int i = 1; i < lb; i++)
    {
        int j = Next[i - 1];
        while (j && b[i] != b[j])
        {
            j = Next[j - 1];
        }
            if(b[i]==b[j]){
                j++;
            }
            Next[i] = j;
    }
        for(int i=0,j=0;i<la;i++){
            while(j&&b[j]!=a[i]){
                j = Next[j - 1];
            }
        if(a[i]==b[j]){
            j++;
        }
        // cout<<j<<endl;
        if(j==lb)
        {
            ans[pos] =  i - lb + 2;
            pos++;
            j = Next[j - 1];
        }
    }
    ans[pos] = -1;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string a, b;
    
    cin >> a;
    string s1 = a.substr(0, a.find_first_of('*'));
    string s2 = a.substr(a.find_first_of('*') + 1, a.size() - 1);
    while (n)
    {
        int p1 = 0, p2 = 0;
        cin >> b;
        if (a == "*")
        {
            cout << "true" << endl;
            n--;
            continue;
        }

        int delta = s1.length() + 1;
        if (s2 == "")
            delta--;
        int *pos1 = KMP(b, s1);
        int *pos2 = KMP(b, s2);

        bool flag = false;

        /*int tst1 = 0, tst2 = 0;
        while (pos1[tst1] != -1)
        {
            cout << pos1[tst1] << ' ';
            tst1++;
        }
        cout << endl;
        while (pos2[tst2] != -1)
        {
            cout << pos2[tst2] << ' ';
            tst2++;
        }
        cout << endl
             << delta << endl;*/

        while (pos1[p1] != -1 && pos2[p2] != -1)
        {
            int x = pos2[p2] - pos1[p1];
            if (x == delta)
            {
                flag = true;
                break;
            }
            if (x < delta)
            {
                p2++;
            }
            else
            {
                p1++;
            }
        }
        if (flag)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        n--;
    }
}