#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
string str;
vector<int> bits;
int sum;
void decompose()
{
    for(int i=0;i<(int)str.size();i++) bits.push_back(str[i]-'0');
    reverse(bits.begin(),bits.end());
}
void mult9()
{
    int carry=0;
    for(int i=0;i<(int)bits.size();i++)
    {
        int result=bits[i]*9+carry;
        bits[i]=result%10; carry=result/10;
    }
    if(carry) bits.push_back(carry);
}
void find_sum()
{
    sum=0;
    for(int i=0;i<(int)bits.size();i++) sum+=bits[i];
}
void add9()
{
    int pos=0;
    bits[pos]+=9;
    sum+=9;
    while(bits[pos]>9)
    {
        bits[pos]-=10; sum-=9;
        if(pos==(int)bits.size()-1) bits.push_back(1); else bits[pos+1]++;
        pos++;
    }
}
int main()
{
    cin>>str;
    decompose();mult9();find_sum();
    for(int i=1;;i++)
    {
        add9();
        if(sum<=9*i)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}

