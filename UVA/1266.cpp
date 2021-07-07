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

int n_dig(int n){
  string a = to_string(n);
  return sz(a);
}

int main(){
  fastio;

  int n;
  int ncase = 0;
  while(cin >> n){
    if(ncase) cout << endl;
    ncase++;
    vector <vi> ans(n, vi(n,-1));
    int x = 0, y = n/2;
    int id = 1;
    while(id <= n*n){
          ans[x][y] = id++;
          int nx = ((x - 1)%n + n)%n;
          int ny = ((y + 1)%n + n)%n;
          if(ans[nx][ny] == -1){
            x = nx;
            y = ny;
          }else{
            x++;
          }
      }
  
    int sum = 0;
    for(int i=0;i<n;i++) sum += ans[0][i];

    cout << "n=" << n << ", sum=" << sum << endl;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int space = n_dig(n*n) - n_dig(ans[i][j]);
        space++;
        while(space--) cout << " ";
        cout << ans[i][j];
      }
      cout << endl;
    }

  }
  return 0;
}