#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define MAX 505
typedef pair<int,int> pii;

int n;

struct edge{
    int st,ed,w;
};

vector<edge> tree,graph;
vector<pii>adj[MAX];
int par[MAX],vis[MAX],maxi[MAX];

bool cmp(edge a,edge b)
{
    return a.w<=b.w;
}

int findroot(int u)
{
    if(u==par[u])
        return u;
    return par[u]=findroot(par[u]);
}
void mst()
{
    int i,j,k,u,v,pu,pv;
    for(i=0; i<n; ++i)
        par[i]=i;
    for(i=0; i<graph.size() && tree.size()<n-1; ++i)
    {
        u=graph[i].st;
        v=graph[i].ed;
        pu=findroot(u);
        pv=findroot(v);
        if(pu != pv)
        {
            tree.push_back(graph[i]);
            par[pu]=par[pv];
        }
    }

}

void buildgraph()
{
    int i,j,u,v;
    for(i=0; i<tree.size(); ++i)
    {
        u=tree[i].st;
        v=tree[i].ed;
        adj[u].push_back(make_pair(v,tree[i].w));
        adj[v].push_back(make_pair(u,tree[i].w));
    }
}

void dfs(int u)
{
    int i,j,v;
    vis[u]=1;
    for(i=0; i<adj[u].size(); ++i)
    {
        v=adj[u][i].first;
        if(!vis[v])
        {
            maxi[v]=max(maxi[u],adj[u][i].second);
            dfs(v);
        }
    }

}

int main()
{
    int t,ti,m,i,j,k,d,s,u,v;
    edge e;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d %d",&n, &m);
        for(i=0; i<n; ++i)
            adj[i].clear();
        tree.clear();
        graph.clear();
        memset(vis,0,sizeof(vis));
        memset(maxi,-1,sizeof(maxi));
        while(m--)
        {
            scanf("%d %d %d",&e.st, &e.ed, &e.w);
            graph.push_back(e);

        }
        sort(graph.begin(),graph.end(),cmp);
        mst();
        buildgraph();
        scanf("%d",&s);
        maxi[s]=0;
        dfs(s);
        for(i=0; i<n; ++i)
        {
            if(maxi[i]==-1)
                puts("Impossible");
            else
                printf("%d\n",maxi[i]);
        }
    }
    return 0;
}
