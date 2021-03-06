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
  vi a(n),pos(n+1);


  for(int i=0;i<n;i++)
    cin >> a[i];

  set <int> conj;

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    pos[x] = i;
    conj.insert(i);
  }

  
  int ans = 0;

  for(int i=n-1;i>=0;i--){
    auto it = conj.upper_bound(pos[a[i]]);
    if(it != conj.end())
      ans = n-i;
    conj.erase(pos[a[i]]);
  }

  cout << ans << endl;

  return 0;
}