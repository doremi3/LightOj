#include<stdio.h>

#define MAX 100003

struct item{
    int ans,ansf,pre,pref,post,postf;
};

typedef struct item item;

item tree[MAX*3 +10];
int a[MAX];

void init(int node,int st,int ed)
{
    if(st>ed)
        return;
    if(st==ed)
    {
        tree[node].ans=tree[node].pre=tree[node].post=a[st];
        tree[node].ansf=tree[node].pref=tree[node].postf=1;
        return;
    }
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    init(lc,st,mid);
    init(rc,mid+1,ed);

    item ret,ret1,ret2;
    ret1=tree[lc];
    ret2=tree[rc];

    ret.pre=ret1.pre;
    ret.pref=ret1.pref;
    if(ret1.pref==mid-st+1 && ret1.post==ret2.pre)
    {
        ret.pref=ret1.pref+ret2.pref;
    }
    ret.post=ret2.post;
    ret.postf=ret2.postf;

    if(ret1.post==ret2.pre && ret2.postf==ed-mid)
    {
        ret.postf=ret2.postf+ret1.postf;
    }

    if(ret1.ansf>ret2.ansf)
    {
        ret.ansf=ret1.ansf;
        ret.ans=ret1.ans;
    }
    else{
        ret.ansf=ret2.ansf;
        ret.ans=ret2.ans;
    }
    if(ret1.post==ret2.pre && ret1.postf+ret2.pref > ret.ansf)
    {
        ret.ansf=ret1.postf+ret2.pref;
        ret.ans=ret1.post;

    }
    tree[node]=ret;
}

item query(int node,int st,int ed,int i,int j)
{
    item ret;
    ret.ansf=ret.ans=ret.pre=ret.pref=ret.post=ret.postf=0;
    if(st>ed)
        return ret;
    if(st>j || ed<i)
        return ret;
    if(st>=i && ed<=j)
    {
       // printf("%d\n",tree[node].ansf);
        return tree[node];
    }
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;
    item ret1,ret2;

    ret1=query(lc,st,mid,i,j);
    ret2=query(rc,mid+1,ed,i,j);

    ret.pre=ret1.pre;
    ret.pref=ret1.pref;
    if(ret1.pref==mid-st+1 && ret1.post==ret2.pre)
    {
        ret.pref=ret1.pref+ret2.pref;
    }
    ret.post=ret2.post;
    ret.postf=ret2.postf;


    if(ret1.post==ret2.pre && ret2.postf==ed-mid)
    {
        ret.postf=ret2.postf+ret1.postf;
    }

    if(ret1.ansf>ret2.ansf)
    {
        ret.ansf=ret1.ansf;
        ret.ans=ret1.ans;
    }
    else{
        ret.ansf=ret2.ansf;
        ret.ans=ret2.ans;
    }
    if(ret1.post==ret2.pre && ret1.postf+ret2.pref > ret.ansf)
    {
        ret.ansf=ret1.postf+ret2.pref;
        ret.ans=ret1.post;
    }

    return ret;

}

int main()
{
    int t,ti,i,j,k,n,q,c;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d %d",&n,&c,&q);
        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        init(1,1,n);
        printf("Case %d:\n",ti);
        while(q--)
        {
            scanf("%d %d",&j,&k);
            printf("%d\n",query(1,1,n,j,k).ansf);
        }
    }
    return 0;
}
