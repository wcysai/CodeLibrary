#include<bits/stdc++.h>
#define MAXN 200005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
struct seg
{
    int len,num,crd;
    const bool operator<(seg y) const
    {
        if (len!=y.len) return len>y.len;
        if (crd!=y.crd) return crd<y.crd;
        return num>y.num;
    }
};
set<seg> s;
int n,a[MAXN],pre[MAXN],suf[MAXN],num[MAXN],len[MAXN];
vector<seg> p;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    p.clear();
    int cnt=1,k=a[0],q=0;
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    memset(num,0,sizeof(num));
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) cnt++;
        else
        {
            seg new_seg;
            new_seg.len=cnt;
            new_seg.num=k;
            new_seg.crd=q;
            num[q]=k;
            len[k]=cnt;
            p.push_back(new_seg);
            k=a[i];
            cnt=1;
            q=i;
            int sz=p.size();
            if(sz>1)
            {
                pre[p[sz-1].crd]=p[sz-2].crd;
                suf[p[sz-2].crd]=p[sz-1].crd;
            }
        }
    }
    pre[p[0].crd]=suf[p[p.size()-1].crd]=-1;
    for(int i=0;i<p.size();i++)
        s.insert(p[i]);
    int res=0;
    while(s.size())
    {
        seg now=*(s.begin());
        if(pre[now.crd]!=-1&&suf[now.crd!=-1]&&num[pre[now.crd]]==num[suf[now.crd]])
        {
            seg new_seg;
            new_seg.crd=pre[now.crd];
            new_seg.len=len[pre[now.crd]];
            new_seg.num=num[pre[now.crd]];
            auto it=s.lower_bound(new_seg);
            new_seg.crd=suf[now.crd];
            new_seg.len=len[suf[now.crd]];
            new_seg.num=num[suf[now.crd]];
            auto id=s.lower_bound(new_seg);
            (*it).len+=(*id).len;
            suf[(*it).crd]=suf[(*id).crd];

        }
    }
    return 0;
}
