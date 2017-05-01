#include<bits/stdc++.h>
using namespace std;

int flag[1000100];

int main()
{
    int t,ti,n,i,j,k,f;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        f=0;
        memset(flag,0,sizeof(flag));
        scanf("%d",&n);
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            if(!flag[j+1])
                flag[j+1]++;
            else
                flag[n-j]++;
        }
        for(i=1; i<=n; ++i)
        {
            if(flag[i] != 1)
            {
                f=1;
                break;
            }
        }
        if(f)
            printf("Case %d: no\n",ti);
        else
            printf("Case %d: yes\n",ti);
    }
    return 0;
}
