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


int main(){
  fastio;

  int t=1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    
    if(a[0]+a[1]<=a[n-1]){
      cout << 1 << " " << 2 << " " << n << endl;
    }else
      cout << -1 << endl;
  }
  
  return 0;
}