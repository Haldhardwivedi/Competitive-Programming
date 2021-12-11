#include<bits/stdc++.h>

using namespace std;

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
bool cmp(pair<int, vector<int>>& a,
         pair<int, vector<int>>& b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    int j;
    sort(a,a+n);
    int max=a[n-1];
    vector<vector<int>>v(log2(max)+1);
    for(i=0;i<n;i++)
    {
        int count=countSetBits(a[i]);
        cout<<count<<endl;
        v[count].push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++)
    {
        vector<int>m=it->second;
        //sort(v.begin(),v.end(),greater<int>());
        for(j=0;j<max_size.size();j++)
        {
            cout<<m[i]<<" ";
        }
    }
    cout<<endl;
}