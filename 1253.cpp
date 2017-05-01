#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,ti,n,i,j,k,ans,flag;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ ti)
    {
        scanf("%d",&n);
        ans=0;
        flag=0;
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            if(j>1)
                flag=1;
            ans=ans^j;
        }
        if((flag==1 && ans==0) || (flag==0 && ans==1))
            printf("Case %d: Bob\n",ti);
        else
            printf("Case %d: Alice\n",ti);
    }
    return 0;
}
