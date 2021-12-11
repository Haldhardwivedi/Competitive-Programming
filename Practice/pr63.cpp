#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    int sum[n];
    int tsum=0;
    for(i=0;i<n;i++)
    {
        sum[i]=(i+1)*a[i];
        tsum=tsum+sum[i];
    }
    int j;
    int max=tsum;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int temp=tsum;
            temp=temp-sum[i]-sum[j];
            int sum1=(i+1)*a[j];
            int sum2=(j+1)*a[i];
            temp=temp+sum1+sum2;
            if(temp>max)
                max=temp;
        }
    }
    cout<<max<<endl;
}