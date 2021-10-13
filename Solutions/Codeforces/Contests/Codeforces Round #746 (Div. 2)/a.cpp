#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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


int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int n, H;
    cin >> n >> H;
    vector <int> a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    sort(all(a));
    reverse(all(a));
      int s = (a[0] + a[1]);
      int ti = H / s;
      int ans = 2*ti;
      if(H - ti*s > 0)
        ans++;
      if(H - (ti*s + a[0]) > 0)
        ans++;
      
      cout << ans << endl;
    
  }
  
  return 0;
}