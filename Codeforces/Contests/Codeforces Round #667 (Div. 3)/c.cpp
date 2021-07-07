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

int n,x,y;

bool valid(vi& ans){
  bool fx = false, fy = false;

  for(int i=0;i<n;i++)
    if(ans[i] == x)
      fx = true;
    else if(ans[i] == y)
      fy = true;

  return fx && fy;  
}
int main(){
  fastio;

  int t = 1;
  cin >> t;

  while(t--){
    cin >> n >> x >> y;

    vi ans;

    for(int i=1;i<=(y-x);i++){
      if((y-x)%i != 0)
        continue;
      for(int pri=1;pri<=50;pri++){
        int num = pri;
        while(sz(ans) < n)
          ans.pb(num),num += i;
        if(valid(ans)){
          i = (y-x);
          break;
        }
        ans.clear();
      }
    }

    for(int x:ans)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}