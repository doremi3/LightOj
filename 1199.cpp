#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int g[MAX+10];
bool flag[MAX+10];

int main()
{
    int t,ti,i,j,k,n,ans;
    g[1]=g[2]=0;
    for(i=3; i<=MAX; ++i)
    {
        memset(flag,0,sizeof(flag));
        for(j=1; j<i; ++j)
        {
            if(j>=i-j)
                break;
            if((g[j]^g[i-j]) <= MAX)
                flag[g[j]^g[i-j]]=1;

        }
        for(j=0; j<=i; ++j)
        {
            if(!flag[j])
                break;
        }
        g[i]=j;
    }
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            ans=ans^g[j];
        }
        if(ans)
            printf("Case %d: Alice\n",ti);
        else
            printf("Case %d: Bob\n",ti);
    }
    return 0;
}
