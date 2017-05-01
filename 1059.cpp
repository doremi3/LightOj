#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 10005

int par[MAX],n,cnt;

struct edge{
    int st,ed,w;
};

typedef struct edge edge;

vector<edge> graph, tree;

bool cmp(edge a,edge b)
{
    return (a.w<b.w) ||( a.w==b.w && a.ed<b.ed) || ( a.w==b.w && a.ed==b.ed && a.st<b.st);
}

int findroot(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=findroot(par[u]);
}

int mst()
{
    int i,j,k,u,v,pu,pv,ret;
    for(i=0; i<=n; ++i)
        par[i]=i;
    tree.clear();
    ret=0;
    for(i=0; i<graph.size() && tree.size() < n; ++i)
    {
        u=graph[i].st;
        v=graph[i].ed;
        pu=findroot(u);
        pv=findroot(v);
        if(pu != pv)
        {
            tree.push_back(graph[i]);
            ret+=graph[i].w;
            if(graph[i].ed==0)
                ++cnt;
            par[pu]=par[pv];
        }
    }
    return ret;
}

int main()
{
    int t,ti,m,a,i,k,j;
    edge e;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d %d",&n, &m, &a);
        graph.clear();
        cnt=0;
        for(i=1; i<=n; ++i)
        {
            e.st=i;
            e.ed=0;
            e.w=a;
            graph.push_back(e);
        }
        while(m--)
        {
            scanf("%d %d %d",&e.st, &e.ed, &e.w);
            graph.push_back(e);
        }
        sort(graph.begin(),graph.end(),cmp);
        j=mst();
        printf("Case %d: %d %d\n",ti,j,cnt);
    }
    return 0;
}
