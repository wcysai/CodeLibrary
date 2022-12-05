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
int n,q,l[MAXN],r[MAXN];
string str;
int dif[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    for(int i=1;i<n;i++) 
    {
        dif[i]=(str[i]!=str[i-1]?1:0);
        dif[i]+=dif[i-1];
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        r--; l--;
        int x=dif[r]-dif[l];
        if(str[r]!=str[l]) x++;
        printf("%d\n",(x+1)/2);
    }
    return 0;
}

