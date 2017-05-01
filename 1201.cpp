#include<bits/stdc++.h>
using namespace std;

#define MAX 1010

int vis[MAX],dp[MAX][2],n,m;
vector<int> v[MAX];

int cal(int i, int p)
{
    //printf("%d %d\n",i,p);
    vis[i]=1;
    if(dp[i][p] != -1)
        return dp[i][p];
    int j,k,ret1,ret2;
    ret1=ret2=0;
    if(p==1)
        ret1=1;
    for(j=0; j<v[i].size(); ++j)
    {
        k=v[i][j];
        if(vis[k]==1)
            continue;
        if(p==1)
            ret1+=cal(k,0);
        ret2+=cal(k,1);
    }
    vis[i]=2;
    return dp[i][p]=max(ret1,ret2);
}

int main()
{
    int t,ti,i,j,k,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d %d",&n,&m);
        for(i=1; i<=n; ++i)
            v[i].clear();
        while(m--)
        {
            scanf("%d %d",&i,&j);
            v[i].push_back(j);
            v[j].push_back(i);
        }
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        ans=0;
        for(i=1; i<=n; ++i)
        {
            if(!vis[i])
                ans+=cal(i,1);
        }
        printf("Case %d: %d\n",ti,ans);
    }
    return 0;
}
