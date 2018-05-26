/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-26 20:34:37
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,q,a[MAXN],ans,c[MAXN],b[MAXN],r,p,w;
int mark[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&q); ans=INF;
    for(int i=0;i<n;i++) scanf("%d",&a[i]); 
    for(int o=0;o<n;o++)
    {
        r=a[o];w=0;
        for (int i=0;i<=n;i++){
            if (a[i]<r){
                if (p>=k){
                    sort(b,b+p);
                    for (int j=0;j<=p-k;j++) c[w++]=b[j];
                }
                p=0;
            }
            else b[p++]=a[i];
        }
        sort(c,c+w);
        if (w>=q) ans=min(ans,c[q-1]-r);
    }
    cout << ans << endl;
    return 0;
}

