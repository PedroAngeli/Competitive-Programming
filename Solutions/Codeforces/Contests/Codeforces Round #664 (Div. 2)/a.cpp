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
    int r,g,b,w;
    cin >> r >> g >> b >> w;

    int even = (r%2==0) + (g%2==0)+ (b%2==0) + (w%2==0);

    if(even == 3 || even == 4)
      cout << "Yes" << endl;
    else{
      if(r && g && b){
        r--,g--,b--,w++;
        even = (r%2==0) + (g%2==0)+ (b%2==0) + (w%2==0);
        if(even == 3 || even == 4)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
      }else
          cout << "No" << endl;

    }    
  }

  return 0;
}