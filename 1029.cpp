#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 105

struct edge{
    int st,ed,w;
};

vector<edge> tree,graph;
int par[MAX],n;

bool mini(edge a,edge b)
{
    return a.w<=b.w;
}

bool maxi(edge a,edge b)
{
    return a.w>=b.w;
}

int findroot(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=findroot(par[u]);
}

int mst()
{
    int i,j,k,u,v,pu,pv;
    for(i=0; i<=n; ++i)
        par[i]=i;
    tree.clear();
    for(i=0; i<graph.size() && tree.size()<n; ++i)
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
    int ret=0;
    for(i=0; i<tree.size(); ++i)
        ret+=tree[i].w;
    return ret;
}

int main()
{
    int t,ti,i,j,k,u,v;
    edge e;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        graph.clear();

        scanf("%d",&n);
        while(1)
        {
            scanf("%d %d %d",&e.st, &e.ed, &e.w);
            if(e.st+e.ed+e.w==0)
                break;
            graph.push_back(e);
        }
        sort(graph.begin(),graph.end(),mini);
        u=mst();
        sort(graph.begin(),graph.end(),maxi);
        v=mst();
        u=u+v;
        if(u%2)
            printf("Case %d: %d/%d\n",ti,u,2);
        else
           printf("Case %d: %d\n",ti,u/2);
    }
    return 0;
}
