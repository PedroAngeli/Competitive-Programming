#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector <string> strs(n);
    for(int i=0;i<n;i++)
      cin >> strs[i];

    string ans = strs[0];
    bool flag = false;
    for(int i=0;i<m;i++){
      char cur = ans[i];
      for(char c = 'a';c<='z';c++){
        bool can = true;
        ans[i] = c;
        for(int k=0;k<n;k++){
          int cnt = 0;
          for(int j=0;j<m;j++){
            if(strs[k][j] != ans[j])
              cnt++;
          }
          if(cnt > 1){
            can = false;
            break;
          }
        }

        if(can){
          flag = true;
          cout << ans << endl;
          break;
        }
      }
      if(flag)
        break;
      ans[i] = cur;
    }
    if(!flag)
    cout << -1 << endl;
  }
 
  return 0;
}