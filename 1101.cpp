#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define MAX 50005

struct edge{
    int st,ed,w;
};

typedef struct edge edge;
typedef pair<int,int> pii;

vector<edge> v,tree;
vector<int> adj[MAX];
map <pii,int> mapi;
int T[MAX],l[MAX],par[MAX][30],vis[MAX],maxi[MAX][30];
int n;

bool cmp(edge a,edge b)
{
    return a.w<=b.w;
}

int findroot(int u)
{
    if(u==T[u])
        return u;
    return T[u]=findroot(T[u]);
}

void mst()
{
    int a,b,pa,pb,i;
    sort(v.begin(),v.end(),cmp);
    tree.clear();
    for(i=1; i<=n; ++i)
        T[i]=i;

    for(i=0; i<v.size() && tree.size()<n-1; ++i)
    {
        a=v[i].st;
        b=v[i].ed;
        pa=findroot(a);
        pb=findroot(b);
        if(pa != pb)
        {
            tree.push_back(v[i]);
            T[pa]=T[pb];
        }
    }
}

void buildgraph()
{
    int i,j,u,a,b;
    mapi.clear();
    for(i=1; i<=n; ++i)
        adj[i].clear();
    for(i=0; i<tree.size(); ++i)
    {
        a=tree[i].st;
        b=tree[i].ed;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mapi[make_pair(min(a,b),max(a,b))]=tree[i].w;
    }
}

void dfs(int a,int dep)
{
    int i,b,j;
    l[a]=dep;
    vis[a]=1;
    for(i=0; i<adj[a].size(); ++i)
    {
        b=adj[a][i];
        if(vis[b]==0){
            par[b][0]=a;
            dfs(b,dep+1);
        }
    }
}

void makeTable()
{
    int i,j,a,b,k;
    for(j=1; j<30; ++j)
    {
        for(i=1; i<=n; ++i)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
    for(i=1; i<=n; ++i)
    {
        k=par[i][0];
        a=min(i,k);
        b=max(i,k);
        maxi[i][0]=mapi[make_pair(a,b)];
    }
    for(j=1; j<30; ++j)
    {
        for(i=1; i<=n; ++i)
        {
            if(par[i][j]==-1)
                continue;
            k=par[i][j-1];
            maxi[i][j]=max(maxi[i][j-1], maxi[k][j-1]);
        }
    }
}

int lca(int a,int b)
{
    int p=a;
    int q=b;
    if(l[p]<l[q])
        swap(p,q);
    int i,j,k;
    for(i=28; i>=0; --i)
    {
        if(l[p]-(1<<i) >= l[q])
            p=par[p][i];
    }
    if(p==q)
        return p;
    for(i=28; i>=0; --i)
    {
        if(par[p][i] !=-1 && par[q][i] !=-1 && par[p][i] != par[q][i])
        {
            p=par[p][i];
            q=par[q][i];
        }
    }
    return par[p][0];
}

int findmax(int a,int b)
{
    int p,q,i,j,k,ret;
    p=a;
    q=b;
    ret=0;
    if(l[p]<l[q])
        swap(p,q);
    for(i=28; i>=0; --i)
    {
        if(l[p]-(1<<i) >=l[q])
        {
            ret=max(ret,maxi[p][i]);
            p=par[p][i];
        }
    }
    return ret;
}

int main()
{
    int t,ti,m,q,x,y,d,s,i;
    edge e;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d %d",&n,&m);
        v.clear();
        while(m--)
        {
            scanf("%d %d %d",&e.st, &e.ed, &e.w);
            v.push_back(e);
        }
        mst();
        buildgraph();
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        memset(maxi,0,sizeof(maxi));
        dfs(tree[0].st,0);
        makeTable();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            s=lca(x,y);
            printf("%d\n",max(findmax(x,s),findmax(y,s)));
        }

    }
    return 0;
}
