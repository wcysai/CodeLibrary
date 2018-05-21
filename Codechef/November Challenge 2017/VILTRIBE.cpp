#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
char str[MAXN];
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int n=strlen(str);
        int flag=0,cnt=0,a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='.')
            {
                if(flag!=0) cnt++;
            }
            else if(str[i]=='A')
            {
                a++;
                if(flag==0) flag=1;
                else if(flag==2)
                {
                    cnt=0;
                    flag=1;
                }
                else
                {
                    a+=cnt;
                    cnt=0;
                }
            }
            else if(str[i]=='B')
            {
                b++;
                if(flag==0) flag=2;
                else if(flag==1)
                {
                    cnt=0;
                    flag=2;
                }
                else
                {
                    b+=cnt;
                    cnt=0;
                }
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
