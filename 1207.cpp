#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 200010

int tree[MAX*3 + 100],flag[MAX+5];

void cal(int node,int st,int ed,int lazy)
{
    if(st>ed)
        return;
    if(st==ed)
    {
        flag[max(tree[node],lazy)]=1;
        return;
    }
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;
    cal(lc,st,mid, max(lazy,tree[node]));
    cal(rc,mid+1,ed,max(lazy,tree[node]));
}

void update(int node,int st,int ed,int i,int j,int c)
{
    if(st>ed)
        return;
    if(st>j || ed<i)
        return;
    if(st>=i && ed<=j)
    {
        tree[node]=c;

        return;
    }
    if(st==ed)
        return;
    int mid,lc,rc;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;
    update(lc,st,mid,i,j,c);
    update(rc,mid+1,ed,i,j,c);
}

int main()
{
    int t,ti,i,j,k,st,ed,n,c;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(tree,0,sizeof(tree));
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        for(i=1; i<=n; ++i)
        {
            scanf("%d %d",&st,&ed);
            update(1,1,MAX-1,st,ed,i);
        }
        cal(1,1,MAX-1,0);
        c=0;
        for(i=1; i<=n; ++i)
        {
            c+=flag[i];
        }
        printf("Case %d: %d\n",ti,c);
    }
    return 0;
}
