#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000007
using namespace std;
int n,k;
int h[MAXN],r[MAXN],R[MAXN],st[MAXN],dummy[MAXN];
vector<int> save;
map<int,int> mp;
void solve()
{
	int t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		r[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
}
void solve2()
{
	int t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        //dummy[i]=h[i];
    }
   /* sort(dummy,dummy+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i==0||dummy[i]!=dummy[i-1])
        {
            cnt++;
            map[dummy[i]]=cnt;
        }
    }
    for(int i=0;i<n;i++)
        h[i]=map[h[i]];*/
    h[n]=0;
    solve();
    for(int i=0;i<n;i++)
        printf("%d\n",r[i]);
    for(int i=0;i<n;i++)
        if(r[i]>k+i) save.push_back(i);
    if(save.size()==0)
    {
        printf("YES\n");
        return 0;
    }
    int x=save[save.size()-1],y=h[x];
    for(int i=0;i<save.size()-1;i++)
        if(r[i]!=x)
        {
            printf("NO\n");
            return 0;
        }
    h[x]=INF;
    solve2();
    h[x]=y;
    if(save.size()==1)
    {
        int p=INF;
        for(int i=x-1;i>=0;i--)
        {
            if(h[i]<y) p=i;
            else if(h[i]>y)
            {
                if(p!=INF&&i+k<=p&&R[i]-k<=x)
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        printf("NO\n");
        return 0;
    }
    else
    {
        int p=INF;
        int rb=save[0]+k,lb=save[save.size()-2];
        for(int i=rb;i>=lb;i--)
        {
            if(h[i]<y) p=i;
            else if(h[i]>y)
            {
                if(p!=INF&&i+k<=p&&R[i]-k<=x)
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        printf("NO\n");
        return 0;
    }
    return 0;
}
