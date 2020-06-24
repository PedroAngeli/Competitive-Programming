#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  // cin >> t;
  while(t--){
    long long k;
    cin >> k;

    int cnt[10];
    long long mult = 1;
    for(int i=0;i<10;i++)
      cnt[i] = 1;

    string ans = "codeforces";

    int idx = 0;
    while(mult < k){
      cnt[(idx)%10]++;
      mult = 1;
      for(int i=0;i<10;i++)
        mult *= cnt[i];
      idx++;
    }

    for(int i=0;i<10;i++)
      while(cnt[i]--)
        cout << ans[i];
    
    cout << endl;
  }
 
  
  return 0;
}