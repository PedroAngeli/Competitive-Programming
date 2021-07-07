#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;


  int cnt = 0;

  for(int i=0;i<n-p;i++){
    if((s[i] == '1' || s[i] == '0') && s[i] == s[i+p])
      cnt++;
  }

  if(cnt == n-p){
    cout << "No" << endl;
    return 0;
  }

  for(int i=0;i<n;i++){
    if(s[i] == '.'){
      if(i-p>=0){
        if(s[i] == s[i-p]){
          s[i] = '1';
          s[i-p] = '0';
        }else
          s[i] = '1'-s[i-p]+'0';
      break;
        
      }else if(i+p < n){
        if(s[i] == s[i+p]){
          s[i] = '1';
          s[i+p] = '0';
        }else{
          s[i] = '1'-s[i+p]+'0';
        }
      break;
      }
    }
  }

  for(int i=0;i<n;i++)
    if(s[i] == '.')
      s[i] = '1';
  
  cout << s << endl;
  
  return 0;
}