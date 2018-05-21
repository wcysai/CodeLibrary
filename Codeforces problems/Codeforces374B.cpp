#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 100
using namespace std;
char s[MAXN][MAXN],str[MAXN];
int cnt[MAXN+1];
int n,k,same,low,equ;
int main()
{
    scanf("%d %d",&n,&k);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    scanf("%s",str);
    low=0;same=0;equ=0;
    int p=strlen(str);
    for(int i=0;i<n;i++)
    {
        int x=strlen(s[i]);
        if(x<p) low++;
        if(x==p)
        {
            equ++;
            int f=1;
            for(int j=0;j<p;j++)
                if(s[i][j]!=str[j]) f=0;
            if(f) same++;
        }
    }
    printf("%d ",(low/k)*5+low+1);
    printf("%d",((low+equ-same)/k)*5+low+equ-same+1);
    return 0;
}
