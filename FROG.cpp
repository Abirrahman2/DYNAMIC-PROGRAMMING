#include<bits/stdc++.h>
using namespace std;
int cost(int index,int arr[],int n,int k,int dp[])
 {

    if(n==index)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int r=INT_MAX;
    int l=0;
    for(int i=1;i<=k;i++)
    {
        if(index+i<=n)
        {
         l=cost(index+i,arr,n,k,dp)+abs(arr[index]-arr[index+i]);
        }
       r=min(r,l);
    }
    return dp[index]=r;


 }

int main()
{

    int n,k,sum=0;
    cin>>n>>k;
    int arr[n];
    int dp[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<cost(0,arr,n-1,k,dp);

}
