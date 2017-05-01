#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;

string s;
char str[100005];

int main()
{
    int t,ti,n,m,i,j,k,l,ans;
    bool flag;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        printf("Case %d:\n",ti);
        scanf("%d",&n);
        mp.clear();
        ans=1;
        while(n--)
        {
            cin >> s;
            if(s.size()>2)
                sort(s.begin()+1,s.end()-1);
            //cout << s << endl;
            ++mp[s];
        }
        scanf("%d",&m);
        gets(str);
        while(m--)
        {
            ans=1;
            gets(str);
            l=strlen(str);
            flag=0;
            i=0;
            while(1)
            {
              //  puts("p");
                s="";
                while(i<l)
                {
                    if(str[i] != ' ')
                        break;
                    ++i;
                }
                if(i>=l)
                    break;
                while(i<l)
                {
                    if(str[i] == ' ')
                        break;
                    s=s+str[i];
                    ++i;
                }
                if(s.size()>2)
                    sort(s.begin()+1,s.end()-1);
                ans=ans*mp[s];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
