/*************************************************************************
    > File Name: 75E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-04 15:10:11
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
int n,q,a[MAXN];
const int B=600;
int pre[200][MAXN];
int last[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;;i++)
    {
        memset(last,0,sizeof(last));
        for(int j=i*B;j<min(n,(i+1)*B);j++)
            last[a[j]]=a[j];
        for(int j=1;j<=80000;j++)
            if(!last[j]) last[j]=last[j-1];
        for(int mod=1;mod<=40000;mod++)
        {
            int ans=0;
            for(int kmod=mod;;kmod+=mod)
            {
                if(kmod-mod>=40000) break;
                if(last[kmod-1]<=kmod-mod) continue;
                ans=max(ans,last[kmod-1]-(kmod-mod));
            }
            pre[i][mod]=ans;
        }
        if((i+1)*B>=n) break;
    }
    int l,r,k;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&l,&r,&k);l--;r--;
        int ans=0;
        while(l%B!=0&&l<=r) {ans=max(ans,a[l]%k); l++;}
        while(r%B!=B-1&&l<=r) {ans=max(ans,a[r]%k); r--;}
        while(l<=r) {ans=max(ans,pre[l/B][k]); l+=B;}
        printf("%d\n",ans);
    }
    return 0;
}

