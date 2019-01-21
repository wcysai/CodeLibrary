/*************************************************************************
    > File Name: L.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 16:51:45
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
int T,n;
string str;
int L,O,V,E;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>str;
        n=str.size();
        L=O=V=E=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='L') L++;
            if(str[i]=='O'&&L) {L--; O++;}
            if(str[i]=='V'&&O) {O--; V++;}
            if(str[i]=='E'&&V) {V--; E++;}
        }
        printf("%d\n",E);
    }
    return 0;
}

