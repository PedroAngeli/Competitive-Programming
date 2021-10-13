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
  
  string a,b;
  cin >> a >> b;
  int n = b.size();
  int m = a.size();

  vi pref(n+1,0);
  for(int i=1;i<=n;i++){
    pref[i] = pref[i-1];
    if(b[i-1] == '0')
      pref[i]++;
  }

  ll ans = 0;

  for(int i=0;i<m;i++){
    ll qtd = pref[n-m+i+1]-pref[i];
    if(a[i] == '1'){
      ans += qtd;
    }else{
      qtd = n-m+1-qtd;
      ans += qtd;
    }
  }

  cout << ans << endl;
  return 0;
}