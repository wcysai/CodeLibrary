/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 16:51:17
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
int T,n,q;
string str;
int cnt[26][MAXN];
int main()
{
    scanf("%d",&T);
    int tot=0;
    while(T--)
    {
        tot++;
        scanf("%d%d",&n,&q);
        cin>>str;
        for(int i=0;i<=26;i++)
            for(int j=1;j<=n;j++)
                if(str[j-1]=='A'+i) cnt[i][j]=cnt[i][j-1]+1; else cnt[i][j]=cnt[i][j-1]; 
        printf("Case #%d:\n",tot);
        for(int i=0;i<q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            for(int j=0;j<26;j++)
            {
                if(cnt[j][r]-cnt[j][l-1]>0)
                {
                    printf("%d\n",cnt[j][r]-cnt[j][l-1]);
                    break;
                }
            }
        }
    }
    return 0;
}

