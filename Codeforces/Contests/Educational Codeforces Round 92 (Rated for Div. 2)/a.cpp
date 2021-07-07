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
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    ll l,r;
    cin >> l >> r;
    ll x = l;
    if(2*x <= r)
      cout << x << " " << 2*x << endl;
    else
      cout << -1 << " " <<-1 << endl;
  }
 
  return 0;
}