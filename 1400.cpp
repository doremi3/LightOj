#include<bits/stdc++.h>
using namespace std;

queue<int> q[210];
queue<int> lft;

int a[210][210],match[210];

int main()
{
    int t,ti,n,i,j,k,curr,to;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        memset(match,0,sizeof(match));
        memset(a,0,sizeof(a));
        for(i=1; i<=n; ++i)
        {
            while(!q[i].empty())
                q[i].pop();
        }
        while(!lft.empty())
            lft.pop();
        for(i=1; i<=n; ++i)
            lft.push(i);
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                scanf("%d",&k);
                q[i].push(k);
            }
        }
        for(i=n+1; i<=2*n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                scanf("%d",&k);
                a[i][k]=j;
            }
        }
        while(!lft.empty())
        {
            curr=lft.front();
            lft.pop();
            to=q[curr].front();
            q[curr].pop();
            if(!match[to])
                match[to]=curr;
            else if(a[to][match[to]]>a[to][curr])
            {
                lft.push(match[to]);
                match[to]=curr;
            }
            else
            {
                lft.push(curr);
            }
        }
        printf("Case %d:",ti);
        for(i=n+1; i<=2*n; ++i)
        {
            printf(" (%d %d)",match[i],i);
        }
        puts("");
    }
    return 0;
}
