#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int N = 1001;

struct Edge{
    int s,e,next;
}edge1[6*N],edge2[6*N];

int n,m,e_num1,e_num2,vis_num,cnt;
int head[N],instack[N],low[N],tim[N],belong[N],de[N];

void AddEdge(int a,int b,Edge edge[],int &e_num){
    edge[e_num].s=a; edge[e_num].e=b; edge[e_num].next=head[a]; head[a]=e_num++;
}

void getmap(){
    int a,b;
    scanf("%d%d",&n,&m);
    e_num1=0;
    memset(head,-1,sizeof(head));
    while(m--){
        scanf("%d%d",&a,&b);
        AddEdge(a,b,edge1,e_num1);
    }
}

stack <int> st;
void tarjan(int x){
    int j;
    tim[x]=low[x]=++vis_num;
    instack[x]=1;
    st.push(x);
    for(j=head[x];j!=-1;j=edge1[j].next){
        int u=edge1[j].e;
        if(tim[u]==-1){
            tarjan(u);
            if(low[x]>low[u])low[x]=low[u];
        }
        else if(instack[u] && low[x]>tim[u])low[x]=tim[u];
    }
    if(low[x]==tim[x]){
        cnt++;
        do{
            j=st.top();
            st.pop();
            instack[j]=0;
            belong[j]=cnt;
        }while(j!=x);
    }
}

int topo()
{
    int i,cur,u,count,num;
    count=0;
    for(i=1;i<=cnt;i++){
        if(de[i]==0){
            cur=i;count++;
        }
    }
    if(count>1)return 0;
    num=cnt;
    while(num--){
        count=0;
        for(i=head[cur];i!=-1;i=edge2[i].next){
            u=edge2[i].e;
            de[u]--;
            if(de[u]==0){
                count++;cur=u;
            }
        }
        if(count>1)return 0;
    }
    return 1;
}

void solve(){
    int i;
    cnt=vis_num=0;
    memset(instack,0,sizeof(instack));
    memset(low,0,sizeof(low));
    memset(tim,-1,sizeof(tim));
    for(i=1;i<=n;i++){
        if(tim[i]==-1)tarjan(i);
    }

    e_num2=0;
    memset(head,-1,sizeof(head));
    memset(de,0,sizeof(de));
    for(i=0;i<e_num1;i++){
        int j=edge1[i].s;
        int k=edge1[i].e;
        if(belong[j]!=belong[k]){
            AddEdge(belong[j],belong[k],edge2,e_num2);
            de[belong[k]]++;
        }
    }
    topo()==1?puts("I love you my love and our love save us!"):puts("Light my fire!");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        getmap();
        solve();
    }
    return 0;
}
