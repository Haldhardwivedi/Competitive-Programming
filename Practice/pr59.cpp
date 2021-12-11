#include<bits/stdc++.h>
#include <omp.h>  

using namespace std;

#define N 1000
#define M 1000

#define ll long long 



int main()
{
    float start,end;
    int thread[]={1,2,4,6,8,10,12,16,20,24,32,64};
    float exectimes[12];
    ll int i,j;
    ll int n;
    cin>>n; 
    ll int a[n][n];
    ll int b[n][n];
    ll int c[n][n];
    ll int p[n][n];
    ll int q[n][n];
    ll int ans[n][n];
    srand(time(0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        a[i][j]=rand()%10;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        b[i][j]=rand()%10;
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        c[i][j]=rand()%10;
    }
    ll int row,col;
    for(i=0;i<12;i++)
    {
        start=omp_get_wtime();
        #pragma omp parallel for num_threads(thread[i])
        for (row = 0; row<n;row++) 
        {
            #pragma omp parallel for num_threads(thread[i])
            for (col = 0; col < n; col++) 
            {
                p[row][col]=0;
                for (j = 0; j < n; j++)
                    p[row][col] += a[row][j] * b[j][col];
            }
        }
        #pragma omp parallel for num_threads(thread[i])
        for (row = 0; row<n;row++) 
        {
            #pragma omp parallel for num_threads(thread[i])
            for (col = 0; col < n; col++) 
            {
                q[row][col]=0;
                for (j = 0; j < n; j++)
                    q[row][col] += b[row][j] * c[j][col];
            }
        }
        #pragma omp parallel for num_threads(thread[i])
        for (row = 0; row<n;row++) 
        {
            #pragma omp parallel for num_threads(thread[i])
            for (col = 0; col < n; col++) 
            {
                ans[row][col]=p[row][col]+q[row][col];
            }
        }
        end=omp_get_wtime();
        exectimes[i]=end-start;
    }
    for (row = 0; row<n;row++) 
    {
        for (col = 0; col < n; col++) 
        cout<<p[row][col]<<" ";
        cout<<endl;
    }
    cout<<"q"<<endl;
    for (row = 0; row<n;row++) 
    {
        for (col = 0; col < n; col++) 
        cout<<q[row][col]<<" ";
        cout<<endl;
    }
    cout<<"ans"<<endl;
    for (row = 0; row<n;row++) 
    {
        for (col = 0; col < n; col++) 
        cout<<ans[row][col]<<" ";
        cout<<endl;
    }
    return 0; 
}
