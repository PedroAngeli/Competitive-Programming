#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n,k;
    string s;
    cin >> n >> k >> s;
    bool one = false;
    int len = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
      if(s[i] == '0')
        len++;
      else{
        if(!one){
          one = true;
          len = len - k;
          if(len > 0)
            ans += 1 + (len-1)/(k+1);
        }else{
          len = len - 2*k;
          if(len > 0)
            ans += 1 + (len-1)/(k+1);
        }
        len = 0;
      }
    }
    if(len){
        if(one){
        len = len - k;
        if(len > 0){
           ans += 1 + (len-1)/(k+1);
        }
      }else{
        ans += 1 + (len-1)/(k+1);
 
      }
    }
    

    cout << ans << endl;
  }

  return 0;
}