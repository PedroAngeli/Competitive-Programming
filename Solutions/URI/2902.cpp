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

  int n, j;
  while(cin >> n >> j and n and j){
    vector <vi> cartasJogador(j, vi(14, 0));
    vi topoJogador(j, 0);
    vi cartasDescarte(14, 0);
    int vez = 0;

    for(int i=0;i<n;i++){
      int cur;
      cin >> cur;

      if(cartasDescarte[cur]){
        cartasDescarte[cur]--;
        topoJogador[vez] = cur;
        cartasJogador[vez][cur] += 2;
        continue;
      }

      bool ok = false;
      for(int p=0;p<j;p++){
        if(p == vez)
          continue;
        if(topoJogador[p] == cur){
          topoJogador[p] = 0;
          topoJogador[vez] = cur;
          for(int c=1;c<=13;c++){
            cartasJogador[vez][c] += cartasJogador[p][c];
            cartasJogador[p][c] = 0;
          }
          cartasJogador[vez][cur]++;
          ok = true;
          break;
        }
      }
      if(ok) continue;

      if(topoJogador[vez] == cur){
        cartasJogador[vez][cur]++;
        continue;
      }
      vez++;
      vez %= j;
      cartasDescarte[cur]++;
    }
    
    int mx = 0;
    for(int i=0;i<j;i++){
      int sum = 0;
      for(int c=1;c<=13;c++)
        sum += cartasJogador[i][c];
      mx = max(mx, sum);
    }
    vi ans;
    for(int i=0;i<j;i++){
       int sum = 0;
      for(int c=1;c<=13;c++)
        sum += cartasJogador[i][c];
      if(mx == sum)
        ans.pb(i);
    }

    cout << mx;
    for(int x:ans)
      cout << " " << x+1;
    cout << endl;
  }

  
  return 0;
}