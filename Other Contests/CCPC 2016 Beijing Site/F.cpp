#include<bits/stdc++.h>
#define MAXN 25
#define MAXM 25
using namespace std;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXM];
struct save
{
    int cnt,id;
}a[5];
bool cmp(save x,save y)
{
    if(x.cnt==y.cnt) return x.id<y.id;
    return x.cnt>y.cnt;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            getchar();
        }
        for(int i=0;i<5;i++)
         {
             a[i].cnt=0;
             a[i].id=i;
         }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='A') a[0].cnt++;
                    else if(str[i][j]=='G') a[4].cnt++;
                        else a[str[i][j]-'B'].cnt++;
        sort(a,a+5,cmp);
        bool f=true;
        for(int i=0;i<5;i++)
        {
            if(a[i].cnt!=0)
            {
                if(f)
                {
                    if(a[i].id==0) printf("A");
                    else if(a[i].id==4) printf("G");
                    else printf("%c",'B'+a[i].id);
                }
                else
                {
                    if(a[i].id==0) printf(" A");
                    else if(a[i].id==4) printf(" G");
                    else printf(" %c",'B'+a[i].id);
                }
                f=false;
                printf(" %d",a[i].cnt);
            }
        }
        printf("\n");
    }
    return 0;
}
