#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 100005



int sum[MAX*3 +100],lazy[MAX*3 +100], tim[MAX*3 +100],n;
bool flag[MAX*3 +100];

int query(int node,int st,int ed,int i,int j,int v,int c)
{

    if(st>ed)
        return 0;
    if(st>j || ed<i){
        return 0;
    }
    if((st>=i && ed<=j) && (flag[node] || st==ed))
    {
       // printf("%d %d\n",st,ed);
        if(c>tim[node]){
            return v*(ed-st+1);
        }

        return sum[node];

    }

    int mid,lc,rc,cr,vl;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    if(c>tim[node]){
        cr=c;
        vl=v;
    }
    else
    {
        cr=tim[node];
        vl=lazy[node];
    }
    int ret;
    ret= query(lc,st,mid,i,j,vl,cr) + query(rc,mid+1,ed,i,j,vl,cr);

    //printf("%d %d %d %d %d\n",st,ed,i,j,ret);
    return ret;
}

void update(int node,int st,int ed,int i,int j,int v,int c)
{

    if(st>ed)
        return;
    if(st>j || ed<i){
        return;
    }
    if(st>=i && ed<=j)
    {
        lazy[node]=v;
        sum[node]=v*(ed-st+1);
        tim[node]=c;
        flag[node]=1;
      //  printf("%d %d %d\n",st,ed,sum[node]);
        return;
    }

    int mid,lc,rc;
    mid=(st+ed)/2;
    lc=2*node;
    rc=lc+1;

    update(lc,st,mid,i,j,v,c);
    update(rc,mid+1,ed,i,j,v,c);
    flag[node]=0;
    //sum[node]=sum[lc]+sum[rc];
    //tim[node]=c;
    //printf("%d %d %d\n",st,ed,sum[node]);
    return;
    //sum[node]=query(1,1,n,st,mid,0,0)+query(1,1,n,mid+1,ed,0,0);
}



int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int t,ti,i,j,v,m,q,c,cnt,g;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(sum,0,sizeof(sum));
        memset(lazy,0,sizeof(lazy));
        memset(tim,0,sizeof(tim));
        memset(flag,0,sizeof(flag));
        scanf("%d %d",&n,&q);
        c=1;
        printf("Case %d:\n",ti);
        while(q--)
        {
            scanf("%d",&m);
            if(m==1)
            {
                scanf("%d %d %d",&i, &j, &v);
                i++;
                j++;
                update(1,1,n,i,j,v,c);
                ++c;
            }
            else
            {
                scanf("%d %d",&i,&j);
                i++;
                j++;
                v= query(1,1,n,i,j,0,0);
                cnt=j-i+1;
                g=gcd(max(v,cnt),min(v,cnt));
                v/=g;
                cnt/=g;
                if(cnt>1)
                    printf("%d/%d\n",v,cnt);
                else
                    printf("%d\n",v);
            }
        }

    }
    return 0;
}
