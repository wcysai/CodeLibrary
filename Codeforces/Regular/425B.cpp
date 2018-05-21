#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
char str[MAXN],a[MAXN];
int n;
bool check[26];
int main()
{
    scanf("%s",a);
    int x=strlen(a);
    memset(check,false,sizeof(check));
    for(int i=0;i<x;i++)
        check[a[i]-97]=true;
    scanf("%s",str);
    x=strlen(str);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        int y=strlen(a);
        int f=1,k=-1;
        for(int j=0;j<x;j++)
        {
            k++;
            if(str[j]=='?')
            {
                if(check[a[k]-97]) continue;
                else
                {
                    f=0;
                    printf("NO\n");
                    break;
                }
            }
             else if(str[j]=='*')
            {
                if(y<x)
                {
                    k--;
                    continue;
                }
                while(y>x)
                {
                    if(check[a[k]-97])
                    {
                        f=0;
                        printf("NO\n");
                        break;
                    }
                    else k++;
                    y--;
                }
                if(!f) break;
            }
            else if(str[j]!=a[k])
                 {
                    f=0;
                    printf("NO\n");
                    break;
                }
        }
        if(f)
        {
            printf("YES\n");
        }
    }
    return 0;
}
