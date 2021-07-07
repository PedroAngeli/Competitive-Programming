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

  int t;
  cin >> t;
  int ncase = 1;
  while(t--){
    cout << "Case #" << ncase++ << ":" << endl;
    string a;
    cin >> a;
    int n = sz(a);
    int mn = 0;
    int mx = 0;
    int pos = 0;
    for(int i=1;i<n;i++){
      if(a[i] == 'C'){
        if(a[i-1] == 'R') pos--;
      }else if(a[i] == 'R'){
        if(a[i-1] == 'R') pos--;
      }else{
        if(a[i-1] != 'R') pos++;
      }
      mx = max(mx,pos);
      mn = min(mn,pos);
    }
    int len = mx - mn + 1;
    vs graph(len+1, string(n + 3, ' '));

    for(int i=0;i<len;i++) graph[i][0] = '|';
    graph[len][0] = '+';
    for(int i=1;i<=n+2;i++) graph[len][i] = '-';

    int x = abs(mn);
    int y = 2;
    graph[x][y] = (a[0] == 'R') ? '/' : (a[0] == 'F') ? '\\' : '_';
    y++;
    for(int i=1;i<n;i++){
      if(a[i] == 'C'){
        if(a[i-1] == 'R') x--;
        graph[x][y] = '_';
      }else if(a[i] == 'R'){
        if(a[i-1] == 'R') x--;
        graph[x][y] = '/';
      }else{
        if(a[i-1] != 'R') x++;
        graph[x][y] = '\\';
      }

      y++;
    }

    for(int i=0;i<sz(graph);i++){
      int pos = n+2;
      while(graph[i][pos] == ' ') pos--;
      for(int j=0;j<=pos;j++) cout << graph[i][j];
      cout << endl;
    }
    cout << endl;
  }
  
  return 0;
}