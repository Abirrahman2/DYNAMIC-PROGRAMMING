#include<bits/stdc++.h>
using namespace std;
long long fun(bool prev,int i,int j,int n,vector<vector<long long>>&v,vector<vector<long long>>&dp)
{
   //cout<<j<<endl;
    if(j>n)
    {

        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long pick=0;
    if(prev==true)
    {
        pick=v[i][j]+fun(false,i+1,j+1,n,v,dp);
    }
    else{
        pick=v[i][j]+fun(true,i-1,j+1,n,v,dp);
    }
     long long notpick=0;

      notpick=fun(prev,i,j+1,n,v,dp);


    return dp[i][j]=max(pick,notpick);

}
int main()
{
    int n;
    cin>>n;
    vector<vector<long long>>v(2,vector<long long>(n,0));
    vector<vector<long long>>dp(2,vector<long long>(n+1,-1));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {

            cin>>v[i][j];
        }
    }
      //cout<<v[0][4];
    cout<<max(fun(true,0,0,n-1,v,dp),fun(false,1,0,n-1,v,dp));
}
