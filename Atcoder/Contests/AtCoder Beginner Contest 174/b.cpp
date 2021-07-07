#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
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
  
  int n;
  ll d;
  cin >> n >> d;
  int ans = 0;

  while(n--){
    ll x,y;
    cin >> x >> y;
    if(x*x + y*y <= d*d)
      ans++;
  }

  cout << ans << endl;

  return 0;
}