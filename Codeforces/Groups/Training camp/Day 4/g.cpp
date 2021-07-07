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


ll squared(ll x){
  return x*x;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  
  vector <pll> vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i].f >> vet[i].s;
  }

  vi ans(n);

  ll curx = 0;
  ll cury = 0;

  for(int i=n-1;i>=0;i--){
    ll na = squared(vet[i].f+curx) + squared(vet[i].s+cury);
    ll nb = squared(vet[i].f-curx) + squared(vet[i].s-cury);

    if(na < nb){
      ans[i] = 1;
      curx += vet[i].f;
      cury += vet[i].s;
    }else{
      ans[i] = -1;
      curx -= vet[i].f;
      cury -= vet[i].s;
    }
  }

  for(int x:ans)
    cout << x << " ";
  
  cout << endl;
  return 0;
}