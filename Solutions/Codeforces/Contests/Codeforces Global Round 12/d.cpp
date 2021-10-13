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

const int nax = 3e5 + 5;
int n;
vi a;
const int INF = 1e9 + 7;
int freq[nax];

bool is_perm(vi& p){
  memset(freq, 0, sizeof freq);

  for(int x:p)
    freq[x]++;

  for(int i=1;i<=sz(p);i++)
    if(freq[i] != 1) return false;

  return true;
}

bool can(int k){
  vi p;
  deque <int> dq;

  int i;
  for(i=0;i<k;i++){
    while(!dq.empty() and a[i] <= a[dq.back()]) dq.pop_back();
    dq.pb(i);
  }

  for(;i<n;i++){
    p.pb(a[dq.front()]);
    while(!dq.empty() and dq.front() <= i-k) dq.pop_front();
    while(!dq.empty() and a[i] <= a[dq.back()]) dq.pop_back();
    dq.pb(i);
  }
  p.pb(a[dq.front()]);

  return is_perm(p);
}

int main(){
  fastio;

  int t = 1;
  cin >> t;

  while(t--){
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];

    string ans(n, '0');
    ans[0] = is_perm(a) ? '1' : '0';

    int l = 2;
    int r = n;
    int mx = INF;

    while(l <= r){
      int m = (l+r)/2;
      if(can(m)) mx = m, r = m-1;
      else l = m + 1;
    }

    for(int i=mx-1;i<n;i++) ans[i] = '1';

    cout << ans << endl;
  }
  
  return 0;
}