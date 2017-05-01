#include<stdio.h>
#include<vector>
#include<algorithm>

#define MAX 1500000
#define inf 999999999

using namespace std;
typedef long long ll;

int flag[1500000],tree[5000000];

int n;

vector<int> lucky;

int cal(int node,int st,int ed ,int cnt)
{
    if(st>ed)
        return 0;
    if(st==ed)
        return ed;
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    if(tree[lc]>=cnt)
        return cal(lc,st,mid,cnt);
    return cal(rc,mid+1,ed,cnt-tree[lc]);
}

void init(int node,int st,int ed)
{
    if(st>ed)
        return;
    if(st==ed){
        tree[node]=flag[st];
        return ;
    }

    int mid,lc,rc;

    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    init(lc,st,mid);
    init(rc,mid+1,ed);

    tree[node]=tree[lc]+tree[rc];
}
void update(int node,int st,int ed,int pos)
{
    if(st>ed)
        return;
    if(st==ed && pos==st)
    {
        flag[pos]=0;
        tree[node]=0;
        return;
    }
    if(st==ed)
        return;
    if(st>pos || ed<pos)
        return;

    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=node*2;
    rc=lc+1;

    update(lc,st,mid,pos);
    update(rc,mid+1,ed,pos);

    tree[node]=tree[lc]+tree[rc];

}

int query(int node,int st,int ed ,int i,int j)
{
    if(st>ed)
        return 0;
    if(st>=i && ed<=j)
        return tree[node];
    if(st>j || ed<i)
        return 0;
    int lc,rc,mid;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    return query(lc,st,mid,i,j) + query(rc, mid+1, ed,i,j);
}

int bs(int lo,int hi,int val)
{
    if(lo>hi)
        return inf;
    if(lo==hi && query(1,1,MAX-1,0,lo)==val)
        return lo;
    if(lo==hi)
        return inf;
    int mid=(lo+hi)/2;


    int k=query(1,1,MAX-1,0,mid);
    if(k<val)
        return bs(mid+1,hi,val);
    return min(mid, bs(lo,mid,val));

}



int main()
{
    int t,ti,i,j,k,c,m;
    for(i=1; i<MAX; i+=2)
        flag[i]=1;
    init(1,1,MAX-1);
    m=2;
    for(j=3; j<100000 ;)
    {
        c=0;
       k=cal(1,1,MAX-1,j);
        update(1,1,MAX-1,k);
        ++c;
        for(i=j+j; i<MAX; i+=j)
        {
            update(1,1,MAX-1,cal(1,1,MAX-1, i-c));
            ++c;
        }
        ++m;
        k=cal(1,1,MAX-1,m);
        j=k;

    }
    lucky.push_back(0);
    for(i=1; i<MAX; ++i)
    {
        if(flag[i])
            lucky.push_back(i);
    }
   // printf("%d\n",lucky[100000]);
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",ti,lucky[n]);
    }
    return 0;
}
