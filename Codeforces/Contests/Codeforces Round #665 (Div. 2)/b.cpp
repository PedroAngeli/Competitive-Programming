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
    int x1,y1,z1;
    int x2,y2,z2;

    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    int maxTwo = min(z1,y2);
    z1 -= maxTwo;
    y2 -= maxTwo;
    int ans = 2*maxTwo;

    int anul = z1 + x1;

    if(z2 > anul){
      int dif = z2 - anul;
      ans -= 2*dif;
    }

    cout << ans << endl;
  }
  
  return 0;
}