#include<stdio.h>

int main()
{
    long long i,k,a;
    scanf("%I64d",&i);
    a=1;
    for(k=1; k<=i; ++k)
        a*=2;
    printf("%I64d\n",a);
    return 0;
}
