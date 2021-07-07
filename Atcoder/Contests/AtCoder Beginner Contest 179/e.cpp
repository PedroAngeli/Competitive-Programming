#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


int main(){
  fastio;

  ll n;
  cin >> n;
  ll x,m;
  cin >> x >> m;
  ll ans = 0;
  set <ll> conj;
  vll nums;
  int times = 0;

  while(true){
    if(conj.count(x))
      break;
    nums.pb(x);
    conj.insert(x);
    ans += x;
    x = (x*x)%m;
    times++;
    if(times == n){
      cout << ans << endl;
      return 0;
    } 
  }
  
  int p = 0;
  while(nums[p] != x)
    p++;

  ll sum = 0;
  for(int i=p;i<sz(nums);i++){
    ans += nums[i];
    sum += nums[i];
    times++;
    if(times == n){
      cout << ans << endl;
      return 0;
    }
  }
  int per = sz(nums)-p;
  ll dif = n-times;

  ans += sum*(dif/per);

  int rest = dif%per;
  while(rest--){
    ans += nums[p];
    p++;
  }

  cout << ans << endl;



  return 0;
}