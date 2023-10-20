#include <iostream>
using namespace std;
const int N=100;
int a[N];
bool vis[N];
int n;
void dfs(int u)
{
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        for(int i=1;i<=2*n-1;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        exit(0);
        return;
    }
    if(a[u]!=0)
    {
      dfs(u+1);
      return;
    }
    for(int i=n;i>=1;i--)
    {
        if(i==1)
        {
            if(!vis[i])
            {
                a[u]=i;
                vis[i]=true;
                dfs(u+1);
                vis[i]=false;
                a[u]=0;
            }
        }
        else
        {
            if(!vis[i]&&a[i+u]==0&&i+u<=2*n-1)
            {
                a[u]=a[u+i]=i;
                vis[i]=true;
                dfs(u+1);
                vis[i]=false;
                a[u]=a[u+i]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}