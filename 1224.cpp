#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
char s[55];
ll maxi;
int a[26];

struct node
{
    ll cnt;
    struct node* edge[4];

    node()
    {
        cnt=0;
        int i;
        for(i=0; i<4; ++i)
            edge[i]=NULL;
    }

};

typedef struct node node;

node *root;

void add(char s[],ll l)
{
    ll i,j;
    node *curr=root;
    for(i=0; i<l; ++i)
    {
        ++curr->cnt;
        j=a[s[i]-'A'];
        if(curr->edge[j]==NULL)
        {
            curr->edge[j]=new node();
        }
        curr=curr->edge[j];
    }
    ++curr->cnt;
}

void fnd(node *u, ll dep)
{
    maxi=max(maxi,dep*u->cnt);
    ll i,l,j,ch=0;
    //node *curr=root;
    for(i=0; i<4; ++i)
    {
        if(u->edge[i]!= NULL)
            fnd(u->edge[i],dep+1);
    }
}

void del(node *curr)
{
    ll i,j;
    if(curr==NULL)
        return ;
    for(i=0; i<4; ++i)
    {
        del(curr->edge[i]);
    }
    delete(curr);
}

int main()
{
    ll n,i,j,k,m,q,t,ti;
    a['A'-'A']=0;
    a['C'-'A']=1;
    a['G'-'A']=2;
    a['T'-'A']=3;
    scanf("%lld",&t);
    for(ti=1; ti<=t; ++ti)
    {
        root=new node();
        scanf("%lld",&n);
        maxi=0;
        for(i=0; i<n; ++i)
        {
            scanf("%s",s);
            m=strlen(s);
            add(s,m);
        }
        fnd(root,0);

        printf("Case %lld: %lld\n",ti,maxi);

        del(root);
    }
    return 0;
}


