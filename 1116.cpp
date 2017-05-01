#include<bits/stdc++.h>
using namespace std;

int a[110],vis[110];

int dfs(int u)
{
    vis[u]=1;
    if(vis[a[u]])
        return 1;
    return 1+dfs(a[u]);
}

int main()
{
    int t,ti,i,j,k,n,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        memset(vis,0,sizeof(vis));
        ans=0;
        for(i=1; i<=n; ++i)
        {
            if(!vis[i])
                ans+=dfs(i)-1;
        }
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
