#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector <int> v;
int main()
{
    int t,n,i,j,k;
    double sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        v.clear();
        for(i=0; i<n; ++i)
        {
            scanf("%d",&j);
            v.push_back(j);
        }
        sort(v.begin(),v.end());
        sum=0;
        if(n-(2*k)>0)
        {
            for(i=k; i<n-k; ++i)
            {
                sum+=v[i];
            }
            sum/=(n-(2*k));
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
