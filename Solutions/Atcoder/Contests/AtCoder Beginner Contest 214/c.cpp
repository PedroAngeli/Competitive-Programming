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

  vector <int> ans(n, 2e9 + 5);
  vector <int> s(n), t(n);
  set <pair <int,int> > events;
  
  for(int i=0;i<n;i++)
    cin >> s[i];
  for(int i=0;i<n;i++){
    cin >> t[i];
    events.insert({t[i], i});
  }

  set <int> S;
  while(S.size() < n){
    auto it = events.begin();
    int ti = it->f;
    int id = it->s;
    events.erase(it);
    if(S.count(id))
      continue;
    S.insert(id);
    ans[id] = ti;
    int nxt = id + 1;
    nxt %= n;
    events.insert({ti + s[id], nxt});
  }
  
  for(int i=0;i<n;i++)
    cout << ans[i] << endl;
  
  return 0;
}