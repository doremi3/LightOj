#include<bits/stdc++.h>
using namespace std;

int adj[205][205],n,w,pre[205];
vector<int> edge[205];

void dfs(int u,int par)
{
    pre[u]=par;
    int v,i;
    for(i=0; i<edge[u].size(); ++i)
    {
        v=edge[u][i];
        if(pre[v]==0)
            dfs(v,u);
    }
}

int main()
{
    int t,ti,i,j,k,total,flag,u,v,maxi,st,ed,a,b;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(adj,0,sizeof(adj));
        for(i=1; i<=n; ++i)
            edge[i].clear();
        total=0;
        flag=0;
        scanf("%d %d",&n,&w);
        printf("Case %d:\n",ti);
        while(w--)
        {
            scanf("%d %d %d",&i,&j,&k);
            memset(pre,0,sizeof(pre));
            dfs(i,i);
            if(!pre[j])
            {
               // puts("p");
                total+=k;
                adj[i][j]=adj[j][i]=k;
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
            else
            {
                u=j;
                maxi=0;
                while(u!=i)
                {
                    if(adj[u][pre[u]]>maxi)
                    {
                        maxi=adj[u][pre[u]];
                        st=pre[u];
                        ed=u;
                    }
                    u=pre[u];
                }
                if(maxi>k){
                    adj[st][ed]=adj[ed][st]=0;
                    adj[i][j]=adj[j][i]=k;
                    for(a=0; a<edge[st].size(); ++a)
                    {
                        if(edge[st][a]==ed)
                        {
                            edge[st].erase(edge[st].begin()+a);
                            break;
                        }
                    }
                    for(a=0; a<edge[ed].size(); ++a)
                    {
                        if(edge[ed][a]==st)
                        {
                            edge[ed].erase(edge[ed].begin()+a);
                            break;
                        }
                    }
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                    total=total-maxi+k;
                }
            }
            memset(pre,0,sizeof(pre));
            dfs(1,1);
            for(i=1; i<=n; ++i)
            {
                if(!pre[i])
                    break;
            }
         //   printf("%d\n",i);
            if(i<=n)
                puts("-1");
            else
                printf("%d\n",total);

        }
    }
    return 0;
}
