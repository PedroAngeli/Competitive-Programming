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

  int n;
  cin >> n;
  
  vector <pair<int,int>> points(n);
  map <pair <int,int>, bool> mp;

  for(int i=0;i<n;i++){
    cin >> points[i].f >> points[i].s;
    mp[points[i]] = true;
  }

  int ans = 0;

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      if(points[i].f == points[j].f
        or points[i].s == points[j].s)
          continue;
      int x1 = points[i].f, y1 = points[j].s;
      int x2 = points[j].f, y2 = points[i].s;
      if(mp.find({x1, y1}) != mp.end() 
        and mp.find({x2, y2}) != mp.end()){
          ans++;
        }
    }

  cout << ans/2 << endl;
  return 0;
}