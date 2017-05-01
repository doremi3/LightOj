#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
    int st,ed,w;
};

vector<edge> graph,tree;

int par[55],n;

int findroot(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=findroot(par[u]);
}

int mst()
{
    int i,j,u,v,pu,pv,ret;
    for(i=0; i<=n; ++i)
        par[i]=i;
    tree.clear();
    ret=0;
    for(i=0; i<graph.size() && tree.size() <n-1; ++i)
    {
        u=graph[i].st;
        v=graph[i].ed;
        pu=findroot(u);
        pv=findroot(v);
        if(pu != pv)
        {
            tree.push_back(graph[i]);
            ret+=graph[i].w;
            par[pu]=par[pv];
           // printf("%d nn\n",graph[i].w);
        }
    }
    if(tree.size()<n-1)
        return -1;
    return ret;
}

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int main()
{
    int t,ti,i,j,d,total;
    edge e;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        graph.clear();
        total=0;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                scanf("%d",&d);
                total+=d;
                if(d)
                {
                    e.st=i;
                    e.ed=j;
                    e.w=d;
                    graph.push_back(e);
                }
            }
        }
        sort(graph.begin(),graph.end(),cmp);
        d=mst();
        if(d>=0)
            total-=d;
        else
            total=d;
        printf("Case %d: %d\n",ti,total);

    }
    return 0;
}
