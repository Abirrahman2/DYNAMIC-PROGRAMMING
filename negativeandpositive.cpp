#include<bits/stdc++.h>
//my compiler shows 1 but here shows 3....
using namespace std;
long long f(int ind,int n,long long sum,long long arr[],vector<long long>&dp)
{
    if(ind>n){
        return sum;
    }

    long long x=-arr[ind];
    long long y=0;
    long long sum2=0;
    if(ind+1<=n)
    {
     y=-arr[ind+1];
     sum2=sum-(arr[ind]+arr[ind+1])+x+y;
     arr[ind]=x;
     arr[ind+1]=y;
    }
    long long take=f(ind+2,n,sum2,arr,dp);
    if(ind+1<=n)
    {
       arr[ind]=-x;
      arr[ind+1]=-y;
    }
    long long nottake=f(ind+1,n,sum,arr,dp);
    return max(take,nottake);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        long long sum=0;
        vector<long long>dp(n+1,INT_MIN);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum=sum+arr[i];
        }
        cout<<f(0,n-1,sum,arr,dp)<<endl;


    }
}
