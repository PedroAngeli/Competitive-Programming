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

const int mod = 1e9 + 7;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  string a;
  cin >> a;

  int n = a.size();
  int ans = 0;
  int cb = 0;

  for(int i=n-1;i>=0;i--){
    if(a[i] == 'b')
      cb++;
    else{
      ans += cb;
      cb += cb;
      ans %= mod;
      cb %= mod;
    }
  }

  cout << ans << endl;
  return 0;
}