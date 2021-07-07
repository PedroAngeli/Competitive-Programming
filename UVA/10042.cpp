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

int sum_dig(int n){
  string a = to_string(n);
  int ret = 0;
  for(int i=0;i<sz(a);i++) ret += (a[i]-'0');
  return ret;
}

bool smith(int n){
  int sn = sum_dig(n);
  int sf = 0;

  int div = 2;
  int N = n;

  while(div*div*1LL <= n){
    while(n % div == 0){
      n /= div;
      sf += sum_dig(div);
    }
    div++;
  }

  if(n == N) return false;
  if(n > 1) sf += sum_dig(n);

  return (sn == sf);
}
int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    n++;
    while(!smith(n)) n++;
    cout << n << endl;
  }
  return 0;
}