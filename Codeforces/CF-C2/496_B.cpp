#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


string smallest(string s){
  int n = s.size();
  string ans = s;
  s += s;

  for(int i=0;i<n;i++){
    string cur = s.substr(i,n);
    if(cur < ans)
      ans = cur;
  }

  return ans;
}
int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  string s;
  cin >> n >> s;

  string ans = smallest(s);

  for(int i=1;i<=10;i++){
    for(int j=0;j<n;j++){
      if(s[j] == '9')
        s[j] = '0';
      else
        s[j]++;
    }

    string cur = smallest(s);
    
    if(cur < ans){
      ans = cur;
    }
  }

  cout << ans << endl;
  return 0;
}