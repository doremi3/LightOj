#include<bits/stdc++.h>
using namespace std;

#define MAX  50010

typedef long long ll;

const ll LIM = 1e10;

ll ans[MAX];

struct ele{
    ll x,y1,y2,type,ind;

};

bool cmp(ele a,ele b)
    {
        return (a.x<b.x) || (a.x==b.x && a.type<b.type);
    }

typedef struct ele ele;

struct node{
    struct node *lc, *rc;
    int cnt;

    node()
    {
        lc=rc=NULL;
        cnt=0;
    }

};

typedef struct node node;
node *root;
vector<ele> v;

void update(node *curr, ll st, ll ed, ll i)
{
    if(st>ed)
        return;
    if(i>ed || i<st)
        return;
    if(ed==st && i==st)
    {
        curr->cnt++;
        return;
    }
    ll mid=(st+ed)/2;
    if(i<=mid)
    {
        if(curr->lc==NULL)
            curr->lc=new node();
        update(curr->lc, st,mid,i);
    }
    else
    {
        if(curr->rc==NULL)
            curr->rc = new node();
        update(curr->rc, mid+1,ed,i);
    }
    curr->cnt++;
}

ll query(node *curr, ll st, ll ed, ll i,ll j)
{
    if(st>ed)
        return 0;
    if(i>ed || j<st)
        return 0;
    if(st>=i && ed<=j)
        return curr->cnt;
    ll mid=(st+ed)/2;
    ll ret=0;
    if(i<=mid)
    {
        if(curr->lc != NULL)
            ret+=query(curr->lc,st,mid,i,j);
    }
    if(j>mid)
    {
        if(curr->rc != NULL)
            ret+=query(curr->rc,mid+1,ed,i,j);
    }
    return ret;
}

void del(node *curr)
{
    if(curr->lc != NULL)
        del(curr->lc);
    if(curr->rc != NULL)
        del(curr->rc);
    delete(curr);
}

int main()
{
    ll t,ti,i,j,k,p,q,x1,y1,x2,y2;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        root = new node();
        v.clear();
        scanf("%lld %lld",&p,&q);
        for(i=1; i<=p; ++i)
        {
            scanf("%lld %lld",&j,&k);
            v.push_back({j,k,k,0,i});
        }
        for(i=1; i<=q; ++i)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            v.push_back({x1,y1,y2,-1,i});
            v.push_back({x2,y1,y2,1,i});
        }
       sort(v.begin(),v.end(),cmp);
       for(i=0; i<v.size(); ++i)
       {
           if(v[i].type==0)
                update(root,0,LIM,v[i].y1);
            else if(v[i].type==-1)
                ans[v[i].ind]=query(root,0,LIM,v[i].y1,v[i].y2);
            else
                ans[v[i].ind]=query(root,0,LIM,v[i].y1,v[i].y2)-ans[v[i].ind];

       }
       printf("Case %lld:\n",ti);
       for(i=1; i<=q; ++i)
            printf("%lld\n",ans[i]);
        del(root);
    }
    return 0;
}
