#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 210
#define inf 9999

ll c[MAX][MAX],pre[MAX],vis[MAX];

queue <ll> q;

ll s,t,maxf,n;

bool bfs(ll u)
{
     memset(pre,0,sizeof(pre));
    memset(vis,0,sizeof(vis));
    ll i,j,v,fr,mini=99999;
    q.push(u);
    vis[u]=1;
    pre[u]=u;
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        if(fr==t)
        {
            i=t;
            while(i != s)
            {
                mini=min(mini,c[pre[i]][i]);
                i=pre[i];
            }
            i=t;
            while(i != s)
            {
                c[pre[i]][i]-=mini;
                c[i][pre[i]]+=mini;
                i=pre[i];
            }
            maxf+=mini;
            while(!q.empty())
                q.pop();
           // puts("p");
            return true;
        }
        for(i=1;i<=n; ++i)
        {
            if(c[fr][i]>0 && vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                pre[i]=fr;
            }
        }
    }
    return false;
}

ll maxflow(ll s)
{
    maxf=0;
    while(1)
    {
        if(bfs(s)==false)
            return maxf;
    }

}

int main()
{
    int T,ti;
    ll m,i,j,k,u,v,b,d;
    scanf("%d",&T);
    for(ti=1; ti<=T; ++ti)
    {
        memset(c,0,sizeof(c));
        scanf("%lld",&n);
        for(i=1; i<=n; ++i)
        {
            scanf("%lld",&k);
            u=2*i;
            v=u+1;
            c[u][v]=k;
        }
        scanf("%lld",&m);
        while(m--)
        {
            scanf("%lld %lld %lld",&i,&j,&k);
            u=(2*i)+1;
            v=(2*j);
            c[u][v]=k;
        }
        scanf("%lld %lld",&b,&d);
        while(b--)
        {
            scanf("%lld",&i);
            u=2*i;
            c[1][u]=inf;
        }
        while(d--)
        {
            scanf("%lld",&i);
            u=(2*i)+1;
            c[u][(2*n)+2]=inf;
        }
        s=1;
        t=(2*n)+2;
        n=(2*n)+2;
        printf("Case %d: %lld\n",ti,maxflow(s));

    }
    return 0;
}
