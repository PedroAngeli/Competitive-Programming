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


int calc(string& a){
  int n = sz(a);
  int ret = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++) ret += (a[i] < a[j]);

  return ret;
}

int main(){
  fastio;

  int t;
  cin >> t;
  for(int tt=0;tt<t;tt++){
    if(tt) cout << endl;
    int n,m;
    cin >> n >> m;
    vs dna(m);
    vpii vet;
    for(int i=0;i<m;i++){
      cin >> dna[i];
      vet.pb({calc(dna[i]), i});
    }

    sort(all(vet));

    for(auto el : vet)
      cout << dna[el.s] << endl;
  }
  return 0;
}