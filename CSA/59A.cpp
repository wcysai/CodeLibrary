#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,k;
char a[MAXN];
int cnt[26];
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
        cnt[a[i]-'a']++;
    for(int i=0;i<n;i++)
    {
        if(cnt[a[i]-'a']==1)
        {
            printf("%c\n",a[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
