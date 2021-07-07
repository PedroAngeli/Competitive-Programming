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

  int n,d;
  
  while(cin >> n >> d){
    if(n == 0 && d == 0)
      break;
    string a;
    cin >> a;

    string ans = "";

    stack <char> p;
    p.push(a[0]);
    int take = n-d;

    for(int i=1;i<n;i++){
      while(!p.empty() && p.top() < a[i] && d)
        p.pop(),d--;
      if(p.size() < take)
      p.push(a[i]);
    }

    while(!p.empty())
      ans += p.top(),p.pop();
    
    reverse(all(ans));


    cout << ans << endl;

  }

  return 0;
}