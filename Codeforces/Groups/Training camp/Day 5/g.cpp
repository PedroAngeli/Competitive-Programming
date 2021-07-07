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

typedef struct{
  int u,v,w;
}Edge;

vi parent;
vector <bool> isSpecial;

int find(int x){
  return x == parent[x] ? x : parent[x] = find(parent[x]);
}

bool join(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y)
    return false;

  if(isSpecial[x])
    parent[y] = x;
  else
    parent[x] = y;

  if(isSpecial[x] && isSpecial[y])
    return true;

  return false;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m,k;
  cin >> n >> m >> k;
  
  parent.resize(n+1);
  isSpecial.assign(n+1,false);
  iota(parent.begin(),parent.end(),0);

  for(int i=0;i<k;i++){
    int x;
    cin >> x;
    isSpecial[x] = true;
  }

  vector <Edge> e(m);

  for(int i=0;i<m;i++)
    cin >> e[i].u >> e[i].v >> e[i].w;
  
  sort(e.begin(),e.end(),[&](auto e1,auto e2){
    return e1.w < e2.w;
  });

  int unitedSpecial = k;

  for(auto el : e){
    if(join(el.u,el.v))
      unitedSpecial--;
    if(unitedSpecial == 1){
      for(int i=0;i<k;i++)
        cout << el.w << " ";
        cout << endl;
      return 0;
    }
  }
  return 0;
}