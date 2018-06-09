/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-09 19:02:49
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
map<char,int> mp;
int main()
{
    scanf("%d",&t);
    mp['@']=mp['!']=mp[':']=0;
    mp['A']=mp['B']=mp['C']=1;
    mp['D']=mp['E']=mp['F']=2;
    mp['G']=mp['H']=mp['I']=3;
    mp['J']=mp['K']=mp['L']=4;
    mp['M']=mp['N']=mp['O']=5;
    mp['P']=mp['Q']=mp['R']=mp['S']=6;
    mp['T']=mp['U']=mp['V']=7;
    mp['W']=mp['X']=mp['Y']=mp['Z']=8;
    while(t--)
    {
        cin>>str;
        n=str.size();
        int ans=0,last=0;
        for(int i=0;i<n;i++)
        {
            int lx=last/3,ly=last%3;
            int nx=mp[str[i]]/3,ny=mp[str[i]]%3;
            ans+=max(ny-ly,ly-ny)+max(nx-lx,lx-nx);
            last=mp[str[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}

