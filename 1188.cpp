#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 100002


int a[MAX+10], tree[MAX*3 +200],pre[MAX+10];

struct nd{
    int b,e,ind,ans;
};

typedef struct nd nd;

vector<nd> v;

bool cmp(nd a,nd c)
{
    return (a.e<c.e) || ((a.e == c.e) && a.b <c.b);
}

bool cmp2(nd a,nd c)
{
    return a.ind<c.ind;
}


void update(int node, int st,int ed,int i,int v)
{
    if(st>ed)
        return ;
    if(st>i || ed <i)
        return;
    if(st==ed)
    {
        tree[node]=v;
        return;
    }
    int mid,lc,rc;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    update(lc,st,mid,i,v);
    update(rc,mid+1,ed,i,v);

    tree[node]=tree[rc]+tree[lc];
}

int query(int node,int st, int ed, int i,int j)
{
    if(st>ed)
        return 0;
    if(st>j || ed<i)
        return 0;
    if(st>=i && ed<=j)
        return tree[node];
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    return query(lc,st,mid,i,j) +query(rc,mid+1,ed,i,j);
}

int main()
{
    int t,ti,n,i,j,q,qi;
    nd temp;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(tree,0,sizeof(tree));
        memset(pre,-1,sizeof(pre));
        v.clear();
        printf("Case %d:\n",ti);
        scanf("%d %d",&n, &q);

        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        for(qi=1; qi<=q; ++qi)
        {
            scanf("%d %d",&temp.b, &temp.e);
            temp.ind=qi;
            temp.ans=0;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),cmp);
        j=0;
        for(i=1; i<=n; ++i)
        {
            if(pre[a[i]] != -1)
                update(1,1,n,pre[a[i]],0);

            update(1,1,n,i,1);
            pre[a[i]]=i;
            for( ; j<v.size(); ++j)
            {
                if(v[j].e >i)
                    break;
                qi=query(1,1,n,v[j].b,v[j].e);
                v[j].ans=qi;
            }
        }

        sort(v.begin(),v.end(),cmp2);
        for(i=0; i<v.size(); ++i)
            printf("%d\n",v[i].ans);
    }
    return 0;
}
