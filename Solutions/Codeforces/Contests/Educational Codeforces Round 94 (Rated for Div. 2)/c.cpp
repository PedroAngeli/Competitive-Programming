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

  int t = 1;
  cin >> t;

  while(t--){
    string a;
    cin >> a;
    int x;
    cin >> x;
    int n = a.size();

    vector <bool> zero(n, false);
    vector <bool> one(n, false);

    bool can = true;

    for(int i=0;i<n;i++){
      if(a[i] == '0'){
        if(i >= x)
          zero[i-x] = true;
        if(i+x < n)
          zero[i+x] = true;
      }else{
        if(i >= x && i + x < n)
          continue;
        
        if(i < x && i + x < n)
          one[i+x] = true;
        if(i >= x && i + x >= n)
          one[i-x] = true;

        if(i < x && i + x >= n){
          can = false;
          break;
        }
      }
    }

    if(!can){
      cout << -1 << endl;
      continue;
    }

    vector <int> ans(n);

    for(int i=0;i<n;i++){
      if(zero[i] && one[i]){
        can = false;
        break;
      }
      
      if(a[i] == '1' && i >= x && i + x < n && zero[i-x] && zero[i+x]){
        can = false;
        break;
      }

      if(zero[i])
        ans[i] = 0;
      else
        ans[i] = 1;
    }

    if(!can){
      cout << -1 << endl;
      continue;
    }

    for(int v : ans)
      cout << v;
    cout << endl;

  }

  return 0;
}