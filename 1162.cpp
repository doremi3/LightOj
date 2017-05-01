#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define MAX 100005
typedef pair<int,int> pii;

vector<int> adj[MAX];
map<pii,int> mapi;

int n;
int par[MAX][30],maxi[MAX][30],mini[MAX][30],vis[MAX],l[MAX];

void dfs(int u, int dep)
{
    vis[u]=1;
    l[u]=dep;
    int i,v;
    for(i=0; i<adj[u].size(); ++i)
    {
        v=adj[u][i];
        if(!vis[v])
        {
            par[v][0]=u;
            dfs(v,dep+1);
        }
    }
}

void parent()
{
    int i,j;
    for(j=1; j<30; ++j)
    {
        for(i=1; i<=n; ++i)
        {
            if(par[i][j-1] != -1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    }
}

int lca(int a,int b)
{
    int p,q,i,j;
    p=a;
    q=b;
    if(l[p]<l[q])
        swap(p,q);
    for(j=28; j>=0; --j)
    {
        if(l[p]-(1<<j) >= l[q])
            p=par[p][j];
    }
    if(p==q)
        return p;
    for(j=28; j>=0; --j)
    {
        if(par[p][j] !=-1 && par[q][j] !=1 && par[p][j] != par[q][j])
        {
            p=par[p][j];
            q=par[q][j];
        }
    }
    return par[p][0];

}

void MaxMinTable()
{
    int i,j,k;
    for(i=1; i<=n; ++i)
    {
        if(par[i][0]==-1)
            continue;
        j=min(i,par[i][0]);
        k=max(i,par[i][0]);
        mini[i][0]=maxi[i][0]=mapi[make_pair(j,k)];
    }
    for(j=1; j<30; ++j)
    {
        for(i=1; i<=n; ++i)
        {
            if(par[i][j]==-1)
                continue;
            mini[i][j] = min (mini[i][j-1], mini[par[i][j-1]][j-1]);
            maxi[i][j] = max (maxi[i][j-1], maxi[par[i][j-1]][j-1]);
        }
    }
}

pii findMaxMin(int a,int b)
{
    int p,q,i;
    pii ret;
    p=a;
    q=b;
    if(l[p]<l[q])
        swap(p,q);
    ret.first=99999999;
    ret.second=-99;
    for(i=28; i>=0 ; --i)
    {
        if(l[p]-(1<<i) >= l[q])
        {
            ret.first=min(ret.first, mini[p][i]);
            ret.second=max(ret.second, maxi[p][i]);
            p=par[p][i];
        }
    }
    return ret;

}
int main()
{
    int t,ti,u,v,w,i,j,a,b,q,k;
    pii ans1,ans2;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d",&n);
        mapi.clear();
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        for(i=1; i<=n; ++i)
            adj[i].clear();
        for(i=0; i<n-1; ++i)
        {
            scanf("%d %d %d",&u,&v,&w);
            a=min(u,v);
            b=max(u,v);
            adj[a].push_back(b);
            adj[b].push_back(a);
            mapi[make_pair(a,b)]=w;
        }
        dfs(1,0);
        parent();
        MaxMinTable();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&i, &j);
            k=lca(i,j);
            ans1=findMaxMin(i,k);
            ans2=findMaxMin(j,k);
            printf("%d %d\n",min(ans1.first,ans2.first),max(ans1.second,ans2.second));
        }
    }
    return 0;
}
