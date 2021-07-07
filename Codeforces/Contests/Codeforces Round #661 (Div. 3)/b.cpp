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
  
  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vll a(n);
    vll b(n);
    ll mnA = INT_MAX;
    ll mnB = INT_MAX;
    for(int i=0;i<n;i++)
      cin >> a[i],mnA=min(mnA,a[i]);
    for(int i=0;i<n;i++)
      cin >> b[i],mnB=min(mnB,b[i]);
    
    ll ans = 0;

    for(int i=0;i<n;i++){
      ll eatA = a[i]-mnA;
      ll eatB = b[i]-mnB;
      ans += max(eatA,eatB);
    }

    cout << ans << endl;
  }

  return 0;
}