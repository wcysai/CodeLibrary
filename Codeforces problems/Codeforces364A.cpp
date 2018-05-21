#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 100
using namespace std;
int main()
{
    char s[MAXN];
    int n,a[MAXN/2];
    memset(a,0,sizeof(a));
    scanf("%d\n",&n);
    scanf("%s",s);
    int cnt=0,i=-1;
    int p=strlen(s);
    while(i<p)
    {
        i++;
        if(s[i]=='B')
        {
            cnt++;
            int x=0;
            while(s[i]=='B')
            {
                i++;
                x++;
                if(i==strlen(s)) break;
            }
            a[cnt-1]=x;
        }
    }
    printf("%d\n",cnt);
    i=0;
    while(a[i]!=0)
    {
        printf("%d ",a[i]);
        i++;
    }
    return 0;
}
