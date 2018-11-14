/*************************************************************************
    > File Name: HMAPPY1.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 08:11:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,K,Q;
int deq[2*MAXN],s,t;
string str;
multiset<int> ms;
int main()
{
    scanf("%d%d%d",&N,&Q,&K);
    for(int i=1;i<=N;i++) scanf("%d",&deq[N+1-i]);
    s=1;t=N;
    cin>>str;
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        if(deq[i]==1) cnt++;
        else 
        {
            if(cnt) ms.insert(cnt);
            cnt=0;
        }
    }
    if(cnt) ms.insert(cnt);
    if(!ms.size())
    {
        for(int i=0;i<Q;i++) if(str[i]=='?') printf("%d\n",0);
        return 0;
    }
    int pre=0,suf=0;
    for(int i=1;i<=N;i++) if(deq[i]==1) pre++; else break;
    for(int i=N;i>=1;i--) if(deq[i]==1) suf++; else break;
    if(pre==N)
    {
        for(int i=0;i<Q;i++) if(str[i]=='?') printf("%d\n",min(N,K));
        return 0;
    }
    for(int i=0;i<Q;i++)
    {
        if(str[i]=='?')
        {
            auto it=ms.end();it--;
            printf("%d\n",min(*it,K));
        }
        else
        {
            if(pre) 
            {
                if(suf)ms.erase(ms.find(suf));
                ms.erase(ms.find(pre));
                pre--;suf++;
                ms.insert(suf);if(pre) ms.insert(pre);
                deq[++t]=deq[s];s++;
            }
            else
            {
                deq[++t]=deq[s];s++;
                pre=suf=0;
                if(deq[s]==1)
                {
                    for(int i=s;i<=t;i++) if(deq[i]==1) pre++; else break;
                }
            }
        }
    }
    return 0;
}

