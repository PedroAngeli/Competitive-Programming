#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

ll find_n(ll x){
  ll ret = -1;

  for(ll i = 1; i <= 1e5;i++)
    if((i * (i -1)) / 2 == x) return i;

  return ret;
}

ll a,b,c,d;

string solve(int n0,int n1){
  int len = n0 + n1;
  string ans;
  
  if(n0 == 0){ 
    ans.assign(len,'1');
    return ans;
  }
  
  ans.assign(len, '0');
  
  int ones = c / n0;
  int rest = c % n0;
 
  for(int i=0;i<ones;i++)
    ans[i] = '1';
 
  int o = n1 - ones;
  for(int i=len-1;i>=0 && o;i--,o--)
    ans[i] = '1';
 
  int pos = len-1;
  while(pos >=0 && ans[pos] == '1') pos--;
  pos++;
  if(rest){
    ans[pos - rest] = '1';
    ans[pos] = '0';
  }

  return ans;
}

bool can(ll n0,ll n1){
  return n0 != -1 && n1 != -1 && (n0 * n1) == (b + c);
}

int main(){
  fastio;

  cin >> a >> b >> c >> d;

  if(!a && !b && !c && !d){
    cout << "0" << endl;
    return 0;
  }
  
  if(!a || !d){
    ll n0,n1;
    if(a == 0 && d){
      n1 = find_n(d);
      if(can(0,n1)) cout << solve(0,n1) << endl;
      else if(can(1,n1)) cout << solve(1, n1) << endl;
      else cout << "impossible" << endl;
    }else if(a && d == 0){
      n0 = find_n(a);
      if(can(n0,0)) cout << solve(n0,0) << endl;
      else if(can(n0,1)) cout << solve(n0,1) << endl;
      else cout << "impossible" << endl;
    }else{
      if(can(1,1)) cout << solve(1,1) << endl;
      else cout << "impossible" << endl;
    }

    return 0;
  } 

  ll n0 = find_n(a);
  ll n1 = find_n(d);

  if(n0 == -1 || n1 == -1 || !can(n0,n1)){
    cout << "impossible" << endl;
    return 0;
  }

  cout << solve(n0, n1) << endl;


  return 0;
}