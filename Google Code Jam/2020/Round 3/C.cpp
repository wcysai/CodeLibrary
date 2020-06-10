#include<bits/stdc++.h>
#define MAXN 65
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,int> P;
int T,N,C,failed;
double cnt;
const double threshold=0.7400;
mt19937 wcy(time(NULL));
double get_prob(vector<int> v)
{
    int cnt=0;
    int sz=(int)v.size();
    for(int i=0;i<(int)v.size();i++)
        for(int j=i+1;j<(int)v.size();j++)
            if(v[i]+v[j]>=N) cnt++;
    return cnt/(double)(sz*(sz-1)/2);
}
double delete_klast(int k,vector<int> v)
{
    sort(v.begin(),v.end());
    if(k==0) return get_prob(v);
    int sz=(int)v.size()-k;
    double prob=0.0;
    double ndec=1.0/(k+1);
    double unit=1.0/(sz*(sz-1)/2);
    for(int i=k;i<(int)v.size();i++)
        for(int j=i+1;j<(int)v.size();j++)
        {
            if(v[i]+v[j]>=N) prob+=ndec*ndec*unit;
            if(v[i]+v[j]-(v[k-1]+1)>=N) prob+=2*(1-ndec)*ndec*unit;
            if(v[i]+v[j]-2*(v[k-1]+1)>=N) prob+=(1-ndec)*(1-ndec)*unit;
        }
    return prob;
}
pair<double,int> get_maxi(vector<int> v)
{
    sort(v.begin(),v.end());
    P ans=make_pair(-INF,-1);
    for(int i=0;i<=(int)v.size()-2;i++) ans=max(ans,make_pair(delete_klast(i,v),i));
    return ans;
}
vector<int> perm;
void solve()
{
    vector<int> v=perm;
    for(int i=0;i<N-2;i++)
    {
        if(get_maxi(v).F>=threshold)
        {
            cnt+=get_maxi(v).F;
            return;
        }
        v.pop_back();
    }
    failed++;
    cnt+=get_prob(v);
}
int main()
{
    srand(time(NULL));
    T=20000; N=15;
    cnt=0.0;
    for(int i=0;i<N;i++) perm.push_back(i);
    for(int i=0;i<T;i++)
    {
        random_shuffle(perm.begin(),perm.end());
        solve();
    }
    printf("%.10f %d\n",cnt,failed);
}