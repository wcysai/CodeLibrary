/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-05 14:16:10
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
int N,C,S,a[MAXN],b[MAXN];
vector<int> v;
int main()
{
    scanf("%d%d%d",&N,&C,&S);
    for(int i=0;i<N;i++) scanf("%d%d",&a[i],&b[i]);
    int ans=INF;
    for(int i=0;i<(1<<N);i++)
    {
        v.clear();
        for(int j=0;j<N;j++) if((i>>j)&1) v.push_back(j);
        do
        {
            int now=0,res=0,add=S;
            for(int k=0;k<(int)v.size();k++)
            {
                int cur=a[v[k]],t;
                if(cur>now) t=(cur-now-1)/add+1; else t=0;
                res+=t; now+=t*add;
                now-=a[v[k]];add+=b[v[k]];
            }
            int t=0;
            if(C>now) t=(C-now-1)/add+1;
            ans=min(ans,res+t);
        }while(next_permutation(v.begin(),v.end()));
    }
    printf("%d\n",ans);
    return 0;
}

