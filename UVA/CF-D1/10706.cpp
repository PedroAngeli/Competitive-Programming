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

int qtd_dig(int x){
  string a = to_string(x);
  return sz(a);
}

int main(){
  fastio;

  const int nax = 31269;
  vll S(nax,0);  //Si = S1 + S2 + S3 ... + Si

  for(int i=1;i<nax;i++){
    S[i] = S[i-1];
    int qtd = qtd_dig(i);
    for(int j=1;j<qtd;j++)
      S[i] += 9*pow(10,j-1)*j;
    S[i] += (i - pow(10,qtd-1) + 1)*qtd;
  }

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int i = lb(all(S),n) - S.begin();
    n -= S[i-1];
    if(n == 0){
      cout << 1 << endl;
      continue;
    }
    for(int k=1;k<=i;k++){
      int q = qtd_dig(k);
      int j = 0;
      while(j < q && n)
        j++,n--;
      if(n == 0){
        string a = to_string(k);
        cout << a[j-1] << endl;
        break;
      }
    }
  }
  return 0;
}