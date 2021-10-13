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

const int nax = 2e5 + 5;
int parent[nax];
int qtd[nax];

int find(int x){
  if(x == parent[x])
    return x;

  return parent[x] = find(parent[x]);
}

void join(int x,int y){
  x = find(x);
  y = find(y);

  if(x != y){
    parent[x]=y; 
		qtd[y]+=qtd[x]; 
  }
}

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  for(int i=1;i<=n;i++)
    parent[i] = i,qtd[i] = 1;

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    if(find(a) != find(b))
      join(a,b);
  }

  int ans = 1;

  for(int i=1;i<=n;i++)
    ans = max(qtd[i],ans);

  cout << ans << endl;


  return 0;
}