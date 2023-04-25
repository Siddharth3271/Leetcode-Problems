#include<stdio.h>
bool ispalindrome(int n)
{
    scanf("%d",&n);
    int temp,sum=0;
    while(n>0)
    {
        int temp=n%10;
        sum=sum*10+temp;
        n=n/10;
    }
    if(sum==n)
    {
        return 1;
    }
    else{
        return 0;
    }
}
