#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {

            cin>>arr[i];
        }

         long long sum=0;
         bool a;
        for(int i=0;i<n;i++)
        {
             int j=i;

           int maxi=arr[i];
           a=false;
           while(((maxi>0 && arr[j]>0) || (maxi<0 && arr[j]<0)) && j<n)
           {
               maxi=max(maxi,arr[j]);
               a=true;
               j++;

           }
           sum=sum+maxi;

           i=j;
           if(a==true)
           {
                i--;
           }

        }
        cout<<sum<<endl;
    }
}
