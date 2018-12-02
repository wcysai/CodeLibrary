/*************************************************************************
    > File Name: lhy.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 20:22:08
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
string str[MAXN];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tot=0;
    while(cin>>str[tot]) tot++;
    for(int i=tot-1;i>=0;i--)
    {
        int n=str[i].size();
        int num1=0,num2=0,num3=0,phase=0;
        char ch;
        for(int j=0;j<n;j++)
        {
            if(phase==0)
            {
                if(str[i][j]>='0'&&str[i][j]<='9') num1=num1*10+(str[i][j]-'0');
                else {phase=1; continue;}
            }
            else if(phase==1)
            {
                if(str[i][j]>='0'&&str[i][j]<='9') num1=num1*10+(str[i][j]-'0');
                else {phase=2; ch=str[i][j]; continue;}
            }
            else if(phase==2)
            {
                if(str[i][j]>='0'&&str[i][j]<='9') num1=num1*10+(str[i][j]-'0');
                else break;
            }
        }
        if(ch=='+') ch='-'; else if(ch=='-') ch='+';
        printf("a[%d]=a[%d]%ca[%d];\n",)
    }
    return 0;
}

