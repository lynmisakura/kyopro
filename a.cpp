//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pi;
typedef vector<pair<ll, ll>> vpi;
 
//const long long INF = 1LL << 55;
 
#define itn ll
#define endl '\n'
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(ll i = 0;i < n;i++)
#define rep(i,n) for(ll i = 0;i < n;i++)
#define flush fflush(stdout)
#define rrep(i,n) for(ll i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define ioboost cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, ll mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

inline void ain(vector<int>& a,int n){
   for(int i = 0;i < n;i++)scanf("%d",&a[i]);
}
inline void ainl(vector<ll>&a,int n){
   for(int i = 0;i < n;i++)scanf("%lld",&a[i]);
}
template<class T>inline void aout(vector<T> a){
   int sz = a.size();
   cout << "[ ";
   for(int i = 0;i < sz;i++){
      if(i != sz-1)cout << a[i] << ", ";
      else cout << a[i];
   }
   cout << " ]" << endl;
}
int n,m,l;
int cost[400][400];
int cost2[400][400];
int main(void){
   cin >> n >> m >> l;
   rep(i,m){
      int a,b,c;cin >> a >> b >> c;
      a--,b--;
      cost[a][b] = c;
      cost[b][a] = c;
   }
   rep(i,400)rep(j,400)cost[i][j] = INT_MAX/3;
   rep(i,400)rep(j,400)rep(k,400){
      cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
   }
   
   rep(i,400)rep(j,400){
      if(cost[i][j] <= l)cost2[i][j] = 1;
      else cost[i][j] = 1000000;
   }
   rep(i,400)rep(j,400)rep(k,400){
      cost2[i][j] = min(cost2[i][j],cost2[i][k] + cost2[k][j]);
   }
   int q;cin >> q;
   rep(i,q){
      int s,t;cin >> s >> t;
      s--,t--;
      
      if(cost2[s][t] > 300)cout << -1 << endl;
      else cout << cost2[s][t] << endl;
   }
   return 0;
}