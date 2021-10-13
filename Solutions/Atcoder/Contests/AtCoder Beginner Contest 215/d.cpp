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

const int nax = 1e5 + 5;
int main(){
  fastio;

  int n, m;
  cin >> n >> m;

  vector <bool> factor(nax, 0);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    int j = 2;
    while(j*j <= a){
      while(a % j == 0){
        factor[j] = true;
        a /= j;
      }
      j++;
    }
    if(a != 1) factor[a] = true;
  }

  
  vector <int> ans;
  ans.push_back(1);

  for(int i=2;i<=m;i++){ 
    int a = i;
    bool can = true;
    int j = 2;
    while(j*j <= a){
      while(a % j == 0){
        a /= j;
        can = (can and !factor[j]);
      }
      j++;
    }
    if(a != 1) 
      can = (can and !factor[a]);
    if(can)
      ans.push_back(i);
  }


  cout << ans.size() << endl;
  for(int x:ans)
    cout << x << endl;
  return 0;
}