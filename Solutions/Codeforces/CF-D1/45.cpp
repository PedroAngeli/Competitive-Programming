#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

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
  const int nax = 1e7;

  vector <vpii> l(nax+1);

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    l[a].pb({b,i});  
  }

  vi ans(n);
  set <pii> conj;

  for(int date=1;date<=nax;date++){
    for(auto p : l[date])
      conj.insert(p);
    if(!conj.empty()){
      auto it = conj.begin();
      ans[it->s] = date;
      conj.erase(it);
    }
  }

  for(int x:ans)
    cout << x << " ";
  cout << endl;

  return 0;
}