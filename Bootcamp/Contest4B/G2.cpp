/*************************************************************************
    > File Name: G2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 18:38:50
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
const int B=1000;
char str[3];
int bit[105][MAXN+1];
int sum(int id,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,int x)
{
    while(i<=n)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        add((i-1)/B,a[i],1);
    }
    int l,r,x,y;
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='G')
        {
            scanf("%d%d%d%d",&l,&r,&x,&y);
            int ans=0;
            while(l<=r&&l%B!=1) {if(a[l]>=x&&a[l]<=y) ans++; l++;}
            while(l<=r&&r%B!=0) {if(a[r]>=x&&a[r]<=y) ans++; r--;}
            while(l<=r) 
            {
                int id=(l-1)/B;
                ans+=sum(id,y);
                ans-=sum(id,x-1);
                l+=B;
            }
            printf("%d\n",ans);
        }
        else
        {
            scanf("%d%d",&x,&y);
            int id=(x-1)/B;add(id,a[x],-1);
            a[x]=y;add(id,a[x],1);
        }
    }
    return 0;
}

