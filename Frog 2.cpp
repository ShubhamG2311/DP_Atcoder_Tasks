// Code by Shubham
#include<bits/stdc++.h>
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------------------------
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define vs vector<string>
#define vin vector<int>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define inf LONG_LONG_MAX
#define rep(i,a,b) for (ll i=a; i<b; i++)
#define nline "\n"
#define MOD 1000000007
#define MOD1 998244353
//------------------------------------Debugging and few common algorithms-------------------------------------------------------------------------------
template <class t> void printvector(vector<t>& v, ll n) {rep(i,0,n) {cout<<v[i]<<" ";} cout<<endl;}
template<class t> void printarray(t arr, ll n) {rep(i,0,n) {cout<<arr[i]<<" ";} cout<<endl;}
template<class t> t binpow(t a, t b) {ll res = 1;while (b > 0) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
template<class t> t binpowm(t a, t b) {a %= MOD; ll res = 1; while (b > 0) { if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}
template<class t> t lcm(t a, t b) { ll ans=(a*b)/(__gcd(a,b)); return ans;}
template<class t> t ceil(t a, t b) {if (a%b==0) return a/b; else return (a/b)+1;}
template<class t> vector<t> primeFactors(t n){vi ans;while (n % 2 == 0){ans.pb(2); n = n/2;}for (ll i = 3; i <= sqrt(n); i = i + 2){ while (n % i == 0){ ans.pb(i);n = n/i;}}if (n > 2) ans.pb(n);return ans;}
//------------------------------------Let's Go!!--------------------------------------------------------------------------------------------------------
ll solution(vi &a,ll n, ll k,vi &dp)
{
  dp[0]=0;
  dp[1]=0;
  dp[2]=abs(a[1]-a[0]);
  rep(i,3,n+1)
  {
    ll temp=INT_MAX;
    rep(j,1,k+1)
    {
      ll t=min(j,i-1);
      temp=min(temp,abs(a[i-1]-a[i-t-1])+dp[i-t]);
    }
    dp[i]=temp;
  }
  return dp[n];
}

void solve()
{
  ll n,k;
  cin>>n>>k;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  vector<ll> dp(n+1,-1);
  cout<<solution(a,n,k,dp);
}

int main()
{
  FIO
  // ll T;
  // cin>>T;
  // rep(g,0,T)
  // {
  //   solve(); 
  // }
  solve();
  return 0;
}
