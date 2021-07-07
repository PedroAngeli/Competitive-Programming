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

  int n,m;

  cin >> n >> m;

  vs answers(n);

  for(int i=0;i<n;i++)
    cin >> answers[i];

  vi a(m);

  for(int i=0;i<m;i++)
    cin >> a[i];

  int ans = 0;

  for(int i=0;i<m;i++){
    int mx = 0;
    for(char c : {'A','B','C','D','E'}){
      int cnt = 0;
      for(int j=0;j<n;j++)
        if(answers[j][i] == c)
        cnt += a[i];
      mx = max(cnt,mx);
    }
    ans += mx;
  }
    

  cout << ans << endl;


  return 0;
}