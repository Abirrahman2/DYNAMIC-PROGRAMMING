#include<bits/stdc++.h>
using namespace std;

int dice(long long dp[],long long sum)
{
   if(sum==0)
   {
       return 1;
   }
   long long l=0;
   for(int i=1;i<=6;i++)
   {
       if(dp[sum]!=0)
       {
           return dp[sum];
       }
       if(sum>=i)
       {
           l=l+dice(dp,sum-i);
       }
   }
   return dp[sum]=l%(1000000007);
}
int main()
{
    long long n;
    cin>>n;
    long long sum=n;
      long long dp[n+1]={0};
    cout<<dice(dp,sum);
}
