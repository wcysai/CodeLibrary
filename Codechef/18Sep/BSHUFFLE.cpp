/*************************************************************************
    > File Name: BSHUFFLE.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-12 08:00:45
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
int n,k,a[MAXN];
vector<int> perm;
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        puts("1\n1\n");
        return 0;
    }
    if(n==2)
    {
        puts("1 2\n2 1\n");
        return 0;
    }
    perm.resize(n+1);
    int cur=3;
    perm[1]=1;perm[2]=3;perm[3]=2;
    int need=2;
    while(cur<n)
    {
        if(cur&1)
        {
            int pos1=-1,pos2=-1,pos3=-1;
            for(int i=1;i<=cur;i++)
            {
                if(perm[i]==1) pos1=i;
                if(perm[i]==need) pos2=i;
                if(perm[i]==need+1) pos3=i;
            }
            swap(perm[pos3],perm[pos2]);
            swap(perm[pos3],perm[pos1]);
            need++;
            perm[cur+1]=perm[cur];perm[cur]=cur+1;
            cur++;
        }
        else
        {
            perm[cur+1]=perm[cur];perm[cur]=cur+1;
            cur++;
        }
    }
    for(int i=1;i<=n;i++) printf("%d%c",perm[i],i==n?'\n':' ');
    printf("%d",n);
    for(int i=1;i<=n-1;i++) printf(" %d",i);
    puts("");
    return 0;
}

