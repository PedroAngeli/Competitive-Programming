#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;
  
vi parent;

int find(int x){
  return x == parent[x] ? x : parent[x] = find(parent[x]);
}

bool join(int x,int y){
  x = find(x);
  y = find(y);
  
  if(x == y)
    return false;
  
  parent[x] = y;
  return true;
}

void solve(){
  int n;
  string a,b;
  cin >> n >> a >> b;
  for(int i=0;i<n;i++){
    if(a[i] > b[i]){
      cout << -1 << endl;
      return;
    }
  }
  parent.resize(26);
  iota(parent.begin(),parent.end(),0);

  int ans = 0;

  for(int i=0;i<n;i++){
    if(join(a[i]-'a',b[i]-'a'))
      ans++;
  }
  cout << ans << endl;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}