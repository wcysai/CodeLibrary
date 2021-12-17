#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
vector<P> ans;
queue<int> que;
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    memset(used,false,sizeof(used));
    int x=0,y=0,z=0;
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]=='A') x++;
        else if(str[i]=='B') y++; 
        else z++; 
    }
    if(x>n||y>n||z>n) {puts("NO"); return 0;}
    //ab+ac=x
    //ab+bc=y
    //bc+ac=z
    int ab=n-z,ac=n-y,bc=n-x;
    if(ab)
    {
        while(que.size()) que.pop();
        for(int i=2*n-1;i>=0;i--)
        {
            if(str[i]=='B') que.push(i);
            else if(str[i]=='A'&&que.size())
            {
                ans.push_back(P(i+1,que.front()+1));
                used[i]=used[que.front()]=true;
                que.pop();
                ab--; if(!ab) break;
            }
        }
        if(ab) {puts("NO"); return 0;}
    }
    if(bc)
    {
        while(que.size()) que.pop();
        for(int i=0;i<2*n;i++)
        {
            if(used[i]) continue;
            if(str[i]=='B') que.push(i);
            else if(str[i]=='C'&&que.size())
            {
                ans.push_back(P(que.front()+1,i+1));
                used[i]=used[que.front()]=true;
                que.pop();
                bc--; if(!bc) break;
            }
        }
        if(bc) {puts("NO"); return 0;}
    }
    if(ac)
    {
        while(que.size()) que.pop();
        for(int i=0;i<2*n;i++)
        {
            if(used[i]) continue;
            if(str[i]=='A') que.push(i);
            else if(str[i]=='C'&&que.size())
            {
                ans.push_back(P(que.front()+1,i+1));
                used[i]=used[que.front()]=true;
                que.pop();
                ac--; if(!ac) break;
            }
        }
        if(ac) {puts("NO"); return 0;}
    }
    puts("YES");
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}