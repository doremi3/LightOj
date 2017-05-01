#include<bits/stdc++.h>
using namespace std;
#define MAX 100

double mat[MAX+5][MAX+5],e[MAX+5];


void echelon()
{
    int i,j,k;
    double d;
    for(i=1; i<=MAX; ++i)
    {
        d=mat[i][i];
        for(j=1; j<=MAX+1; ++j)
            mat[i][j]/=d;
        for(j=i+1; j<=MAX; ++j)
        {
            d=mat[j][i];
            for(k=1; k<=MAX+1; ++k)
            {
                mat[j][k]-=d*mat[i][k];
            }
        }
    }

}

void gauss()
{
    int i,j,k;
    double s;
    memset(e,0,sizeof(e));
    echelon();
    for(i=MAX ; i>=1; --i)
    {
        s=0;
        for(j=1; j<=MAX+1; ++j)
        {
            if(j==i)
                continue;
            s+=e[j]*mat[i][j];
        }
        s+=mat[i][MAX+1];
        s=-s;
        s/=mat[i][i];
        e[i]=s;
    }
}


int main()
{
    int t,ti,i,j,k,n;
    scanf("%d",&t);
    for(ti=1; ti<=t; ++ti)
    {
        scanf("%d",&n);
        memset(mat,0,sizeof(mat));
        while(n--)
        {
            scanf("%d %d",&i,&j);
            mat[i][j]=1;
            mat[i][i]=-1;
            //mat[i][MAX+1]=-1;
        }
        for(i=1; i<=MAX; ++i)
        {
            if(mat[i][i])
                continue;
            mat[i][i]=1;
            if(i<MAX)
                mat[i][MAX+1]=-1;
            for(j=i+1; j<=i+6; ++j)
            {
                if(j>MAX)
                    break;
                mat[i][j]=-(1.0/6.0);
            }
            if(j<=i+6 && i<MAX){
                 //   printf("pp %d %.2lf\n",i,(i+6-j+1)/6.0);
                mat[i][i]-=(double)((i+6-MAX)/6.0);

            }
        }
        gauss();
        printf("Case %d: %.8lf\n",ti,e[1]);
    }
    return 0;
}
