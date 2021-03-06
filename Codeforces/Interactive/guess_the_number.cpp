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
  
  int l = 1;
  int r = 1e6;
  int ans = 0;

  while(l <= r){
    int m = (l+r)/2;
    printf("%d\n", m);
    fflush(stdout);
    char line[3];
    scanf("%s", line);
    string response = line;
    if(response == ">=")
      l = m+1,ans = m;
    else
      r = m-1;
  }

  printf("! %d\n", ans);
  fflush(stdout);


  return 0;
}