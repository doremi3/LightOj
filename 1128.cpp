#include<stdio.h>
#include<string.h>

#define MAX 100005

int par[MAX][30],val[MAX];

void makeTable(int n)
{
    int i,j,k,p;
    for(j=1; j<30; ++j)
    {
        for(i=0; i<n; ++i)
        {
            if(par[i][j-1] != -1)
            {
                par[i][j]= par[par[i][j-1]][j-1];
            }
        }
    }
}

int query(int node,int v)
{
    int i,j,k;
    i=node;
    for(j=29; j>=0; --j)
    {
        if(par[i][j] != -1 && val[par[i][j]] >= v)
        {
            i=par[i][j];
        }
    }
    return i;
}

int main()
{
    int t,ti,n,q,i,p,j;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        memset(par,-1,sizeof(par));
        scanf("%d %d",&n,&q);
        val[0]=1;
        for(i=1; i<=n-1; ++i)
        {
            scanf("%d %d",&par[i][0],&val[i]);
        }
        makeTable(n);
        while(q--)
        {
            scanf("%d %d",&i,&j);
            printf("%d\n",query(i,j));
        }
    }
    return 0;
}
