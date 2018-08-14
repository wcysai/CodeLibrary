#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,int> P;
int n;
double bit[MAXN+1];
int d[MAXN];
vector<P> a[MAXN];
double sum(int i)
{
    double s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,double x)
{
    while(i<MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	set<int> s;
	map<int,int> mp;
	s.clear();
	mp.clear();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d[i];j++)
		{
			double x;int y;
			scanf("%lf%d",&x,&y);
			s.insert(y);
			a[i].push_back(P(x,y));
		}
	}
	vector<int> v(s.begin(),s.end());
	for(int i=0;i<v.size();i++)
		mp[v[i]]=i+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<d[i];j++)
		{
			a[i][j].S=mp[a[i][j].S];
			//printf("%f %d\n",a[i][j].F,a[i][j].S);
		}
	memset(bit,0,sizeof(bit));
	double ans=0,now=0;
	vector<P> save;
	for(int i=0;i<n;i++)
	{
		save.clear();
		for(int j=0;j<d[i];j++)
		{
			ans+=a[i][j].F*(now-sum(a[i][j].S));
			save.push_back(a[i][j]);
		}
		for(int j=0;j<d[i];j++)
		{
			add(save[j].S,save[j].F);
			now+=save[j].F;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}