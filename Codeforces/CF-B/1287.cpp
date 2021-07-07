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
 
 
char decide(char i,char j){
  if(i == j)
    return i;
  return i^j^'B';
}
 
int main(){
  fastio;
 
  int n,k;
  cin >> n >> k;
 
  vs cards(n);
  set <string> conj;

  for(int i=0;i<n;i++){
    cin >> cards[i];
    conj.insert(cards[i]);
  }

  int ans = 0;
  string search;
  search.resize(k);

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){      
      for(int l=0;l<k;l++)
        search[l] = decide(cards[i][l],cards[j][l]);
      ans += (conj.count(search));
    }
 
  cout << ans/3 << endl;
 
  return 0;
}