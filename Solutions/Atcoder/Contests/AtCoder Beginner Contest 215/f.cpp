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

vector <pair <int,int> > points;

bool test(int k){
  queue <pair <int,int> > q;

  int ymin = INT_MAX;
  int ymax = 0;

  for(auto p:points){
    while(!q.empty() and q.front().f >= p.f + k){
      ymin = min(ymin, q.front().s);
      ymax = max(ymax, q.front().s);
      q.pop();
    } 
    if(ymax >= p.s + k or p.s - k >= ymin)
      return true;
    q.push(p);
  }

  return false;
}

int main(){
  fastio;

  int n;
  cin >> n;

  points.resize(n);

  for(int i=0;i<n;i++)
    cin >> points[i].f >> points[i].s;

  sort(all(points));
  reverse(all(points));

  int l = 0;
  int r = 1e9;

  int ans = 0;
  while(l <= r){
    int m = (l+r)/2;
    if(test(m))
      ans = m, l = m+1;
    else
      r = m-1;
  }

  cout << ans << endl;
  
  return 0;
}