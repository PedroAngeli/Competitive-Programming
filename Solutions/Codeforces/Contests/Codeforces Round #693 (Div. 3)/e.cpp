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
#define ordered_set 
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

vi find_pref(vector <pair<pii,int> >& v){
  int n = v.size();
  vi p(n, 0);

  for(int i=1;i<n;i++){
    int wj = v[p[i-1]].f.s;
    int wi = v[i].f.s;
    if(wi < wj) p[i] = i;
    else p[i] = p[i-1];
  }

  return p;
}

int solve(vector <pair<pii,int> >& v, vi& p, int h, int w){
    pair <pii,int> s = {{h, -1},-1};
    int j = lb(all(v), s) - v.begin() - 1;
    if(j == -1) return -1;
    int wj = v[p[j]].f.s;
    if(w > wj) return v[p[j]].s;
    return -1;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <pair<pii,int> > v1, v2;

    for(int i=0;i<n;i++){
      int h,w;
      cin >> h >> w;
      v1.pb({{h,w},i});
      v2.pb({{w,h},i});
    }

    sort(all(v1));
    sort(all(v2));

    vi p1 = find_pref(v1);
    vi p2 = find_pref(v2);

    vi ans(n,-1);

    for(int i=0;i<n;i++){
      int h = v1[i].f.f;
      int w = v1[i].f.s;
      int idx = v1[i].s;
      int j = solve(v1, p1, h, w);
      if(j == -1)  j = solve(v2, p2, h, w);
      ans[idx] = j + (j!=-1);
    }
    for(int x:ans)
      cout << x << " ";
    cout << endl;
  }
  
  return 0;
}