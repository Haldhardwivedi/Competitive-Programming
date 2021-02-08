/*
author :Haldhar Dwivedi
emial:haldhardwivedi@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define REP(i,a,b) for(i=a;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);
 
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
vi g[N];
int a[N];
//=======================
 
set < string > alstr;
ll int n=0;
void permutation(string s,ll int l,ll int r)
{
   if(l==r)
   {
       alstr.insert(s);
   }
   else
   {
       for(ll int i=l;i<=r;i++)
       {
           swap(s[l],s[i]);
           permutation(s,l+1,r);
           swap(s[l],s[i]);
       }
   }
   
}
void solve() 
{
   string str;
   getline(cin,str);
   //cout<<str<<endl;
   ll int i;
   ll int visit[str.size()]={0};
   permutation(str,0,str.size()-1);
   cout<<alstr.size()<<endl;
   for(auto it=alstr.begin();it!=alstr.end();it++)
            cout<<*it<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}
 
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}