#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool isnum(char c)
{
    if(c>='0'&&c<='9')return true;
    else return false;
}
bool isf(int l,int r)
{
    while(s[l]==' ')l++;
    while(s[r]==' ')r--;
    if(s[l]=='+'||s[l]=='-')l++;
    int cnt=0,num=0;
    if(l>r)return false;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='.')cnt++;
        else if(!isnum(s[i]))return false;
        else num++;   
    }
    if(num==0)return false;
    if(cnt!=1)return false;
    return true;
}
bool isi(int l,int r)
{
    while(s[l]==' ')l++;
    while(s[r]==' ')r--;
    if(s[l]=='+'||s[l]=='-')l++;
    if(l>r)return false;
    for(int i=l;i<=r;i++)
    {
        if(!isnum(s[i]))return false;
    }
    return true;
}
int main()
{
    getline(cin,s);
    n=s.length()-1;
    bool flag=true;
    int e=-1;
    for(int i=0;i<=n;i++)
    {
        if(s[i]=='e'||s[i]=='E')
        {
            e=i;
            break;
        }
    }
    if(e!=-1)
    {
        flag=(isi(0,e-1)||isf(0,e-1))&&isi(e+1,n);
    }else
    {
        flag=isi(0,n)||isf(0,n);
    }
    cout<<((flag)?"true":"false")<<endl;
    return 0;
}