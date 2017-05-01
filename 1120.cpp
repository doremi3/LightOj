#include<bits/stdc++.h>
using namespace std;

#define LIM 1000000010

#define MAX 60100

typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> xpos;
vector<pii> y_st[MAX],y_ed[MAX];
map<int,int> ind;

struct node
{
    ll on,cnt;
    struct node *lc, *rc;

    node()
    {
        lc=NULL;
        rc=NULL;
        on=0;
        cnt=0;
    }
};

typedef struct node node;

node *root;

void update(node *curr, ll st,ll ed,ll i, ll j,ll val)
{
    if(st>ed)
        return;
    if(i>ed || j<st)
        return;
    if(st>=i && ed<=j)
    {
        curr->cnt+=val;
        if(curr->cnt)
            curr->on=ed-st+1;
        else
        {
            curr->on=0;
            if(curr->lc != NULL)
                curr->on+=(curr->lc)->on;
            if(curr->rc != NULL)
                curr->on += (curr->rc)->on;
        }
        return;
    }
    ll mid=(st+ed)/2;
    if(i<=mid)
    {
        if(curr->lc == NULL)
            curr->lc = new node();
        update(curr->lc,st,mid,i,j,val);
    }
    if(j>mid)
    {
        if(curr->rc == NULL)
            curr->rc = new node();
        update(curr->rc,mid+1,ed,i,j,val);
    }
    if(curr->cnt)
        curr->on=ed-st+1;
    else
    {
        curr->on=0;
        if(curr->lc != NULL)
            curr->on+=(curr->lc)->on;
        if(curr->rc != NULL)
            curr->on += (curr->rc)->on;
    }
    return;

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
    ll t,ti,q,i,j,k,n,x1,x2,y1,y2,c,ans,pre,pls;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        c=1;
        ind.clear();
        xpos.clear();
        for(i=0; i<MAX; ++i)
        {
            y_st[i].clear();
            y_ed[i].clear();
        }
        root=new node();
        scanf("%lld",&n);
        for(i=0; i<n; ++i)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            x1++;
            y1++;
            x2++;
            if(ind[x1]==0)
            {
                ind[x1]=c++;
                xpos.push_back(make_pair(x1,ind[x1]));
            }
            if(ind[x2]==0)
            {
                ind[x2]=c++;
                xpos.push_back(make_pair(x2,ind[x2]));
            }
            y_st[ind[x1]].push_back(make_pair(y1,y2));

            y_ed[ind[x2]].push_back(make_pair(y1,y2));

        }
        ans=0;
        sort(xpos.begin(),xpos.end());
        k=xpos[0].second;
        for(i=0; i<y_st[k].size(); ++i)
        {
            update(root,1,LIM,y_st[k][i].first,y_st[k][i].second,1);
        }
        pre=xpos[0].first;
        for(j=1; j<xpos.size(); ++j)
        {
            //     print(root,1,LIM) ;
            pls=root->on;

            k=xpos[j].second;
            for(i=0; i<y_st[k].size(); ++i)
            {
                update(root,1,LIM,y_st[k][i].first,y_st[k][i].second,1);
            }
            for(i=0; i<y_ed[k].size(); ++i)
            {


                update(root,1,LIM,y_ed[k][i].first,y_ed[k][i].second,-1);
            }
            k=pls;
            if(k)
                ans+=(k-0)*(xpos[j].first-pre);
            //    printf("%lld\n",ans);
            pre=xpos[j].first;
        }
        printf("Case %lld: %lld\n",ti,ans);
        del(root);
    }
    return 0;
}
