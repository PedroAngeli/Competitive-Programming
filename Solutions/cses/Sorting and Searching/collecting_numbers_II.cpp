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

  int n, m;
  cin >> n >> m;

  vi a(n), pos(n+1);
  for(int i=0;i<n;i++){
    cin >> a[i];
    pos[a[i]] = i;
  }

  int quedas = 0;

  for(int i=2;i<=n;i++)
    if(pos[i] < pos[i-1])
      quedas++;

  while(m--){
    int l, r;
    cin >> l >> r;
    l--, r--;

    set <pii> S;
    //pos[a[l]] = pos[a[r]] e vice-versa
    //os pares de indices que vou checar são para 1 <= a[i] <= n
    //(a[l]-1, a[l])
    //(a[l] , a[l]+1)
    //(a[r]-1, a[r])
    //(a[r], a[r]+1)

    if(a[l]-1 >= 1)
      S.insert({a[l]-1, a[l]});
    if(a[l]+1 <= n)
      S.insert({a[l], a[l]+1});
    if(a[r]-1 >= 1)
      S.insert({a[r]-1, a[r]});
    if(a[r]+1 <= n)
      S.insert({a[r], a[r]+1});

    for(auto p:S){
      bool tem_queda_antes = pos[p.f] > pos[p.s];
      swap(pos[a[l]], pos[a[r]]);
      bool tem_queda_depois = pos[p.f] > pos[p.s];
      swap(pos[a[l]], pos[a[r]]);
      if(tem_queda_antes and !tem_queda_depois)
        quedas--;
      if(!tem_queda_antes and tem_queda_depois)
        quedas++;
    }
    swap(pos[a[l]], pos[a[r]]);
    swap(a[l], a[r]);

    cout << quedas + 1 << endl;
  }
  
  return 0;
}