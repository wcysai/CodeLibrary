/*************************************************************************
    > File Name: 85E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 23:55:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
int cntl,cntr;
int ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int n=str.size();
        stack<int> l,r;
        while(l.size()) l.pop();
        while(r.size()) r.pop();
        bool f=true;
        for(int i=0;i<n;i++) ans[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(') l.push(i); else r.push(i);
            if(r.size()>l.size())
            {
                if(l.size()==0)
                {
                    f=false;
                    break;
                }
                else
                {
                    int p=r.top();r.pop();int q=r.top();r.pop();
                    ans[p]=1;ans[q]=2;
                    p=l.top();l.pop();
                    ans[p]=0;
                }
            }
        }
        if(l.size()>2*r.size()) f=false;
        while(l.size()>r.size())
        {
            int p=l.top();l.pop();int q=l.top();l.pop();
            ans[p]=1;ans[q]=2;
            int s=r.top();r.pop();
            if(s<p) f=false;
            ans[s]=0;
        }
        while(l.size())
        {
            int p=l.top();l.pop();int q=r.top();r.pop();
            if(q<p) f=false;
            ans[p]=ans[q]=0;
        }
        if(!f) {puts("impossible"); continue;}
        for(int i=0;i<n;i++) 
            if(ans[i]==0) printf("G");
            else if(ans[i]==1) printf("R");
            else printf("B");
        puts("");
    }
    return 0;
}

