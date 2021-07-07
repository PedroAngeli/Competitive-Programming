#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

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

  int x1,y1,x2,y2;

  while(cin >> x1 >> y1 >> x2 >> y2){
    if(!x1 && !y1 && !x2 && !y2)
      break;
    
    if(x1 == x2 && y1 == y2)
      cout << 0 << endl;
    else if(x1 == x2 || y1 == y2 || (x1+y1 == x2+y2) || (x1-y1 == x2-y2))
      cout << 1 << endl;
    else
      cout << 2 << endl;
    }

    
  return 0;
}