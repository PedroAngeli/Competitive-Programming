#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;

  string s;
  cin >> s;

  bool remove = true;
  int ans = 0;
  
  while(remove){
    // cout << s << endl;
    remove = false;
    int idx;
    char c = '\0';

    if(s.size() > 1){
      for(int i=0;i<s.size();i++){
        if(i > 0){
          if(i == s.size() - 1){
            if(s[i]-1 == s[i-1]){
              remove = true;
                if(c < s[i]){
                  idx = i;
                  c = s[i];
                }
              }
          }else{
            if(s[i]-1 == s[i-1] || s[i]-1 == s[i+1]){
            remove = true;
            if(c < s[i]){
              idx = i;
              c = s[i];
            }
          }
          }
         
        }
        else{
          if(s[i]-1 == s[i+1]){
            remove = true;
            if(c < s[i]){
              idx = i;
              c = s[i];
            }
          }
        }
      }
    }
  
    if(remove){ 
      s.erase(s.begin() + idx);
      ans++;
    }

  }
  
  cout << ans << endl;
}