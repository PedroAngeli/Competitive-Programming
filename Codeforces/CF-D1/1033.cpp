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

const int nax = 1e5 + 5;
vi adj[nax];

int main(){
  fastio;

  int n;
  cin >> n;

  vi vet(n);
  vi pos(n+1);

  for(int i=0;i<n;i++)
    cin >> vet[i],pos[vet[i]]=i;
  
  for(int i=0;i<n;i++){
    int l = i-vet[i];
    while(l >= 0){
      if(vet[l] > vet[i])
        adj[vet[i]].push_back(vet[l]);
      l-=vet[i];
    }
    int r = i+vet[i];
    while(r < n){
      if(vet[r] > vet[i])
        adj[vet[i]].push_back(vet[r]);
      r+=vet[i];
    }
  }

  string ans;
  ans.resize(n);

  vector <bool> dp(n+1,false);

  for(int i=n;i>=1;i--){
    for(int v:adj[i])
      dp[i] = (dp[i] || !dp[v]);
    
    ans[pos[i]] = dp[i] ? 'A' : 'B';
  }

  cout << ans << endl;
  
  return 0;
}