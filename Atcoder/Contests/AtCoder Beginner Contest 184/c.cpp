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

  int r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  
  if(r1 == r2 and c1 == c2) cout << 0 << endl;
  else if(r1+c1 == r2+c2 or r1-c1 == r2-c2 or abs(r1-r2)+abs(c1-c2)<=3) cout << 1 << endl;
  else{
    int s1 = r1+c1, s2 = r2+c2;
    int d1 = r1-c1, d2 = r2-c2;
    if(s1%2 == s2%2) cout << 2 << endl;
    else if (abs(r2 - r1) + abs(c2-c1) <= 6) cout << 2 << endl;
    else{
      if(abs(s1-s2) <= 3 or abs(d1-d2) <= 3) cout << 2 << endl;
      else cout << 3 << endl;
    }
  }

  return 0;
}