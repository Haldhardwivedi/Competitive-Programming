#include<bits/stdc++.h> 
using namespace std;

int main() 
{
    int n;
    int i;
    int a,b;
    cin>>a>>b;
    cin>>n;
    if(n==1)
    cout<<a<<endl;
    else if(n==2)
    cout<<b<<endl;
    else
    {
        int d=b-a;
        for(i=3;i<=n;i++)
        {
            b=b+d;
        }
        cout<<b<<endl;
    }
    return 0;
}