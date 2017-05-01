#include<bits/stdc++.h>
using namespace std;

#define MAX 110
int w[MAX],b[MAX];

int main()
{
    int t,ti,n,i,j,ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        for(i=0; i<n; ++i)
            scanf("%d",&w[i]);
        for(i=0; i<n; ++i)
            scanf("%d",&b[i]);
        ans=0;
        for(i=0; i<n; ++i)
            ans=ans^(b[i]-w[i]-1);

        if(ans)
            printf("Case %d: white wins\n",ti);
        else
            printf("Case %d: black wins\n",ti);
    }
    return 0;
}
