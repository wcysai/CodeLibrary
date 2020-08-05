#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
vector<int> v;
vector<int> odd,even;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear(); odd.clear(); even.clear();
        scanf("%d",&n);
        cin>>str;
        int val=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            int id=n-1-i;
            if(str[i]=='?')
            {
                cnt++;
                if(id&1) val--; else val++;
                v.push_back(i);
                if(id&1) odd.push_back(i); else even.push_back(i);
            }
            else 
            {
                if(id&1) val+=str[i]-'0'; else val-=str[i]-'0';
            }
        }
        val=(val%11+11)%11;
        int oid=0,eid=0;
        int i=0;
        while(i<(int)v.size())
        {
            if(str[v[i]]!='?') {i++; continue;}
            int id=n-1-v[i];
            if(val==0)
            {
                str[v[i]]='0';
                if(id&1) val=1; else val=10;
                if(id&1) oid++; else eid++;
            }
            else
            {
                int x;
                if(id&1) 
                {
                    val=(val+1)%11;
                    x=(11-val)%11;
                } 
                else 
                {
                    val--;
                    x=val;
                }
                if(x!=0)
                {
                    str[v[i]]='0'+x;
                    if(id&1) oid++; else eid++;
                }
                else
                {
                    if(id&1)
                    {
                        if(eid==(int)even.size())
                        {
                            str[v[i]]='0'+x;
                            oid++; 
                        }
                        else
                        {
                            str[even[eid]]='9';
                            eid++; i--; 
                        }
                    }
                    else
                    {
                        if(oid==(int)odd.size())
                        {
                            str[v[i]]='0'+x;
                            eid++; 
                        }
                        else
                        {
                            str[odd[oid]]='9';
                            oid++; i--;
                        }
                    }
                }
                val=0; 
            }
            i++;
        }
        if(val!=0) printf("-");
        cout<<str<<endl;
    }
    return 0;
}