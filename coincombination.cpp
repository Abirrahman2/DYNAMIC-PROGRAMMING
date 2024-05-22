#include<bits/stdc++.h>
using namespace std;
long long ways(long long ind,long long  sum,long long n,long long arr[],vector<vector<long long>>&dp)
{
    if(sum<0)
    {
        return 0;
    }
    if(sum==0)
    {
        return 1;
    }
    if(dp[sum][ind]!=-1)
    {
        return dp[sum][ind];
    }
    long long l=0;
    for(long long i=ind;i<=n;i++)
    {

        l=l+ (ways(i,sum-arr[i],n,arr,dp))%1000000007;

    }

    return dp[sum][ind]=l%1000000007;
}
int main()
{
    long long n;
    cin>>n;
    long long  sum;
    cin>>sum;
    long long arr[n];

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // sort(arr,arr+n);
    long long x=sum+1;
    long long y=n;
   vector<vector<long long>>dp(x,vector<long long>(y,-1));
    cout<<ways(0,sum,n-1,arr,dp);
}
