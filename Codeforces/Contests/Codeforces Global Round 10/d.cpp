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

int n;

int mod(int x){
  return (x%n + n)%n;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n;
    string a;
    cin >> a;
    set <char> conj;
    for(int i=0;i<n;i++)
      conj.insert(a[i]);
    if(conj.size() == 1){
      cout << (n+2)/3 << endl;
      continue;
    }
    int ans = 0;

    int j = -1;
    int cnt = 1;
    char cur = a[0];

    while(mod(j) != 0 && a[mod(j)] == cur){
      cnt++,j--;
    }

    j = mod(j) + 1;
    int i = 1;
    
    while(i < j){
      while(i < j && a[i] == cur)
        cnt++,i++;
      ans += cnt/3;
      cnt = 0;
      cur = a[i];
    }

    ans += cnt/3;


    cout << ans << endl;
  }

  return 0;
}