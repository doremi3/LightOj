#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 505
#define inf 9999999

int a[MAX][MAX], tree[MAX][3*MAX];

void init(int k,int node,int st,int ed)
{
    if(st>ed)
        return;
    if(st==ed)
    {
        tree[k][node]=a[k][st];
        return;
    }

    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    init(k,lc,st,mid);
    init(k,rc,mid+1,ed);

    tree[k][node]=max(tree[k][lc],tree[k][rc]);
}

int query(int k,int node,int st,int ed,int i,int j)
{
    if(st>ed)
        return -inf;
    if(i>ed || j<st)
        return -inf;
    if(st>=i && ed<=j)
        return tree[k][node];
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    return max(query(k,lc,st,mid,i,j), query(k,rc,mid+1,ed,i,j));
}


int main()
{
    int t,ti,i,j,n,k,l,p,q,Q,s,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d %d",&n, &Q);
        for(p=k=1; p<=n; ++p)
        {
            for(q=1; q<=n; ++q)
                scanf("%d",&a[p][q]);
        }
        for(i=1; i<=n; ++i)
            init(i,1,1,n);
        while(Q--)
        {
            scanf("%d %d %d",&i,&j,&s);

            ans=-inf;
            for(k=i ; k<=i+s-1; ++k)
            {
                ans=max(ans,query(k,1,1,n,j,j+s-1));
            }
            printf("%d\n",ans);
        }
    }
   return 0;
}
