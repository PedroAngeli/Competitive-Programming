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
    int n;
    cin >> n;
    vi a(n+1);
    int zeros = 0;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      if(a[i] == 0)
        zeros++;
    }
    if(zeros >= n/2){
      cout << zeros <<endl;
      for(int i=1;i<=zeros;i++)
        cout << 0 << " ";
      cout << endl;
    }else{
      int half = n/2;
      if(half % 2 == 1)
        half++;
        
      cout << half << endl;
      for(int i=1;i<=half;i++)
        cout << 1 << " ";
      cout <<endl;
    }
  }


  return 0;
}