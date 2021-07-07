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

  int n,k;
  cin >> n >> k;
  vi p(n);
  
  int cur = n;
  vi ans;
  ans.pb(cur);
  vi used(n+1,0);
  used[cur] = 1;

  bool sign = true;
  for(int i=k;i>=1;i--){
    if(sign)
      cur -= i;
    else
      cur += i;
    sign = !sign; 
    ans.pb(cur);
    used[cur] = 1;
  }

  for(int i=n;i>=1;i--)
    if(!used[i])
      ans.pb(i);
    
    for(int x:ans)
      cout << x << " ";
  cout << endl;

  return 0;
}