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

const int mod = 998244353;

void addZero(string &str,int val){
  reverse(str.begin(),str.end());
  while(val--)
    str+='0';
  reverse(str.begin(),str.end());
}
int main(){
  fastio;

  int n,m;
  cin >> n >> m;
  string a,b;
  cin >> a >> b;

  addZero(a,max(m-n,0));
  addZero(b,max(n-m,0));

  int len = a.size();

  int pot[len];
  pot[0] = 1;
  for(int i=1;i<len;i++){
    pot[i] = 2*pot[i-1];
    pot[i] %= mod;
  }

  int pref[len];
  pref[0] = (b[0]-'0');

  for(int i=1;i<len;i++)
    pref[i] = pref[i-1] + (b[i]-'0');

  ll ans = 0;

  for(int i=0;i<len;i++){
    if(a[i] == '0')
      continue;
    ans += 1LL*pref[i]*pot[len-i-1];
    ans %= mod;
  }

  
  cout << ans << endl;
  
  return 0;
}