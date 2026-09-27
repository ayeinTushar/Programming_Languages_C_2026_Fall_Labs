#include <stdio.h>
long long factorial (int n)
{
    long long result = 1;
    for (int i = 1; i <=n; i++)
    {
        result = result *i;
    }
    return result;
}
int main( void)
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
    if (n <0)
    {
        printf("error\n");
    }
    else{
        printf("factorial = %lld\n",factorial(n));
    } return 0;
}