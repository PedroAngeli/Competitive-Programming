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

  string a,b;

  cin >> a >> b;

  int n = a.size();
  int m = b.size();

  int mx = 0;

  for(int i=0;i<=n-m;i++){
    int cnt = 0;
    int k = i;
    for(int j=0;j<m;j++,k++){
      if(a[k] == b[j])
        cnt++;
    }
    mx = max(mx,cnt);
  }



  cout << m - mx << endl;

  return 0;
}