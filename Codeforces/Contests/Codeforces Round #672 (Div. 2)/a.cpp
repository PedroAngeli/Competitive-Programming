#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
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
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    int cnt = 0;
    for(int i=0;i<n-1;i++){
      if(a[i] > a[i+1])
        cnt++;
    }
    if(cnt == n-1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}