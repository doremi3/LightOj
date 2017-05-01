#include<bits/stdc++.h>

using namespace std;

#define MAX 103

char a[MAX],b[MAX];
string dp[MAX][MAX];
int f[MAX][MAX];
int la,lb;

string cal(int i,int j)
{
    if(i==la || j==lb)
        return "";
    if(f[i][j] !=-1)
        return dp[i][j];
    f[i][j]=0;
    if(a[i]==b[j])
        return dp[i][j]=a[i]+cal(i+1,j+1);
    string ret1,ret2;
    int k;
    ret1=cal(i+1,j);
    ret2=cal(i,j+1);
    if(ret1.size()>ret2.size())
        return dp[i][j]=ret1;
    if(ret2.size() > ret1.size())
        return dp[i][j]=ret2;
    for(k=0; k<ret1.size(); ++k)
    {
        if(ret1[k]<ret2[k])
            return dp[i][j]=ret1;
        if(ret2[k]<ret1[k])
            return dp[i][j]=ret2;
    }
    return dp[i][j]=ret1;

}

int main()
{
    int t,ti,i,j,k;
    string ans;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%s %s",a,b);
        la=strlen(a);
        lb=strlen(b);
        memset(f,-1,sizeof(f));
        printf("Case %d: ",ti);
        ans=cal(0,0);
        if(ans == ""){
            puts(":(");
        }
        else{
            cout << ans;
            puts("");
        }
    }
    return 0;
}
