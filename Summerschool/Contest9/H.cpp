#include<bits/stdc++.h>
#define MAXN 125252
using namespace std;
int n,m;
pair<int,int> a[MAXN];
map<int,int> fd;
vector<int> save;
int main()
{
    while(scanf("%d",&m)==1)
    {
        fd.clear();
        save.clear();
        memset(a,0,sizeof(a));
        for(int i=1;i<=500;i++)
            if(i*(i+1)/2==m) {printf("%d\n",i); n=i; break;}
        int k=-1,j=0;
        int x;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            if(i==0||x!=a[k].first)
            {
                k++;
                fd[x]=k;
                a[k].first=x;
                a[k].second=1;
            }
            else
            {
                a[k].second++;
            }
        }
        int t=0;
        for(int i=0;i<=k;i++)
        {
            while(a[i].second!=0)
            {
                a[i].second--;
                for(int j=0;j<save.size();j++)
                    a[fd[a[i].first+save[j]]].second--;
                t++;
                if(t!=n) printf("%d ",a[i].first); else printf("%d",a[i].first);
                save.push_back(a[i].first);
            }
        }
        printf("\n");
    }
    return 0;

}
