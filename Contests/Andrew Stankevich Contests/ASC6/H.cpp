#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,key;};
int n,m,s,t,now;
int rcnt,kcnt,ccnt,icnt,ocnt;
int d[MAXN];
bool visr[MAXN],visc[MAXN],visi[MAXN],viso[MAXN];
bool usedkey[MAXN];
int locc[MAXN],loco[MAXN];
set<string> key;
vector<edge> G[MAXN];
map<string,int> room,character,item,object;
vector<int> keys[MAXN],characters[MAXN],items[MAXN],objects[MAXN];
vector<int> cneed[MAXN],oneed[MAXN];
vector<int> coffer[MAXN],ooffer[MAXN];
string rname[MAXN],kname[MAXN],cname[MAXN],iname[MAXN],oname[MAXN];
string str;
vector<string> ans;
void fake_print(string str)
{
    ans.push_back(str);
}
void real_print()
{
    for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<endl;
}
void add_room(string str)
{
    if(room[str]) return;
    room[str]=++rcnt; rname[rcnt]=str;
}
void add_character(string str)
{
    if(character[str]) return;
    character[str]=++ccnt; cname[ccnt]=str;
}
void add_object(string str)
{
    if(object[str]) return;
    object[str]=++ocnt; oname[ocnt]=str;
}
void add_item(string str)
{
    if(item[str]) return;
    item[str]=++icnt; iname[icnt]=str;
}
bool is_key(string str)
{
    if(key.count(str)) return true;
    return false;
}
void add_edge(int u,int v,int key)
{
    G[u].push_back((edge){v,key}); G[v].push_back((edge){u,key});
}
void get_items(vector<int> &v)
{
    getline(cin,str);
    int last=0;
    for(int it=0;it<(int)str.size();it++)
    {
        if(str[it]==',')
        {
            string ite=str.substr(last,it-last);
            add_item(ite);
            v.push_back(item[ite]);
            last=it+2;
        }
    }
    string ite=str.substr(last);
    add_item(ite); v.push_back(item[ite]);
}
void pickall(int id)
{
    string s;
    for(auto x:items[id])
    {
        visi[x]=true;
        s="pick "+iname[x];
        fake_print(s);
    }
}
void walk(int to)
{
    string s="go to "+rname[to];
    fake_print(s);
    now=to;
}
void go(int to)
{
    assert(visr[to]);
    fill(d+1,d+rcnt+1,INF);
    d[to]=0; queue<int> que; que.push(to);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(auto e:G[v])
        {
            if(visr[e.to]&&d[e.to]==INF&&usedkey[e.key])
            {
                d[e.to]=d[v]+1;
                que.push(e.to);
            }
        }
    }
    assert(d[now]!=INF);
    while(now!=to)
    {
        for(auto e:G[now])
        {
            if(visr[e.to]&&d[e.to]==d[now]-1&&usedkey[e.key])
            {
                walk(e.to);
                break;
            }
        }
    }
}
void opendoor(int to)
{
    string s="open door to "+rname[to];
    fake_print(s);
}
void exchange_item(int id,bool ischaracter,bool isgive)
{
    vector<int> &v=ischaracter?(isgive?cneed[id]:coffer[id]):(isgive?oneed[id]:ooffer[id]);
    string s=isgive?(ischaracter?"give":"use"):"take";
    for(int i=0;i<(int)v.size();i++)
    {
        s+=" "+iname[v[i]];
        if(i==(int)v.size()-1);
        else if(i==(int)v.size()-2) s+=" and";
        else s+=",";
    }
    s+=isgive?(ischaracter?" to "+cname[id]:" on "+oname[id]):(" from "+(ischaracter?cname[id]:oname[id]));
    fake_print(s);
}
void finish_character(int id)
{
    string s="talk to "+cname[id];
    fake_print(s);
    exchange_item(id,true,true); exchange_item(id,true,false);
}
void finish_object(int id)
{
    exchange_item(id,false,true); exchange_item(id,false,false);
}
void success()
{
    real_print();
    cout<<"save princess"<<endl;
    exit(0);
}
bool checkstatus()
{
    if(visr[t]) {success(); return true;}
    for(int i=1;i<=rcnt;i++)
    {
        if(!visr[i]) continue;
        for(auto e:G[i])
        {
            if(visi[e.key]&&!visr[e.to]&&!usedkey[e.key])
            {
                go(i); usedkey[e.key]=true;
                opendoor(e.to); visr[e.to]=true;
                walk(e.to); pickall(e.to);
                return true;
            }
        }
    }
    for(int i=1;i<=ccnt;i++)
    {
        if(visc[i]) continue;
        if(!visr[locc[i]]) continue;
        bool f=true;
        for(auto x:cneed[i]) if(!visi[x]) {f=false; break;}
        if(f)
        {
            go(locc[i]); 
            finish_character(i);
            for(auto x:coffer[i]) visi[x]=true;
            visc[i]=true;
            return true;
        }
    }
    for(int i=1;i<=ocnt;i++)
    {
        if(viso[i]) continue;
        if(!visr[loco[i]]) continue;
        bool f=true;
        for(auto x:oneed[i]) if(!visi[x]) {f=false; break;}
        if(f)
        {
            go(loco[i]); 
            finish_object(i);
            for(auto x:ooffer[i]) visi[x]=true;
            viso[i]=true;
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("quest.in","r",stdin);
    freopen("quest.out","w",stdout);
    scanf("%d",&n); getchar();
    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        add_room(str);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d ",&u,&v);
        getline(cin,str);
        add_item(str);
        add_edge(u,v,item[str]);
    }
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d ",&x,&y,&z);
        for(int j=0;j<x;j++)
        {
            getline(cin,str); 
            add_character(str);
            int id=character[str]; characters[i].push_back(id); locc[id]=i;
            get_items(cneed[id]); get_items(coffer[id]);
        }
        for(int j=0;j<y;j++)
        {
            getline(cin,str);
            add_object(str);
            int id=object[str]; objects[i].push_back(id); loco[id]=i;
            get_items(oneed[id]); get_items(ooffer[id]);
        }
        for(int j=0;j<z;j++)
        {
            getline(cin,str);
            add_item(str);
            int id=item[str]; items[i].push_back(id);
        }
    }
    getline(cin,str); s=room[str];
    getline(cin,str); t=room[str]; 
    memset(visr,false,sizeof(visr));
    memset(visc,false,sizeof(visc));
    memset(viso,false,sizeof(viso));
    memset(visi,false,sizeof(visi));
    now=s; pickall(now); visr[now]=true;
    while(checkstatus());
    cout<<"dead princess"<<endl;
    return 0;
}
