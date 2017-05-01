#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[25];
ll f[22], cnt[30];
ll n;

void cal()
{
    ll l,i,j,k,curr,pre;
    l=strlen(s);
    sort(s,s+l);
    pre=1;
    for(i=l-1,j=1; i>=0; --i,++j)
    {
        ++cnt[s[i]-'a'];
        curr=(pre*j)/cnt[s[i]-'a'];
        if(curr>=n)
            break;
        pre=curr;
    }
    if(i<0){
        puts("Impossible");
        return;
    }
    k=s[i]-'a';
    pre=0;
   // pre=0;
   int save=0;
    for( ; i<l; ++i,--j)
    {
        for(k=0; k<26; ++k)
        {
            if(cnt[k]){

                curr=curr*cnt[k];
                curr=curr/j;
                if(pre+curr>=n)
                {
                    s[i]='a'+k;
                    --cnt[k];
                    break;
                }
                else{
                    save=curr;
                    pre=pre+save;
                    curr=curr*j;
                    curr=curr/cnt[k];
                }

            }
        }
    }
    puts(s);

}

int main()
{
    int t,ti,i,j,k;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%s %d",s,&n);
        printf("Case %d: ",ti);
        cal();
    }
    return 0;
}
