#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

  int q;
  cin >> q;
  map <pll,ll> weight;

  while(q--){
    int e;
    ll u,v,w;
    cin >> e >> u >> v;

    if(u > v)
        swap(u,v);
    int lgu = log2l(u);
    int lgv = log2l(v);

    if(e == 1){
      cin >> w;
      while(lgu != lgv){
        ll parentV = v/2;
        weight[{parentV,v}] += w;
        v = parentV;
        lgv--;
      }
      while(u != v){
        ll parentU = u/2;
        ll parentV = v/2;
        weight[{parentU,u}] += w;
        weight[{parentV,v}] += w;
        v = parentV;
        u = parentU;
      }
    }else{
       ll ans = 0;
        while(lgu != lgv){
        ll parentV = v/2;
        ans += weight[{parentV,v}];
        v = parentV;
        lgv--;
      }
      while(u != v){
        ll parentU = u/2;
        ll parentV = v/2;
        ans += weight[{parentU,u}];
        ans += weight[{parentV,v}];
        v = parentV;
        u = parentU;
      }
      cout << ans <<endl;
    }
  }

  return 0;
}