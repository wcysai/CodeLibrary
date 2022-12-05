int find(int k,int l,int r,int pos)
{
    if(sum[k]==0) return -1;
    if(r<pos) return -1;
    if(l==r) return pos;
    int mid=(l+r)/2;
    int x=find(k*2,l,mid,pos);
    if(x==-1) return find(k*2+1,mid+1,r,pos); else return x;
}
