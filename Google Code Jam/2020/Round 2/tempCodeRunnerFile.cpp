scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%lld",&L,&R);
        ll cur=1;
        if(L>=R)
        {
            ll l=0,r=INF;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(L-get_sum(cur,mid,1)>=R) l=mid; else r=mid;
            }
            L-=get_sum(cur,l,1); cur+=l;
        }
        else if(R>L)
        {
            ll l=0,r=INF;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(R-get_sum(cur,mid,1)>L) l=mid; else r=mid;
            }
            R-=get_sum(cur,l,1); cur+=l;
        }
        if(R>L&&R>=cur) R-=cur,cur++;
        int l=0,r=INF;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(get_sum(cur,mid,2)<=L&&get_sum(cur+1,mid,2)<=R) l=mid; else r=mid;
        }
        L-=get_sum(cur,l,2); R-=get_sum(cur+1,l,2);
        cur+=2*l;
        if(L>=R&&L>=cur) L-=cur,cur++;
        printf("Case #%d: %lld %lld %lld\n",t,cur-1,L,R);
    }
    return 0;