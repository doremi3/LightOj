#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;


#define MAX 30000

vector<int> adj[MAX+3];

int t[MAX*2 + 10], tree[MAX*7],vis[MAX+10],d[MAX+10],f[MAX+10],l[MAX+30],a[MAX+10],tm,n;
int par[MAX+10][33];

void init(int node,int st,int ed)
{
    if(st>ed)
        return;
    if(st==ed)
    {
        tree[node]=t[st];
        return;
    }

    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    init(lc,st,mid);
    init(rc,mid+1,ed);
    tree[node]=tree[lc]+tree[rc];
}

void update(int node,int st,int ed,int i,int v)
{
    if(st>ed)
        return;
    if(st==ed && st==i)
    {
        tree[node]=v;
        return;
    }
    if(st>i || ed<i)
        return;
    int lc,rc,mid;
    lc=2*node;
    rc=lc+1;
    mid=(st+ed)/2;

    update(lc,st,mid,i,v);
    update(rc,mid+1,ed,i,v);
    tree[node]=tree[lc]+tree[rc];
}

int query(int node,int st,int ed,int i,int j)
{
    if(st>ed)
        return 0;
    if(st>j || ed<i)
        return 0;
    if(st>=i && ed<=j)
        return tree[node];

    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;
    return query(lc,st,mid,i,j) + query(rc,mid+1,ed,i,j);
}

void dfs(int u,int dep)
{
    int v,i,j;
    ++tm;
    vis[u]=1;
    t[tm]=a[u];
    d[u]=tm;
    l[u]=dep;
    for(i=0; i<adj[u].size(); ++i)
    {
        v=adj[u][i];
        if(!vis[v]){
            par[v][0]=u;
            dfs(v,dep+1);
        }
    }
    ++tm;
    t[tm]=-a[u];
    f[u]=tm;

}

void makeTable()
{
    int i,j;
    for(j=1; j<=30; ++j)
    {
        for(i=1; i<=n; ++i){
            if(par[i][j-1] != -1)
                par[i][j] = par[par[i][j-1]][j-1];
        }
    }

}

int lca(int u,int v)
{
    if(l[u]<l[v])
        swap(u,v);
    int dif=l[u]-l[v];
    int p,q,i;
    p=u;
    q=v;
    for(i=30 ; i>=0; --i)
    {
        if(l[p] -(1<<i) >= l[q])
            p=par[p][i];
    }
    if(p==q)
        return p;
    for(i=30; i>=0; --i)
    {
        if(par[p][i] !=-1 && par[q][i] !=-1 && par[p][i] != par[q][i])
        {
            p=par[p][i];
            q=par[q][i];
        }
    }
    return par[p][0];
}

int main()
{
    int T,ti,u,v,i,j,k,q,type;
    scanf("%d",&T);
    for(ti=1; ti<=T; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d",&n);
        for(i=0; i<=n; ++i)
            adj[i].clear();
        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        for(i=1; i<=n-1; ++i)
        {
            scanf("%d %d",&u,&v);
            u++;
            v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tm=0;
        memset(t,0,sizeof(t));
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        dfs(1,0);
        makeTable();
        init(1,1,n*2);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d %d",&i,&j,&k);
            j++;
            if(i==1){
                update(1,1,n*2,d[j],k);
                update(1,1,n*2,f[j],-k);
                a[j]=k;

            }
            else
            {
                k++;

                v=query(1,1,n*2,1,d[j]);
                v+=query(1,1,n*2,1,d[k]);
                u=lca(j,k);
                v-=a[u];
                if(par[u][0] !=-1){
                    u=par[u][0];
                    v-=2*query(1,1,n*2,1,d[u]);
                }
                printf("%d\n",v);
            }
        }

    }
    return 0;
}
