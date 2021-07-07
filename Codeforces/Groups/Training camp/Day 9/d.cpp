#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
string s;
int n;
const int nax = 1e6 + 5;
int lps[nax];

void solve(){
  int j = 0;
  int i = 1;
  int n = s.size();
  lps[0] = 0;

  while(i < n){
      if(s[i] == s[j]){
          lps[i] = j + 1;
          j++;
          i++;
      }else{
          if(j != 0){
              j = lps[j-1];
          }else{
              lps[i] = 0;
              i++;
          }
      }
  }
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> s;
  n = s.size();

  if(n <= 2){
    cout << "Just a legend" << endl;
    return 0;
  }

  solve();

  int mx = 0;
  for(int i=1;i<n-1;i++){
    if(lps[i] == lps[n-1]){
      mx = lps[i];
      break;
    }
  }

  if(mx == 0)
    mx = lps[lps[n-1]-1];
   
  if(mx == 0)
    cout << "Just a legend" << endl;
  else
    cout << s.substr(0,mx) << endl;

  return 0;
}