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

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    vpii a(n);
    int mn = INT_MAX;

    for(int i=0;i<n;i++){
      cin >> a[i].f;
      mn = min(mn,a[i].f);
      a[i].s = i;
    }
    
    sort(a.begin(),a.end());


    bool can = true;

    for(int i=0;i<n;i++){
      if(((a[i].f % mn) != 0) && a[i].s != i){
        can = false;
        break;
      }
    }
    if(can)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  return 0;
}