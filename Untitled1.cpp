#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 10000

vector <long long> d[MAX+5];

long long flag[MAX+5],cnt[MAX+5],c[MAX+5];
long long a[MAX+5],comb[MAX+5];

void seive()
{
    long long i,j;
    flag[1]=1;
    for(i=2; i<=MAX; ++i)
    {
        d[i].push_back(i);
        if(!flag[i])
            cnt[i]=1;
        for(j=i+i; j<=MAX; j+=i)
        {
            flag[j]=1;
            d[j].push_back(i);
            if(!flag[i] && cnt[j] !=-1)
            {
                cnt[j]++;
            }
            else if(flag[i] &&(cnt[i]==1 || cnt[i]==-1))
                cnt[j]=-1;
        }
    }
}
int main()
{
    long long t,ti,n,i,j,k,ans;
    seive();
    comb[4]=1;
    for(i=5; i<=MAX; ++i)
    {
        comb[i]=(comb[i-1]*i)/(i-4);
    }
    //printf("%lld\n",comb[MAX]);
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(c,0,sizeof(c));
        ans=0;
        scanf("%lld",&n);
        for(i=0; i<n; ++i)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0; i<n; ++i)
        {
            j=a[i];
            for(k=0; k<d[j].size(); ++k)
            {
                ++c[d[j][k]];
            }
        }
        for(i=2; i<=MAX; ++i)
        {
            if(c[i]<4 || (cnt[i]==1 && flag[i])|| cnt[i] ==-1)
                continue;
            j=comb[c[i]];
         //   printf("%lld\n",c[i]);
            if(cnt[i]&1)
                ans+=j;
            else
                ans-=j;
        }
        j=comb[n];
        if(n<4)
            j=0;
        if(ans<0)
            ans=0;
        ans=j-ans;
        printf("Case %lld: %lld\n",ti,ans);
    }
    return 0;
}
