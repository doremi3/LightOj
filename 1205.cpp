#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[20][2];

string sa,sb;

string tostr(ll n)
{
    ll m=n;
    string ret="";
    while(m)
    {
        ret.push_back((m%10)+'0');
        m/=10;
    }
    if(ret.size()==0)
        ret="0";
    reverse(ret.begin(),ret.end());
    return ret;
}

ll cal(int i, bool eq,string s, int n)
{
    if(i==n)
        return 1;
    if(dp[i][eq] != -1)
        return dp[i][eq];
    ll ret=0;
    if(!eq)
        ret=10*(i+1,0,s,n);
    else
    {
        ret=(s[i]-'0')*cal(i+1,0,s,n);
        ret+=cal(i+1,1,s,n);
    }
    return dp[i][eq]=ret;
}
bool poss(string s)
{
    int i,j;
    string rev=s;
    for(i=0,j=s.size()-1;i<j; ++i,--j)
        rev[j]=s[i];
    return(rev<=s);
}
ll cnt(string s)
{
    ll i,j,k,l,temp,ret=0;
    memset(dp,-1,sizeof(dp));
    for(i=1; i<s.size(); i++)
    {
        k=ceil(i/2.0);
        temp=9;
        for(j=2; j<=k; ++j)
            temp=temp*10;
        ret+=temp;
    }

    ret+=(s[0]-'1')*cal(1,0,s,ceil(s.size()/2.0));
    ret+=cal(1,1,s,ceil(s.size()/2.0));
    if(!poss(s))
        ret--;
    cout << ret << endl;
    return ret;

}

bool ispalin(string s)
{
    int i,j;
    for(i=0; j=s.size()-1, i<j; ++i,--j)
    {
        if(s[i] != s[j])
            return 0;
    }
    return 1;
}

int main()
{
    ll t,ti,i,j,k,a,b,ans;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%lld %lld",&a,&b);
        if(a>b)
            swap(a,b);
        sa=tostr(a);
        sb=tostr(b);
        b==cnt(sb);
        a=cnt(sa);
        cout << a<< " " << b<< endl;
        ans=b-a;
        if(ispalin(sa))
            ++ans;
        printf("Case %lld: %lld\n",ti,ans);
    }
    return 0;
}
