#include<bits/stdc++.h>
#define  MAXN 5030
using namespace std;
int t,m;
char str[MAXN];
int cal(int x,int y)
{
    int p=(int)str[x];
    int q=(int)str[y];
    return max(p-q,q-p);
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&m);
        scanf("%s",str);
        int x=strlen(str);
        int ans=0;
        for(int k=x-1;k>0;k--)
        {
            int j=0,t=k,s=0,len=0;
            while(s<=m)
            {
                int tmp=cal(j,t);
                s+=tmp;
                j++;
                t--;
                len++;
                if(j>=t)
                {
                    if(s<=m) ans=max(ans,len); else ans=max(ans,len-1);
                    break;
                }
                else if(s>m)
                {
                    ans=max(ans,len-1);
                    while(s>m)
                    {
                        s-=cal(j-len,t+len);
                        len--;
                    }
                }
            }

        }
        for(int k=1;k<x-1;k++)
        {
            int t=x-1,j=k,s=0,len=0;
            while(s<=m)
            {
                int tmp=cal(j,t);
                s+=tmp;
                j++;
                t--;
                len++;
                if(j>=t)
                {
                    if(s<=m) ans=max(ans,len); else ans=max(ans,len-1);
                    break;
                }
                else if(s>m)
                {
                    ans=max(ans,len-1);
                    while(s>m)
                    {
                        s-=cal(j-len,t+len);
                        len--;
                    }
                }
            }

        }
        printf("%d\n",ans);
    }
}
