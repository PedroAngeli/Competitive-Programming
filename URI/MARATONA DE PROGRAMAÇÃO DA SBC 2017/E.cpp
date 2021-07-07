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

  vi d(n);
  for(int i=0;i<n;i++){
    cin >> d[i];
    d[i]--;
    d[i] %= 12;
  }
  
  vs notas = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};
  vi pattern = {2,2,1,2,2,2,1};
  
  vector <set <int> > tom(12);

  for(int i=0;i<12;i++){
    tom[i].insert(i);
    int nota = i;

    for(int j=0;j<7;j++){
      nota += pattern[j];
      nota %= 12;
      tom[i].insert(nota);
    }
  }

  for(int i=0;i<12;i++){
    bool can = true;
    for(int x : d){
      if(tom[i].find(x) == tom[i].end()){
        can = false;
        break;
      }
    }
    if(can){
      cout << notas[i] << endl;
      return 0;
    }
  }

  cout << "desafinado" << endl;
    
  
  return 0;
}