#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define inf 9999999
#define MOD 100000007
vector<ll> v;
bool flag[100010];
ll dp[100010];

int lower(int lo,int hi, ll f)
{
    if(lo>hi)
        return -inf;
    if(lo==hi)
    {
        if(v[lo]<=f)
            return lo;
        return -inf;
    }
    int mid=(lo+hi)/2;
    if(v[mid]>f)
        return lower(lo,mid,f);
    return max(lower(mid+1,hi,f),mid);
}

ll cal(int i)
{
    if(i==1 || i==0)
        return 1;
    if(dp[i] != -1)
        return dp[i];
    ll ret=0;
    int j;
    for(j=0; j<i; ++j)
        ret=(ret+(cal(j)*cal(i-j-1))%MOD )%MOD;
    return dp[i]=ret;
}


int main()
{
    ll t,ti,a,b,i,j,k,ans;
    for(i=2; i<=100000; ++i)
    {
        if(flag[i])
            continue;
        for(j=i*i; j<=10000000000; j*=i)
        {
            v.push_back(j);
            if(j<=100000)
                flag[j]=1;
        }
    }
    sort(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&a,&b);
        i=lower(0,v.size()-1,a-1);
        j=lower(0,v.size()-1,b);
      //  printf("%lld %lld\n",i,j);
        if(j<0 || i==j )
            ans=0;
        else
        {
            if(i<0)
                k=j+1;
            else
                k=j-i;
            ans=cal(k);
            // printf("%lld %lld\n",v[i],v[j]);
        }
        printf("Case %lld: %lld\n",ti,ans);
    }
    return 0;
}
