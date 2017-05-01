#include<bits/stdc++.h>
using namespace std;

#define MAX 200005

typedef pair<int,int> pii;

int tree[MAX*4];

vector<pii> vn,vm;
int n,m;

void update(int node, int st,int ed, int i)
{
    if(st>ed)
        return;
    if(i>ed || i<st)
        return;
    if(st==ed)
    {
        tree[node]=1;
        return;
    }
    int mid=(st+ed)/2;
    int lc=2*node;
    int rc=lc+1;
    update(lc,st,mid,i);
    update(rc,mid+1,ed,i);
    tree[node]=tree[lc]+tree[rc];
}

int query(int node,int st,int ed,int i, int j)
{
    if(st>ed || i>ed || j<st)
        return 0;
    if(st>=i && ed<=j)
        return tree[node];
    int mid=(st+ed)/2;
    int lc,rc;
    lc=2*node;
    rc=lc+1;
    return query(lc,st,mid,i,j)+query(rc,mid+1,ed,i,j);
}
int main()
{
    int t,ti,i,j,k;
    long long ans,temp;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        vn.clear();
        vm.clear();
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&m);
        for(i=0; i<n; ++i)
        {
            scanf("%d %d",&j,&k);
            vn.push_back(make_pair(j,k));
        }
        for(i=0; i<m; ++i)
        {
            scanf("%d %d",&j,&k);
            vm.push_back(make_pair(j,k));
        }
        sort(vn.begin(),vn.end());
        sort(vm.begin(),vm.end());
        j=0;
        ans=0;
        for(i=0; i<vn.size(); ++i)
        {
            while(j<vm.size())
            {
                if(vm[j].first>= vn[i].first)
                    break;
                update(1,1,n+m,vm[j].second);
                ++j;
            }
            temp=query(1,1,n+m,vn[i].second,n+m);
            ans+=temp;
        }
        memset(tree,0,sizeof(tree));
        j=0;
        for(i=0; i<vm.size(); ++i)
        {
            while(j<vn.size())
            {
                if(vn[j].first>= vm[i].first)
                    break;
                update(1,1,n+m,vn[j].second);
                ++j;
            }
            temp=query(1,1,n+m,vm[i].second,n+m);
            ans+=temp;
        }
        printf("Case %d: %lld\n",ti,ans);
    }
    return 0;
}
