#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

  string str;
  cin >> str;
  
  int cnt = 0;
  int ans = 0;

  for(char c:str){
    if(c == 'R')
      cnt++;
    else{
      ans = max(ans,cnt);
      cnt = 0;
    }
  }
      ans = max(ans,cnt);

  cout << ans << endl;

  
  return 0;
}