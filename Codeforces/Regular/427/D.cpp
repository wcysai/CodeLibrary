#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
int cnt[MAXN];
void manacher(char str[],int len[],int n)
{
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i)
    {
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]])
            ++len[i];
        if(q+len[i]-1>r)
            j=i;
    }
}
int a[MAXN];
char str[MAXN];
int main()
{
    scanf("%s",str);
    int x=strlen(str);
    manacher(str,a,strlen(str));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<2*x-1;i++)
    {
        cnt[a[i]]++;
    }
    for(int i=x-1;i>=1;i--)
        cnt[i]+=2*cnt[i+1];
    for(int i=1;i<=x;i++)
        printf("%d ",cnt[i]);
    return 0;
}
