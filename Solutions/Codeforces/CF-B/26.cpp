#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();
  stack <int> p;
  int ans = 0;
  int cnt = 0;
  for(int i =0;i<n;i++){
    char cur = s[i];
    if(cur == '('){
      p.push(cur);
    }else if(!p.empty()){
      p.pop();
      ans++;
    }
 
  }


  cout << ans*2 << endl;
  
  return 0;
}