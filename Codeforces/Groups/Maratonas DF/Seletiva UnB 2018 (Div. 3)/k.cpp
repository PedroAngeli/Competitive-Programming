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



int main(){
  fastio;

  int n;
  cin >> n;

  vi bits(n);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    bits[i] = log2(x) + 1;
  } 

  int num_ele[9] = {28, 14, 9, 7, 5, 4, 3, 2, 1};
  int num_bits[9] = {1, 2, 3, 4, 5, 7, 9, 14, 28};
  
  int pos = 0;
  int words = 0;

  while(pos < n){
    int best_seletor = 0;
    for(int seletor=8;seletor>=0;seletor--){
      int l = pos;
      int r = min(n, pos+num_ele[seletor]);
      int mx = 0;
      for(int i=l;i<r;i++) mx = max(mx, bits[i]);
      if(mx <= num_bits[seletor]) best_seletor = seletor;
    }
    words++;
    pos = pos + num_ele[best_seletor];
  }

  cout << "Total bytes: " << words*4 << endl;;
  return 0;
}