#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;

    for(int i=0;i<n/2;i++){
      char l = s[i];
      char r = s[n-i-1];
      if(l == r || abs(l-r) == 2)
        cnt++;
    }

    if(cnt == n/2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
    
  return 0;
}