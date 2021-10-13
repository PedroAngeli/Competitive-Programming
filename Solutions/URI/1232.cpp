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

  string s;
  while(cin >> s){
    vi sum(6, 0), cur(6, 0);
    for(char c:s){
      if(c == 'B') sum[0]++; if(c == 'b') sum[0]--;
      if(c == 'F') sum[1]++; if(c == 'f') sum[1]--;
      if(c == 'L') sum[2]++; if(c == 'l') sum[2]--;
      if(c == 'R') sum[3]++; if(c == 'r') sum[3]--;
      if(c == 'U') sum[4]++; if(c == 'u') sum[4]--;
      if(c == 'D') sum[5]++; if(c == 'd') sum[5]--;
    }

    int ans = 0;
    bool check = true;
    while(check){
      ans++;
      for(int i=0;i<6;i++){
        cur[i] += sum[i];
        debug(i, cur[i]);
      }

      check = false;
      for(int i=0;i<6;i++)
        if(cur[i]%4)
          check = true;
    }

    cout << ans << endl;
  }

  
  return 0;
}