#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

ll c[100][100],pre[100],vis[100];

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

void maxflow(ll s)
{
    while(1)
    {
        if(bfs(s)==false)
            return;
    }
}

int main()
{
    ll i,j,k,ts,ti,e;
    scanf("%lld",&ts);
    for(ti=1; ti<=ts; ++ti){
    memset(c,0,sizeof(c));
    scanf("%lld",&n);
    scanf("%lld %lld %lld",&s,&t,&e);
    while(e--)
    {
        scanf("%lld %lld %lld",&i, &j,&k);
        if(i==0)
            break;
        c[i][j]+=k;
        c[j][i]+=k;
    }
    maxf=0;
    if(s != t)
        maxflow(s);
    printf("Case %lld: %lld\n",ti,maxf);
    }
    return 0;
}
