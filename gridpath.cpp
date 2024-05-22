#include<bits/stdc++.h>
using namespace std;
int paths(int i,int j,vector<vector<char>>&v,int n,vector<vector<int>>&dp)
{
    if(i>n|| j>n)
    {
        return 0;
    }
    if(v[i][j]=='*')
    {
        return 0;
    }
    if(i==n && j==n)
    {
        return 1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int right=0;
    int down=0;

      right=paths(i,j+1,v,n,dp);

      down=paths(i+1,j,v,n,dp);


   return dp[i][j]=((right%1000000007)+(down%1000000007))%1000000007;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    if(v[0][0]=='*')
    {
        cout<<0;
    }
    else
    {
       cout<<paths(0,0,v,n-1,dp);
    }

}
