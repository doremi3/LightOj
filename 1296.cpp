#include<bits/stdc++.h>
using namespace std;

int grundy(int n)
{
    if(n==1)
        return 0;
    if(n%2==0)
        return n/2;
    return grundy(n/2);
}

int main()
{
    int t,ti,n,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        j=0;
        while(n--)
        {
            scanf("%d",&i);
            j=j^grundy(i);
        }
        if(j)
            printf("Case %d: Alice\n",ti);
        else
            printf("Case %d: Bob\n",ti);
    }
    return 0;
}
