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

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vi a(n+1), ans(n+1, -1), escolhido(n+1, 0);
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    
    int cnt = 0;

    for(int i=1;i<=n;i++)
      if(!escolhido[a[i]]){
        ans[i] = a[i];
        escolhido[a[i]] = 1;
        cnt++;
      }

    vi naoEscolheu, naoEscolhido;
    for(int i=1;i<=n;i++){
      if(!escolhido[i])
        naoEscolhido.pb(i);
      if(ans[i] == -1)
        naoEscolheu.pb(i);
    }

    assert(naoEscolheu.size() == naoEscolhido.size());
    if(naoEscolheu.size() == 1){
      int u = naoEscolheu[0];
      int v = naoEscolhido[0];
      if(u != v){
        ans[u] = v;
      }else{
        for(int i=1;i<=n;i++)
        if(ans[i] == a[u]){
          ans[i] = u;
          break;
        }
        ans[u] = a[u];
      } 
    }else{
      while(true){
        int c = 0;
        random_shuffle(all(naoEscolheu));
        random_shuffle(all(naoEscolhido));
        for(int i=0;i<sz(naoEscolheu);i++){
          c += (naoEscolheu[i] == naoEscolhido[i]);
          ans[naoEscolheu[i]] = naoEscolhido[i];
        } 
        if(c == 0)
          break;
      }
    }

    cout << cnt << endl;
    for(int i=1;i<=n;i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  
  return 0;
}