#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;

struct edge{
    int st,ed,w;
};

typedef struct edge edge;

map<string, int> mapi;
vector<edge> graph,tree;

int par[110],m,n;

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
    int ret=0;
    for(i=0; i<tree.size(); ++i)
        ret+=tree[i].w;
    if(tree.size()<n-1)
        ret=-1;
    return ret;
}

bool cmp(edge a,edge b)
{
    return a.w<=b.w;
}

int main()
{
    string u,v;
    edge e;
    int i,j,k,t,ti,d;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        n=0;
        graph.clear();
        mapi.clear();
        scanf("%d",&m);
        while(m--)
        {
            cin>>u>>v>>d;
            if(mapi[u]==0)
            {
                mapi[u]= ++n;
            }
            if(mapi[v]==0)
                mapi[v]= ++n;
            i=mapi[u];
            j=mapi[v];
            e.st=i;
            e.ed=j;
            e.w=d;
            graph.push_back(e);
        }
        sort(graph.begin(),graph.end(),cmp);
        k=mst();
        if(k==-1)
            printf("Case %d: Impossible",ti);
        else
            printf("Case %d: %d\n",ti,k);
    }
    return 0;
}


